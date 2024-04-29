//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#ifndef CORE_SIMULATION_INTERACTIONSTATEFACTORY_H
#define CORE_SIMULATION_INTERACTIONSTATEFACTORY_H

#include <variant>

#include "core/simulation/interactiontypes/Contacting.h"
#include "core/simulation/interactiontypes/RigidContacting.h"
#include "core/simulation/interactiontypes/Ingestion.h"
#include "core/simulation/states/InteractionState.h"
#include "apps/alveolus/interactiontypes/PiercingOfImmuneCell.h"

class RigidContacting;

class InteractionStateFactory {

    using StateSetup = std::map<std::string, std::pair<std::variant<InteractionType, Contacting, RigidContacting, Ingestion, PiercingOfImmuneCell>, std::map<std::string, const Rate *>>>;

public:
  // Factory class for all interactions states between cells.  These can either be: Contacting, Ingestion, RigidContacting or InteractionType (Default).
    InteractionStateFactory(const
    std::vector<std::unique_ptr<abm::util::SimulationParameters::InteractionParameters>> &interaction_parameters,
                            RateFactory *rate_factory);

    std::unique_ptr<InteractionState> createInteractionState(Interaction *interaction,
                                                                    std::string interactionStateType,
                                                                    Cell *cell1, Cell *cell2);

private:

    std::map<std::string, StateSetup> state_parameters_;
};

#endif /* CORE_SIMULATION_INTERACTIONSTATEFACTORY_H */
