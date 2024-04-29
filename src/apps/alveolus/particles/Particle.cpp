//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#include "Particle.h"

Particle::Particle(int id, Coordinate3D position, double area, Site *site) {
    id_ = id;
    position_ = position;
    double rad = abm::util::toSphericCoordinates(position).r;
    area_ = area;
    concentration_ = 0.0;
    is_in_site_ = site->containsPosition(position) && site->getRadius() < rad * 1.05 && site->getRadius() > rad * 0.95;
    associated_type1_aec_ = -1;
    associated_type2_aec_ = -1;
    particle_neighbourlist_ = std::make_unique<ParticleNeighbourList>(this);
}

void Particle::addNeighbour(Particle *p, double contact_area, double dc) {
    particle_neighbourlist_->addNeighbour(p, contact_area, dc);
}

double Particle::estimateLowestTimestep(double dc) {
    auto neighbour_particles = particle_neighbourlist_->getNeighbours();
    auto distances = particle_neighbourlist_->getDistances();
    auto contact_areas = particle_neighbourlist_->getContactAreas();

    double sum = 0;
    for (size_t i = 0; i < distances.size(); i++) {
        sum += (dc * contact_areas[i]) / (distances[i] * area_);
    }

    return 1.0 / sum;
}

void Particle::doDiffusion(double timestep) {
    if (is_in_site_) { //only "in site" grid points are used for the calculations
        double current_own_prefactor = 0.0, conc_change_diffusion = 0.0;
        for (size_t i=0; i < particle_neighbourlist_->getNeighbours().size(); ++i) {
            auto neighbour_particle = particle_neighbourlist_->getNeighbours()[i];
            auto neighbour_particle_prefactor_pse = particle_neighbourlist_->getPreFactorsPSE()[i];
            conc_change_diffusion += neighbour_particle->getConcentration() * neighbour_particle_prefactor_pse;
            current_own_prefactor += neighbour_particle_prefactor_pse;
        }
        conc_change_diffusion -= concentration_ * current_own_prefactor;
        conc_change_diffusion *= timestep;

        addConcentrationChange(conc_change_diffusion);
    }
}

void Particle::addConcentrationChange(double conc_change_diffusion) {
    conc_change_in_current_timestep_ += conc_change_diffusion;
}

void Particle::applyConcentrationChange(double timestep) {
    if (is_in_site_) { //only "in site" grid points are used for the calculations
        concentration_ += conc_change_in_current_timestep_;
        conc_change_in_current_timestep_ = 0;
    }
}

Coordinate3D Particle::getGradient() {
    Coordinate3D gradient = Coordinate3D();
    if (is_in_site_) { //only "in site" grid points are used for the calculations
        std::vector<Particle *> neighbours = particle_neighbourlist_->getNeighbours();
        std::vector<double> preFactorsGradient = particle_neighbourlist_->getPreFactorsGradient();
        std::vector<Particle *>::iterator it = neighbours.begin();
        unsigned int index = 0;
        while (it != neighbours.end()) {

            //Sukumar et al.
            Coordinate3D curGradient{(*it)->getPosition() - position_};
            curGradient *= 0.5 * preFactorsGradient[index] * ((*it)->getConcentration() - concentration_);
            it++;
            index++;
            gradient += curGradient;
        }
    }

    return gradient;
}

double Particle::getGradientStrength() {
    Coordinate3D gradient = Coordinate3D();
    if (is_in_site_) {
        std::vector<Particle *> neighbours = particle_neighbourlist_->getNeighbours();
        std::vector<double> preFactorsGradient = particle_neighbourlist_->getPreFactorsGradient();

        std::vector<Particle *>::iterator it = neighbours.begin();
        unsigned int index = 0;
        while (it != neighbours.end()) {

            //Sukumar et al.
            Coordinate3D curGradient{(*it)->getPosition() - position_};
            curGradient *= 0.5 * preFactorsGradient[index] * ((*it)->getConcentration() - concentration_);
            it++;
            index++;
            gradient += curGradient;
        }
    }

    return gradient.getMagnitude();
}



