//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#include "testConfigurations.h"

#include <memory>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "core/analyser/Analyser.h"
#include "core/simulation/Simulator.h"
#include "core/simulation/Site.h"
#include "external/doctest/doctest.h"
#include "apps/alveolus/SimulatorAlveolus.h"

using boost::filesystem::path;
using boost::filesystem::exists;


std::unique_ptr<Simulator> createSimulator(const std::string simulator) {
    // Different Simulators are defined for different subprojects. It takes the value for "simulator" in the main config.json.
    // Please write a short description when you add a new Simulator.
    // -> "Simulator" is the simulator for the coreABM and only uses functionalities in the "core/" folder
    if (simulator == "SimulatorAlveolus") {
        return std::make_unique<SimulatorAlveolus>();
    } else {
        return std::make_unique<Simulator>();
    }
}

std::string abm::test::test_simulation(const std::string &config) {
    const auto parameters = abm::util::getMainConfigParameters(config);
    std::unordered_map<std::string, std::string> input_args;
    const auto simulator = createSimulator(parameters.simulator);
    simulator->setConfigPath(parameters.config_path);
    simulator->setCmdInputArgs(input_args);
    const auto run_seed = parameters.system_seed;
    const auto analyser = std::make_unique<Analyser>();
    const auto random_generator = std::make_unique<Randomizer>(run_seed);
    const auto sites = simulator->createSites(run_seed, random_generator.get(), analyser.get());
    const auto &site = sites;
    SimulationTime time{site->getTimeStepping(), site->getMaxTime()};
    for (time.updateTimestep(0); !time.endReached(); ++time) {    //inner loop: t -> t + dt
        site->doAgentDynamics(random_generator.get(), time);
        if (site->checkForStopping(time)) {
          break;
        }
    }
    return abm::util::generateHashFromAgents(time.getCurrentTime(), site->getAgentManager()->getAllAgents());
}

TEST_CASE ("Test Simulator Configuration") {
    std::cout << "Start basic test ...\n";
    path config("../../test/configurations/testSimulator/config.json");
    CHECK(exists(config) == true);
    const auto string_return = abm::test::test_simulation(config.string());
    CHECK(string_return == "17295131150868456548");
}

TEST_CASE ("Test Simulator Alveolus Configuration") {
    std::cout << "Start alveolus test ...\n";
    path config("../../test/configurations/testSimulatorAlveolus/config.json");
    CHECK(exists(config) == true);
    const auto string_return = abm::test::test_simulation(config.string());
    CHECK(string_return == "17733938994651597134");
}