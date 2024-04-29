//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#include <boost/filesystem.hpp>
#include <iostream>
#include <map>

//#include "apps/example/SimulatorExample.h"
#include "apps/alveolus/SimulatorAlveolus.h"
#include "core/simulation/Simulator.h"
#include "core/utils/io_util.h"
#include "core/utils/macros.h"
#include "core/utils/misc_util.h"
#include <omp.h>


std::unique_ptr<Simulator> createSimulator(const std::string simulator) {
    // Different Simulators are defined for different subprojects. It takes the value for "simulator" in the main config.json.
    // Please write a short description when you add a new Simulator.
    // -> "Simulator" is the simulator for the coreABM and only uses functionalities in the "core/" folder
    // -> "SimulatorExample" is an example that can be used to create a new simulator and is located in the "simulator/" folder
    if (simulator == "SimulatorAlveolus") {
        return std::make_unique<SimulatorAlveolus>();
    } else {
        return std::make_unique<Simulator>();
    }
}

int main(int argc, char** argv) {

    // Default location of config file (if no parameter is specified)
    boost::filesystem::path config_xml("../../config.json");
    if (argc > 1 && !(std::istringstream(argv[1]) >> config_xml)) {
        ERROR_STDERR("usage: " << argv[0] << " <config.json>");
        return 1;
    }
    if (!(boost::filesystem::exists(config_xml))) {
        ERROR_STDERR("Configuration File in " << config_xml.string() << " does not exist!");
        ERROR_STDERR("usage: " << argv[0] << " <config.json>");
        return 2;
    }

    // Change root directory for simulation to configuration location
    auto chd = chdir(&config_xml.parent_path().c_str()[0]);

    // Read cmd inputs and screening parameters
    const auto parameters = abm::util::getMainConfigParameters(config_xml.filename().string());
    std::unordered_map<std::string, std::string> input_args = abm::util::handleCmdInputs(argc, argv);

    // Create simulator
    auto simulator = createSimulator(parameters.simulator);

    // Initialize parallelization
#if defined(_OPENMP)
    omp_set_num_threads(parameters.number_of_threads);
    DEBUG_STDOUT("OpenMP activated with " << parameters.number_of_threads << " Thread(s).");
#endif

    // Start simulation runs
    if (parameters.screening_parameters.empty()) {
//        const auto simulator = std::make_unique<const SimulatorExample>(parameters.config_path, input_args);
        simulator->setConfigPath(parameters.config_path);
        simulator->setCmdInputArgs(input_args);
        simulator->setOutputPath(parameters.output_dir);
        simulator.get()->executeRuns(parameters.runs, parameters.system_seed, parameters.output_dir, parameters.input_dir);
    } else {
        // Screening over all parameter combinations specified as sets in the configuration file <config.json>
        // For screening, the cartesian product of all the single parameters sets is generated
        // If you want to resume a screening from a certain index, you can change screen_start_idx in main config
        const auto [parameter_names, value_combinations] = abm::util::calculateCartesianProd(parameters.screening_parameters);
        for (int sim = parameters.screen_start_idx-1; sim < value_combinations.size(); ++sim) {
            std::stringstream sim_para{};
            for (int i = 0; i < parameter_names.size(); ++i) {
                sim_para << parameter_names[i] << value_combinations[sim][i] << "_";
                input_args[parameter_names[i]] = value_combinations[sim][i];
            }
            SYSTEM_STDOUT("Start " << parameters.runs << " runs of simulation " << sim + 1 << "/" << value_combinations.size());
//            auto simulator = std::make_unique<const SimulatorExample>(parameters.config_path, input_args);
            simulator->setConfigPath(parameters.config_path);
            simulator->setCmdInputArgs(input_args);
            simulator->setOutputPath(parameters.output_dir);
            simulator.get()->executeRuns(parameters.runs, parameters.system_seed, parameters.output_dir, parameters.input_dir, sim, sim_para.str());
        }
    }
    return 0;
}
