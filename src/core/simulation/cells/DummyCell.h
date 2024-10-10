//
// Created by spiccioni on 10/10/24.
//

#ifndef CORE_SIMULATION_DUMMYCELL_H
#define CORE_SIMULATION_DUMMYCELL_H

#include "core/simulation/Cell.h"


class DummyCell : public Cell{
public:
    DummyCell(std::unique_ptr<Coordinate3D> c, int id, Site *site,
              double time_delta, double current_time) : Cell(std::move(c), id, site, time_delta, current_time) {}

    virtual void doMorphologicalChanges(double timestep, double current_time);
    std::string getTypeName();
    void setup(double time_delta, double current_time, abm::util::SimulationParameters::AgentParameters* parameters);
    abm::util::SimulationParameters::DummyCellParameters getParameters();
    virtual void handleInteractionEvent(InteractionEvent* ievent, double current_time);

private:
    abm::util::SimulationParameters::DummyCellParameters* dc_parameters;
};



#endif //CORE_SIMULATION_DUMMYCELL_H
