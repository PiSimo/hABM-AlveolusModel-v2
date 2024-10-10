//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#include "ParticleManager.h"
#include "apps/alveolus/cells/FungalCellAlveolus.h"
#include "core/simulation/neighbourhood/BalloonListNHLocator.h"
#include "external/json.hpp"
#include <algorithm>
#include <chrono>
#include <fstream>

using json = nlohmann::json;

ParticleManager::ParticleManager(abm::utilAlveolus::ParticleManagerParameters parameters, Site *site){
    site_ = dynamic_cast<AlveoleSite*>(site);
    dc_ = parameters.diffusion_constant;
    s_aec_ = parameters.molecule_secretion_per_cell;
    visualize_concentration_ = parameters.visualize_concentration;
    start_chemotaxis_ = parameters.start_secrection;
    number_aecs_ = site_->getAECT1().size() + site_->getAECT2().size();
    sum_area_aec_particles_cells_.resize(number_aecs_, 0.0);
    aec_secretion_rate_per_grid_.resize(number_aecs_, 0.0);
    auto nhl = dynamic_cast<BalloonListNHLocator*>(site_->getNeighbourhoodLocator()); //nhl->getGridConstant()
    particle_balloon_list_ = std::make_unique<StaticBalloonList>(nhl->getGridConstant(), site_->getLowerLimits(), site_->getUpperLimits());
    initializeParticles(parameters.particle_delauney_input_file);
}

void ParticleManager::initializeParticles(std::string filename) {
    std::ifstream infile(filename);
    json j;
    infile >> j;

    int supposed_id = 0;
    if (s_aec_ > 0) {
        for (const auto &particle_json: j["Particles"]) {
            int id = particle_json["id"];
            auto pos = particle_json["position"].get<std::vector<double>>();
            Coordinate3D position{pos[0], pos[1], pos[2]};
            double area = particle_json["area"];
            all_particles_.emplace_back(std::make_shared<Particle>(id, position, area, site_));
            particle_balloon_list_->addCoordinateWithId(position, id);

            if (id != supposed_id) {
                ERROR_STDERR("Particles are not in order at id = " + std::to_string(supposed_id));
            }
            ++supposed_id;
        }

        for (const auto &particle_json: j["Particles"]) {
            auto p = all_particles_[particle_json["id"]];
            for (const auto &neighbour: particle_json["neighbours"]) {
                auto pn = all_particles_[neighbour["id"]];
                double contact_area = neighbour["contact_area"];
                p->addNeighbour(pn.get(), contact_area, dc_);
            }
        }
        infile.close();

        // assign aec cells to particles, associated_type2_aec_ == -1, not associated with any aec2
        for (auto &p: all_particles_) {
            auto min_dist = std::numeric_limits<double>::max();
            for (auto &aec: site_->getAECT1()) {
                auto distance = (p->getPosition() - aec->position).getMagnitude();
                if (distance < min_dist) {
                    p->associated_type1_aec_ = aec->id;
                    min_dist = distance;
                }
            }
            for (auto &aec2: site_->getAECT2()) {
                auto sph_aec = abm::util::toSphericCoordinates(aec2->position);
                auto sph_p = abm::util::toSphericCoordinates(p->getPosition());
                double arcOfIntervalTheta = 0.5 * site_->getLengthAEC2() / (site_->getRadius());

                if ((sph_p.theta <= sph_aec.theta + arcOfIntervalTheta) &&
                    (sph_p.theta >= sph_aec.theta - arcOfIntervalTheta)) {
                    auto distance = sph_aec.calculateEuclidianDistance(sph_p);
                    auto dmax = sqrt(site_->getLengthAEC2() * site_->getLengthAEC2() / 4.0
                                     + (sph_p.theta - sph_aec.theta) * (sph_p.theta - sph_aec.theta) *
                                       site_->getRadius() * site_->getRadius());
                    if (distance < dmax) {
                        p->associated_type2_aec_ = aec2->id;
                    }
                }
            }
        }

        computeMaxPossibleTimestep();

        if (visualize_concentration_) extractTriangles();
    }
}

void ParticleManager::computeMaxPossibleTimestep() {
    double min_timestep = std::numeric_limits<double>::max();
    double timestep{};

    for (auto particle: all_particles_){
        timestep = particle->estimateLowestTimestep(dc_);
        if (timestep < min_timestep)
            min_timestep = timestep;
    }
    INFO_STDOUT("Maximum possible timestep with regard to stability of diffusion: " + std::to_string(min_timestep));
}

void ParticleManager::extractTriangles() {
    std::vector<std::vector<unsigned int>> triangle_candidates;

    for (auto& particle : all_particles_) {
        unsigned int id_p = particle->getId();
        const auto& neighbours = particle->particle_neighbourlist_->getNeighbours();
        for (size_t i = 0; i < neighbours.size(); ++i) {
            unsigned int id_i = neighbours[i]->getId();
            for (size_t j = i + 1; j < neighbours.size(); ++j) {
                unsigned int id_j = neighbours[j]->getId();
                const auto& i_neighbours = all_particles_[id_i]->particle_neighbourlist_->getNeighbours();
                if (std::find(i_neighbours.begin(), i_neighbours.end(), neighbours[j]) != i_neighbours.end()) {
                    std::vector<unsigned int> sorted{id_p, id_i, id_j};
                    std::sort(sorted.begin(), sorted.end());
                    triangle_candidates.emplace_back(sorted);
                }
            }
        }
    }

    std::sort(triangle_candidates.begin(), triangle_candidates.end(), abm::util::compareTriple);
    triangle_candidates.erase(std::unique(triangle_candidates.begin(), triangle_candidates.end()), triangle_candidates.end());

    for (const auto& sorted: triangle_candidates) {
        TRIANGLE3D newTriangle{};
        newTriangle.outside = !all_particles_[sorted[0]]->getIsInSite() and !all_particles_[sorted[1]]->getIsInSite() and !all_particles_[sorted[2]]->getIsInSite();
        newTriangle.neighbourIds[0] = sorted[0], newTriangle.neighbourIds[1] = sorted[1], newTriangle.neighbourIds[2] = sorted[2];
        triangles_.emplace_back(newTriangle);
    }

}

void ParticleManager::inputOfParticles(double time_delta, double current_time) {
    if (clean_chemotaxis_ && !site_->getLargeTimestepActive()) {
        DEBUG_STDOUT("Start chemotaxis cleanup");
        clean_chemotaxis_ = false;
        cleanUpAllParticles();
    }
    insertConcentrationAtArea(time_delta, current_time);
}

void ParticleManager::cleanUpAllParticles() {
    aec_particles_.clear();
}

void ParticleManager::insertConcentrationAtArea(double time_delta, double current_time) {
    if (aec_particles_.empty() && s_aec_ > 0) {
        aec_particles_cells_.clear();
        std::fill(sum_area_aec_particles_cells_.begin(), sum_area_aec_particles_cells_.end(), 0.0);
        std::fill(aec_secretion_rate_per_grid_.begin(), aec_secretion_rate_per_grid_.end(), 0.0);

        std::vector<Agent *> all_fungal_cell = site_->getAgentManager()->getAllFungalCells();

        int jump_over_spheres = 3;
        for (auto fungal_cell: all_fungal_cell) {
            auto cell_state = fungal_cell->getCurrentCellState()->getStateName();

            bool start_secreting = (current_time > start_chemotaxis_) && !abm::util::isSubstring(cell_state, "FungalOnAEC");

            if (!fungal_cell->isDeleted() && dynamic_cast<FungalCellAlveolus*>(fungal_cell)->isActive() && start_secreting){
                for (size_t i=0; i<fungal_cell->getSurface()->getAllSpheresOfThis().size(); i = i + jump_over_spheres) {
                    auto cell_sphere = fungal_cell->getSurface()->getAllSpheresOfThis()[i];
                    auto connected_aec = site_->overAECT1(abm::util::toSphericCoordinates(cell_sphere->getPosition()));
                    bool is_over_aec1 = connected_aec.first;
                    int obstacle_aec_id = connected_aec.second;
                    std::vector<unsigned int> potential_aec_particles;
                    bool aec_is_alive = true;
                    if (is_over_aec1) {
                        particle_balloon_list_->setThreshold(site_->getRadiusAEC1());
                        aec_is_alive = site_->getAECT1()[obstacle_aec_id]->alive;
                    } else {
                        particle_balloon_list_->setThreshold(site_->getLengthAEC2() * sqrt(2.0)/2.0);
                        aec_is_alive = site_->getAECT2()[obstacle_aec_id - site_->getAECT1().size()]->alive;
                    }
                    particle_balloon_list_->getInteractions(cell_sphere->getPosition(), potential_aec_particles);

                    for (auto index: potential_aec_particles) {
                        auto p = all_particles_[index];
                        if (site_->containsPosition(p->getPosition())) {
                        auto associated_aec = p->associated_type2_aec_ < 0 ? p->associated_type1_aec_ : p->associated_type2_aec_;
                        if (associated_aec == obstacle_aec_id and aec_is_alive) {
                                if (std::find(aec_particles_.begin(), aec_particles_.end(), p) ==
                                    aec_particles_.end()) {
                                    aec_particles_cells_.push_back(obstacle_aec_id);
                                    sum_area_aec_particles_cells_[obstacle_aec_id] += p->getArea();
                                    aec_particles_.push_back(p);
                                }
                            }
                        }
                    }
                }
            }
        }

        for (int i = 0; i < number_aecs_; i++) {
            if (sum_area_aec_particles_cells_[i] > 0) {
                DEBUG_STDOUT("Cell " << i << " with an area of " << sum_area_aec_particles_cells_[i]);
                double secretion_rate = (s_aec_ /  sum_area_aec_particles_cells_[i]) * time_delta;
                aec_secretion_rate_per_grid_[i] = secretion_rate;
                DEBUG_STDOUT("The cell gets an per-grid secretion rate of " + std::to_string(secretion_rate));
            }
        }
    }

    for (size_t i = 0; i < aec_particles_.size(); i++) {
        int particle_cell = aec_particles_cells_[i];
        aec_particles_[i]->addConcentrationChange(aec_secretion_rate_per_grid_[particle_cell]);
    }

}

bool ParticleManager::steadyStateReached(double current_time) {
    bool stStReached = false;
    if (dc_ > 500) { //below 500, reaching a steady state takes too much time
        // all values below were found experimentally
        if (dc_ == 600) {
            stStReached =
                    (current_time - site_->getAgentManager()->getLastFungalCellChange() > 35.0);
            allow_higher_dt_ = stStReached;
        } else if (dc_ == 2000) {
            stStReached =
                    (current_time - site_->getAgentManager()->getLastFungalCellChange() > 13.0);
            allow_higher_dt_ = stStReached;
        } else if (dc_ == 6000) {
            stStReached =
                    (current_time - site_->getAgentManager()->getLastFungalCellChange() > 5.0);
            allow_higher_dt_ = stStReached;
        } else if (dc_ == 15000) {
            stStReached =
                    (current_time - site_->getAgentManager()->getLastFungalCellChange() > 2.2);
            allow_higher_dt_ = stStReached;
        } else if (dc_ == 35000) {
            stStReached =
                    (current_time - site_->getAgentManager()->getLastFungalCellChange() > 1.0);
            allow_higher_dt_ = stStReached;
        } else {
            double limit = 30000.0/dc_; // 30000.0/DC proved to be a valid value until steady state is reached for high DC
            stStReached = (current_time - site_->getAgentManager()->getLastFungalCellChange() > limit);
            allow_higher_dt_ = stStReached;
        }
    }
    return stStReached;
}
