//
// Created by spiccioni on 10/10/24.
//

#include "DummyCell.h"
#include "core/simulation/Site.h"

#include "core/utils/macros.h"

std::string DummyCell::getTypeName() {
    return "DummyCell";
}

void DummyCell::handleInteractionEvent(InteractionEvent* ievent, double current_time) {
    std::cout<<"Umbrella\n";
}

void DummyCell::doMorphologicalChanges(double timestep, double current_time) {
}

void DummyCell::setup(double time_delta, double current_time, abm::util::SimulationParameters::AgentParameters* parameters) {
    dc_parameters = static_cast<abm::util::SimulationParameters::DummyCellParameters*>(parameters);
    Cell::setup(time_delta, current_time, dc_parameters);
}


