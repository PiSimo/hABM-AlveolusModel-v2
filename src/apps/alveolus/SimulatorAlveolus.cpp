//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#include "core/simulation/Site.h"
#include "core/utils/macros.h"
#include "SimulatorAlveolus.h"

#include "AnalyserAlveolus.h"
#include "AlveoleSite.h"
#include "apps/alveolus/visualizer/VisualizerAlveolus.h"
#include <unordered_map>

void SimulatorAlveolus::executeRuns(int runs, int seed, const std::string& output_dir, const std::string& input_dir, int sim,
                                   const std::string& parameter_string) const {
//    SYSTEM_STDOUT("SimulatorAlveolus: This is going to be amazing...");
    Simulator::executeRuns(runs, seed, output_dir, input_dir, sim, parameter_string);
}
std::unique_ptr<Site>
SimulatorAlveolus::createSites(int run, Randomizer* random_generator,
                              const Analyser* analyser) const {
//    SYSTEM_STDOUT("SimulatorAlveolus: This will even be more amazing...");

    return std::make_unique<AlveoleSite>(random_generator,
                                        analyser->generateMeasurement(std::to_string(run)),
                                        config_path_, cmd_input_args_, output_dir_);

}

std::unique_ptr<const Analyser> SimulatorAlveolus::createAnalyser(std::string config_path_, std::string project_dir) const {
    return std::make_unique<const AnalyserAlveolus>(config_path_, project_dir);
}

std::unique_ptr<const Visualizer> SimulatorAlveolus::createVisualizer(std::string config_path_, std::string project_dir, int runs) const {
    return std::make_unique<const VisualizerAlveolus>(config_path_, project_dir, runs);
}
