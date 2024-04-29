//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#include <optional>
#include <random>

#include "io_utils_alveolus.h"
#include "external/json.hpp"
#include "core/utils/macros.h"

using json = nlohmann::json;

abm::util::SimulationParameters abm::utilAlveolus::getSimulationParameters(const std::string &simulator_config){
    // Load parameters with base abm::utils
    auto simp = abm::util::getSimulationParameters(simulator_config);

    // Load file again to load alveolus specific parameters
    std::ifstream json_file(simulator_config);
    json json_parameters;
    json_file >> json_parameters;

    // write alveolus specific parameters into program
    for (auto&site: json_parameters["Agent-Based-Framework"]["Sites"]) {
        // Load Alveolus parameters
        auto &sitep = simp.site_parameters;
        auto as_para = AlveolusSiteParameter{*sitep};
        as_para.organism = site["AlveoleSite"]["organism"];
        as_para.objects_per_row = site["AlveoleSite"]["objects_per_row"];
        as_para.number_of_pok = site["AlveoleSite"]["number_of_pok"];
        as_para.number_of_aec2 = site["AlveoleSite"]["number_of_aec2"];
        as_para.site_radius = site["AlveoleSite"]["site_radius"];
        as_para.theta_lower_bound = site["AlveoleSite"]["theta_lower_bound"];
        as_para.surfactant_thickness = site["AlveoleSite"]["surfactant_thickness"];
        as_para.thickness_of_border = site["AlveoleSite"]["thickness_of_border"];
        as_para.radius_pores_of_kohn = site["AlveoleSite"]["radius_pores_of_kohn"];
        as_para.radius_alv_epith_type_one = site["AlveoleSite"]["radius_alv_epith_type_one"];
        as_para.length_alv_epth_type_two = site["AlveoleSite"]["length_alv_epth_type_two"];
        as_para.site_center = {site["AlveoleSite"]["site_center"][0], site["AlveoleSite"]["site_center"][1],
                               site["AlveoleSite"]["site_center"][2]};

        if (auto particles = site.find("Particles"); particles != site.end()) {
            as_para.particle_manager_parameters.diffusion_constant = particles->value("diffusion_constant", 0.0);
            as_para.particle_manager_parameters.molecule_secretion_per_cell = particles->value(
                    "molecule_secretion_per_cell", 0.0);
            as_para.particle_manager_parameters.particle_delauney_input_file = particles->value(
                    "particle_delauney_input_file", "");
            as_para.particle_manager_parameters.start_secrection = particles->value("start_secretion", -1.0);
            as_para.particle_manager_parameters.visualize_concentration = particles->value("visualize_concentration", false);
        }

        sitep = std::make_unique<AlveolusSiteParameter>(as_para);

    }

    for (auto &agent: simp.site_parameters->agent_manager_parameters.agents) {
        for (const auto &site: json_parameters["Agent-Based-Framework"]["Sites"]) {
            auto agent_type_ = "FungalCellAlveolus";
            if (agent->type == agent_type_) {
                auto agent_ = site["AgentManager"]["Agents"].at(std::string(agent_type_));

                auto fge = FungalParametersAlveolus{*agent};
                fge.hyphal_growth = agent_["hyphal_growth"].value("activated", true);
//                fge.other_alveolus_parameter = agent_.value("some_para", 1.0);
                agent = std::make_shared<FungalParametersAlveolus>(fge);
            }

            agent_type_ = "ImmuneCellMacrophage";
            if (agent->type == agent_type_) {
                auto agent_ = site["AgentManager"]["Agents"].at(std::string(agent_type_));
                auto ma_parameters = ImmuneCellMacrophage{*agent};
                ma_parameters.k_r = agent_.value("k_r", 0.0);
                ma_parameters.k_i = agent_.value("k_i", 0.0);
                ma_parameters.k_blr = agent_.value("k_blr", 0.0);
                ma_parameters.input_distribution_path = agent_.value("input_distribution_path", "");
                if (agent_["Movement"]["type"] == "BiasedPersistentRandomWalk"){
                    ma_parameters.movement_parameters.persistence_time = agent_["Movement"].value("persistence_time", 0.0);
                    ma_parameters.movement_parameters.mean = agent_["Movement"]["speed"].value("mean", 0.0);
                    ma_parameters.movement_parameters.stddev = agent_["Movement"]["speed"].value("stddev",0.0);
                }
                agent = std::make_shared<ImmuneCellMacrophage>(ma_parameters);
            }

        }
    }

    return std::move(simp);
};

