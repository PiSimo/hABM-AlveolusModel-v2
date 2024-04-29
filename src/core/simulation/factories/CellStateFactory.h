//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#ifndef CORE_SIMULATION_CELLSTATEFACTORY_H
#define CORE_SIMULATION_CELLSTATEFACTORY_H

#include "core/utils/io_util.h"
#include "RateFactory.h"

class CellState;
class Cell;
class Rate;

class CellStateFactory {
    using StateSetup = std::map<std::string, std::map<std::string, const Rate *>>;
public:
    // Factory class for initializing all possible cell states according to the simulator configuration
    CellStateFactory(const std::unique_ptr<abm::util::SimulationParameters::SiteParameters> &site_parameters,
                     RateFactory *rate_factory);

    std::shared_ptr<CellState> createCellState(Cell *cell, const std::string &state_name);
    StateSetup &getStateSetup(const std::string &site_identifier, const std::string &agent_type);

private:
    std::map<std::string, const Rate *> getNextStates(const std::string &stae_name,
                                                             const std::string &site_identifier,
                                                             const std::string &agent_type);
    std::map<std::pair<std::string, std::string>, StateSetup> next_states;

};

#endif /* CORE_SIMULATION_CELLSTATEFACTORY_H */
