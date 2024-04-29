//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#ifndef COREABM_HYPHALBRANCH_H
#define COREABM_HYPHALBRANCH_H

#include "core/simulation/cells/cellparts/AssociatedCellparts.h"
#include "core/basic/Coordinate3D.h"
#include "core/simulation/morphology/SphericalMorphology.h"
#include "apps/alveolus/environment/Surface.h"
#include "apps/alveolus/io_utils_alveolus.h"

enum class EvasionState {
    NORMAL,
    GO_UP,
    GO_DOWN,
    GO_STRAIGHT
};

class HyphalBranch : public AssociatedCellparts {
public:
    HyphalBranch(Cell *mothercell, const std::shared_ptr<Coordinate3D>& connection_point, int depth, Coordinate3D growth_vector);

    void grow(double timestep, double current_time);

    int getId() { return id_; }

private:
    void set_parameters();
    void set_collision_threshold();
    void update_growth_vector();
    double add_branch_length_change(double timestep);

    Surface surface_;
    int id_{};
    int depth_{};
    double step_length_{};
    double radius_{};
    bool growing_{};
    double branch_length_{};
    double new_dirction_threshold_{};
    double next_sphere_threshold_{};
    double next_branch_threshold_{};

    std::shared_ptr<Coordinate3D> hyphal_tip_{};
    Coordinate3D growth_vector_{};
    Coordinate3D growth_vector_90_deg_{};
    Coordinate3D evasion_growth_vector_{};
    std::pair<double, double> growth_weights_{};
    std::vector<std::unique_ptr<HyphalBranch>> hyphal_branches_{};
    abm::utilAlveolus::curveParameters cp{};
    abm::utilAlveolus::branchParameters bp{};
    abm::utilAlveolus::growthParameter gp{};

    EvasionState eState = EvasionState::NORMAL;
    int evasion_tries{};
    std::vector<Coordinate3D> collisions{};
    int collision_threshold{};
};


#endif //COREABM_HYPHALBRANCH_H
