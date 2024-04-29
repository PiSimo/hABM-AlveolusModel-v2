//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#ifndef CORE_SIMULATION_SimulatorAlveolus_H
#define CORE_SIMULATION_SimulatorAlveolus_H

#include <utility>

#include "core/simulation/Simulator.h"

class SimulatorAlveolus : public Simulator {
   public:
    SimulatorAlveolus() {};
    SimulatorAlveolus(std::string config_path, std::unordered_map<std::string, std::string> cmd_input_args)
    : Simulator(std::move(config_path), std::move(cmd_input_args)){};

    void executeRuns(int runs, int seed, const std::string& output_dir, const std::string& input_dir, int sim = 0,
                     const std::string& parameter_string = "") const override;

    std::unique_ptr<Site> createSites(int run,
                                      Randomizer* random_generator,
                                      const Analyser* analyser) const override;

    std::unique_ptr<const Analyser> createAnalyser(std::string config_path_, std::string project_dir) const override;

    std::unique_ptr<const Visualizer> createVisualizer(std::string config_path_, std::string project_dir, int runs) const override;

};

#endif  // CORE_SIMULATION_SimulatorAlveolus_H
