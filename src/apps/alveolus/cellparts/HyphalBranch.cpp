//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#include "HyphalBranch.h"
#include "apps/alveolus/cells/FungalCellAlveolus.h"
#include "apps/alveolus/AlveoleSite.h"

HyphalBranch::HyphalBranch(Cell *mothercell, const std::shared_ptr<Coordinate3D> &connection_point, int depth, Coordinate3D growth_vector)
        : AssociatedCellparts(mothercell, connection_point), hyphal_tip_(connection_point), depth_(depth + 1), growth_vector_(growth_vector) {

    surface_ = static_cast<AlveoleSite*>(mothercell->getSite())->getEnvSurface();
    set_parameters();
    if (depth_ == 1) {
        growth_weights_ = abm::util::getRandom2Direction(mothercell->getSite()->getRandomGenerator());
    } else {
        growth_weights_ = abm::util::getRandom2Direction(mothercell->getSite()->getRandomGenerator(), bp.angle_mean, 0);
    }
    update_growth_vector();
}

void HyphalBranch::set_parameters() {
    id_ = static_cast<FungalCellAlveolus*>(mothercell)->getNumberOfBranches();
    static_cast<FungalCellAlveolus*>(mothercell)->increaseNumberOfBranches();
    DEBUG_STDOUT("Create new branch with id=" << id_);

    growing_ = true;
    radius_ = mothercell->getSurface()->getBasicSphereOfThis()->getRadius() * 0.5;
    step_length_ = radius_ * 0.95;
    set_collision_threshold();
    next_sphere_threshold_ = 0.0;

    auto hg_paras = static_cast<FungalCellAlveolus*>(mothercell)->getFungalParameter();

    // Curvature
    cp.next_curve_mean = 1.0; //hg_paras->cp.next_curve_mean;
    cp.angle_mean = 0.06; //hg_paras->cp.angle_mean;
    new_dirction_threshold_ = cp.next_curve_mean;

    // Branching
    bp.depth_dependency = 10.0; //hg_paras->bp.depth_dependency;
    bp.next_branch_mean = 50.0; //hg_paras->bp.next_branch_mean + bp.depth_dependency * (depth_ - 1);
    bp.angle_mean = 1.3; //hg_paras->bp.angle_mean;
    next_branch_threshold_ = bp.next_branch_mean;

    // Growth
    branch_length_ = 0.0;
    gp.k1 = 2.0 / (depth_ * depth_); //hg_paras->gp.k1/(depth_*depth_);
    gp.k2 = 1.5 / (depth_ * depth_); //hg_paras->gp.k2/(depth_*depth_);
    gp.sat_length = 10.0; //hg_paras->gp.sat_length;
}

void HyphalBranch::update_growth_vector() {
    // Function to calculate the direction vector in cartesian coordinates on sphere
    surface_ = static_cast<AlveoleSite*>(mothercell->getSite())->getEnvSurface();
//    auto csite_grad = csite_surface.surfaceGradient(*hyphal_tip_);

    if (eState == EvasionState::NORMAL) {

        hyphal_tip_ = std::make_shared<Coordinate3D>(surface_.surfacePoint(*hyphal_tip_));

        if (growth_vector_.getMagnitude() == 0.0) {
            auto uvecs = surface_.perpendicularVectors(*hyphal_tip_);
            growth_vector_ = uvecs.first * growth_weights_.first + uvecs.second * growth_weights_.second;
            growth_vector_ *= step_length_ / growth_vector_.getMagnitude();
        } else {
            growth_vector_90_deg_ = surface_.perpendicularVector(*hyphal_tip_, growth_vector_);
            growth_vector_90_deg_ *= step_length_ / growth_vector_90_deg_.getMagnitude();
            growth_vector_ = surface_.perpendicularVector(*hyphal_tip_, growth_vector_90_deg_ * (-1));
            growth_vector_ *= step_length_ / growth_vector_.getMagnitude();
            Coordinate3D newVec =
                    growth_vector_ * growth_weights_.first + growth_vector_90_deg_ * growth_weights_.second;
            newVec *= step_length_ / newVec.getMagnitude();
            growth_vector_ = newVec;
        }
    } else {
        growth_vector_ = evasion_growth_vector_;
    }

    growth_weights_ = {1.0, 0.0};
}

void HyphalBranch::set_collision_threshold() {
    // Each sphere has always collisions since they are forming the hyphae
    // To detect collisions we set the collision_threshold depending on the ratio step_length/radius
    collision_threshold = step_length_ / radius_ <= 1/2 ? 4 : 3;
    collision_threshold = step_length_ / radius_ > 1.5 ? 2 : collision_threshold;
}

double HyphalBranch::add_branch_length_change(double timestep){
    return (gp.k1/depth_ + gp.k2 * (branch_length_ / (gp.sat_length + branch_length_))) * timestep;
}

void HyphalBranch::grow(double timestep, double current_time) {
    if (growing_) {

        branch_length_ += add_branch_length_change(timestep);

        // Calculate new direction for HyphalBranch
        if (branch_length_ > new_dirction_threshold_) {
            growth_weights_ = abm::util::getRandom2Direction(mothercell->getSite()->getRandomGenerator(), cp.angle_mean, 0);
            update_growth_vector();
            new_dirction_threshold_ += mothercell->getSite()->getRandomGenerator()->generateNormalDistributedValue(cp.next_curve_mean, 0);
        }

        for (; branch_length_ > next_sphere_threshold_ + step_length_; next_sphere_threshold_ += step_length_) {
            auto new_sphere_pos = std::make_shared<Coordinate3D>();
            *new_sphere_pos = *hyphal_tip_ + growth_vector_;
            update_growth_vector();
            auto new_rad = abm::util::toSphericCoordinates(*new_sphere_pos).r;

            if (mothercell->getSite()->containsPosition(*new_sphere_pos) && new_rad < mothercell->getSite()->getRadius() * 1.05 && new_rad > mothercell->getSite()->getRadius() * 0.95)  {
                auto add_sphere = true;
                auto new_sphere = std::make_unique<SphericalMorphology>(mothercell->getSurface(), new_sphere_pos, radius_, std::to_string(id_), current_time);
                auto new_sphere_rep = new_sphere->getSphereRepresentation().front();

                // Evasion only if it has outgrown its motherbranch
                if (branch_length_ > 5 * radius_) {
                    collisions = mothercell->getSite()->getNeighbourhoodLocator()->getCollisionSpheres(new_sphere_rep.get(), growth_vector_);

                    // based on how many collisions a sphere has, we decide if it is hitting a different branch
                    // depends on distance between spheres in the hyphae
                    if (collisions.size() > collision_threshold) {
                        add_sphere = false;
                        evasion_growth_vector_ = growth_vector_;

                        if (eState == EvasionState::NORMAL) {
                            eState = EvasionState::GO_UP;
                        } else if (eState == EvasionState::GO_DOWN) {
                            eState = EvasionState::GO_STRAIGHT;
                            if (evasion_tries > 1) {
                                eState = EvasionState::GO_UP;
                            }
                        } else if (eState == EvasionState::GO_STRAIGHT) {
                            if (evasion_tries > 1) {
                                eState = EvasionState::GO_UP;
                            }
                        }
                        mothercell->getSite()->getNeighbourhoodLocator()->removeSphereRepresentation(new_sphere_rep.get());
                        next_sphere_threshold_ -= step_length_;
                        evasion_tries += 1;
                        if (evasion_tries > 9) { // after 9 evasion tries, it stops growing here
                            growing_ = false;
                            next_sphere_threshold_ += step_length_;
                        }

                    } else {
                        if (eState == EvasionState::GO_DOWN) {
                            surface_ = static_cast<AlveoleSite*>(mothercell->getSite())->getEnvSurface();
                            auto current_position = new_sphere_rep->getPosition();
                            auto distance_to_z_level = current_position.z - surface_.surfacePoint(current_position).z;
                            if (distance_to_z_level <= 0.0) {
                                add_sphere = false;
                                mothercell->getSite()->getNeighbourhoodLocator()->removeSphereRepresentation(new_sphere_rep.get());
                                eState = EvasionState::NORMAL;
                                update_growth_vector();
                                evasion_tries = 0;
                            }
                        } else if (eState == EvasionState::GO_STRAIGHT) {
                            eState = EvasionState::GO_DOWN;
                            evasion_tries = 0;
                        } else if (eState == EvasionState::GO_UP) {
                            eState = EvasionState::GO_STRAIGHT;
                            evasion_tries = 0;
                        }
                    }
                }

                if (eState != EvasionState::NORMAL) { // collision is taking place
                    double factor = 0.5; // factor of evasion steepness (the higher the value, the steeper)
                    if (eState == EvasionState::GO_UP) { // go up
                        auto evasion_vec = evasion_growth_vector_ - surface_.surfaceGradient(*hyphal_tip_) * factor;
                        evasion_vec *= step_length_/evasion_vec.getMagnitude();
                        evasion_growth_vector_ = evasion_vec;
                    } else if (eState == EvasionState::GO_DOWN) { // go down
                        auto evasion_vec = evasion_growth_vector_ + surface_.surfaceGradient(*hyphal_tip_) * factor;
                        evasion_vec *= step_length_/evasion_vec.getMagnitude();
                        evasion_growth_vector_ = evasion_vec;
                    } else if (eState == EvasionState::GO_STRAIGHT) { // go straight
                        evasion_growth_vector_ = growth_vector_;
                    }
                }

                if (add_sphere) {
                    hyphal_tip_ = new_sphere_pos;
                    update_growth_vector();
                    mothercell->getSurface()->appendAssociatedCellpart(std::move(new_sphere));
                }
            } else {
                growing_ = false;
                DEBUG_STDOUT("Stop growth, reached end of site");
            }
        }

        if (branch_length_ > next_branch_threshold_) {
            auto new_branch = std::make_unique<HyphalBranch>(mothercell, hyphal_tip_, depth_, growth_vector_);
            hyphal_branches_.push_back(std::move(new_branch));
            next_branch_threshold_ += mothercell->getSite()->getRandomGenerator()->generateNormalDistributedValue(bp.next_branch_mean, 0);;
        }

    }

    for (auto &branch: hyphal_branches_) {
        branch->grow(timestep, current_time);
    }
}
