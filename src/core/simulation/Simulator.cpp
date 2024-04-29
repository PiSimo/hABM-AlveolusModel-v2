//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#include <chrono>
#include <omp.h>
#include <string>

#include "core/simulation/AgentManager.h"
#include "core/simulation/Simulator.h"
#include "core/simulation/Site.h"
#include "core/simulation/factories/InteractionFactory.h"
#include "core/simulation/site/CuboidSite.h"
#include "core/utils/macros.h"
#include "core/utils/misc_util.h"
#include "core/utils/time_util.h"
#include "core/visualisation/Visualizer.h"


Simulator::Simulator(std::string config_path, std::unordered_map<std::string, std::string> cmd_input_args)
    : config_path_(config_path), cmd_input_args_(cmd_input_args) {
}

void Simulator::executeRuns(int runs, int seed, const std::string& output_dir, const std::string& input_dir, int sim,
                            const std::string& parameter_string) const {

    // Initializes the seed for the current parameter configuration
    // Take system seed from command line IF provided
    seed = cmd_input_args_.find("seed") != cmd_input_args_.end() ? std::stoi(cmd_input_args_.find("seed")->second) : seed;
    SYSTEM_STDOUT("System Seed: " << seed);
    int const current_sim_seed = seed + runs * sim;
    SYSTEM_STDOUT("Current Simulation Seed: " << current_sim_seed);
    if (!parameter_string.empty()) SYSTEM_STDOUT("Parameter Combination: " << parameter_string);
    // Initializes project name and output directory
    std::ostringstream project_name;
    project_name << abm::util::getCurrentLocalTimeAsString() << "_" << parameter_string << current_sim_seed;
    auto project_name_str = project_name.str();
    int const max_filename_size = 254;
    if (project_name_str.length() > max_filename_size) {
        project_name_str = project_name_str.substr(0, max_filename_size);
    }

    // initializes session key sid for different result folders, e.g. ./coreABM ../../config.json -sid abc123
    auto sid = cmd_input_args_.find("sid") != cmd_input_args_.end() ? cmd_input_args_.find("sid")->second : "";
    std::string const output_folder_name = "results" + sid;
    const auto project_dir = static_cast<boost::filesystem::path>(output_dir).append(output_folder_name).append(project_name_str).string();

    // Initializes output handler, visualizer, analyzer and timer
    const auto visualizer = createVisualizer(config_path_, project_dir, runs);
    const auto analyser = createAnalyser(config_path_, project_dir);
    std::vector<std::pair<std::string, std::vector<std::string>>> api_output;

    // Start parallelized for-loop over all runs for one parameter configuration
#pragma omp parallel for schedule(dynamic)
    for (int current_run = 1; current_run <= runs; ++current_run) {
        SYSTEM_STDOUT("Thread " << omp_get_thread_num() << ": Start Run " << current_run << "/" << runs);

        // Setup environment for each run, e.g. each run has its own random number generator.
        int const run_seed = current_run + current_sim_seed;
        const auto random_generator = std::make_unique<Randomizer>(run_seed);
        const auto site = createSites(current_run, random_generator.get(), analyser.get());
        visualizer->overwriteParameters(site->getOverwrittenVisParameters());

        SimulationTime time{site->getTimeStepping(), site->getMaxTime()}; time.updateTimestep(0);

        // Visualize initial condition
        visualizer->visualizeCurrentConfiguration(*site, time, current_run);
        // Start simulation for-loop over all timesteps for one run
        for (time.updateTimestep(0); !time.endReached(); ++time) {
            // All interactions and dynamics of the hABM for all cells is performed
            site->doAgentDynamics(random_generator.get(), time);
            // Visualize current configuration of simulation
            visualizer->visualizeCurrentConfiguration(*site, time, current_run, site->checkForStopping(time) || time.lastStepBeforEnd());
            if (site->checkForStopping(time)) {
                break;
            }
        }

        auto hash = abm::util::generateHashFromAgents(time.getCurrentTime(), site->getAgentManager()->getAllAgents());
        SYSTEM_STDOUT("Hash for run " + std::to_string(current_run) + " of " + parameter_string + ": "+ hash);
    }

    // Write outputs
    analyser->outputAllMeasurements();
}

std::unique_ptr<const Visualizer> Simulator::createVisualizer(std::string config_path_, std::string project_dir, int runs) const {
    return std::make_unique<const Visualizer>(config_path_, project_dir, runs);
}

std::unique_ptr<const Analyser> Simulator::createAnalyser(std::string config_path_, std::string project_dir) const {
    return std::make_unique<const Analyser>(config_path_, project_dir);
}

std::unique_ptr<Site> Simulator::createSites(int run, Randomizer* random_generator,
                                             const Analyser* analyser) const {
    return std::make_unique<CuboidSite>(random_generator,
                                        analyser->generateMeasurement(std::to_string(run)),
                                        config_path_, cmd_input_args_, output_dir_);
}
