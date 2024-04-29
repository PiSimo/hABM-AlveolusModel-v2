//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#ifndef CORE_SIMULATION_ImmuneCellAlveolus_H
#define CORE_SIMULATION_ImmuneCellAlveolus_H

#include "core/simulation/Cell.h"
#include "core/simulation/cells/ImmuneCell.h"
#include "apps/alveolus/io_utils_alveolus.h"

class ImmuneCellAlveolus : public ImmuneCell {
public:
  // Class for immune cells
    ImmuneCellAlveolus(std::unique_ptr<Coordinate3D> c, int id, Site *site, double time_delta, double current_time)
        : ImmuneCell(std::move(c), id, site, time_delta, current_time) {};

    /*!
     * Sets up ImmuneCellAlveolus from input parameters
     * @param time_delta Double that contains time step
     * @param current_time Double that contains current time
     * @param parameters SimulationParameters with agent parameters
     */
    void setup(double time_delta, double current_time, abm::util::SimulationParameters::AgentParameters *parameters) final;

    /// Returns "ImmuneCellAlveolus"
    std::string getTypeName() final;

private:
    void handleInteractionEvent(InteractionEvent *ievent, double current_time) final;
    unsigned int currentNoOfUptakes;

    double radius;
    Coordinate3D cumulativePersistenceGradient;
    abm::utilAlveolus::ImmuneCellParametersAlveolus* ic_parameters;
};

#endif /* CORE_SIMULATION_ImmuneCellAlveolus_H */
