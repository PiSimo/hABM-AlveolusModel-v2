//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#ifndef COREABM_AGENTMANAGERALVEOLUS_H
#define COREABM_AGENTMANAGERALVEOLUS_H


#include "core/simulation/AgentManager.h"
#include "core/simulation/Agent.h"
#include "AlveoleSite.h"

class AgentManagerAlveolus: public AgentManager {
public:
    AgentManagerAlveolus(abm::util::SimulationParameters& parameters, Site *site) : AgentManager(parameters, site){};

    void removeFungalCellFromList(int id, double current_time) final;

    void addGerminatedFungalCellToList(Agent *fungus, double current_time);
};


#endif //COREABM_AGENTMANAGERALVEOLUS_H
