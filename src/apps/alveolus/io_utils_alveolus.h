//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#ifndef CORE_UTILS_IO_UTIL_Alveolus_H
#define CORE_UTILS_IO_UTIL_Alveolus_H

#include <iostream>
#include <string>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <array>
#include <type_traits>

#include <boost/filesystem.hpp>

#include "core/basic/Coordinate3D.h"
#include "core/utils/io_util.h"

namespace abm::utilAlveolus {

    // To create your own parameters, you have to define them here and let them inherit from the base parameter structs
    // In the Site (here: AlveoleSite) you must read in abm::utilAlveolus::getSim.. instead of abm::util:getSim..
    // The parameter are set in the in io_util_alveolus.cpp

    struct curveParameters {
        double angle_mean;
        double next_curve_mean;
    };

    struct branchParameters {
        double angle_mean;
        double next_branch_mean;
        double depth_dependency;
    };

    struct growthParameter {
        double k1;
        double k2;
        double sat_length;
    };

    struct FungalParametersAlveolus : abm::util::SimulationParameters::FungalParameters {
        bool hyphal_growth{};
        double next_hyphae_rate{};
        curveParameters cp{};
        branchParameters bp{};
        growthParameter gp{};
    };

    struct ImmuneCellParametersAlveolus : abm::util::SimulationParameters::ImmuneCellParameters {

    };

    struct ImmuneCellMacrophage : ImmuneCellParametersAlveolus {
        double k_r{};
        double k_i{};
        double k_blr{};
    };

    struct ParticleManagerParameters {
        double diffusion_constant{};
        double molecule_secretion_per_cell{};
        double start_secrection{};
        bool visualize_concentration{};
        std::string particle_delauney_input_file{};
    };

    struct AlveolusSiteParameter : abm::util::SimulationParameters::SiteParameters {
        int organism{};
        int objects_per_row{};
        int number_of_pok{};
        int number_of_aec2{};
        double site_radius{};
        double theta_lower_bound{};
        double surfactant_thickness{};
        double thickness_of_border{};
        double radius_pores_of_kohn{};
        double radius_alv_epith_type_one{};
        double length_alv_epth_type_two{};
        ParticleManagerParameters particle_manager_parameters{};
        Coordinate3D site_center{};
    };

    abm::util::SimulationParameters getSimulationParameters(const std::string &simulator_config);

}

#endif //CORE_UTILS_IO_UTILS_Alveolus_H
