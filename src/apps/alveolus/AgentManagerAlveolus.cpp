//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.
#include "AgentManagerAlveolus.h"

void AgentManagerAlveolus::removeFungalCellFromList(int id, double current_time) {

    for (size_t i = 0; i < activeFungalCells.size(); i++) {
        if (activeFungalCells.at(i)->getId() == id) {
            activeFungalCells.erase(activeFungalCells.begin() + i);
            fungalCellRemoveTimes.push_back(current_time);
            fungalCellRemoveIDs.push_back(id);
            setLastFungalCellChange(current_time);
            DEBUG_STDOUT("Conidia removed. Chemotaxis cleanup initiated at " << current_time);
            dynamic_cast<AlveoleSite*>(site)->particle_manager_->setCleanChemotaxis(true);
            break;
        }
    }
}

void AgentManagerAlveolus::addGerminatedFungalCellToList(Agent *fungus, double current_time) {
    activeFungalCells.emplace_back(fungus);
    for (size_t i=0; i<fungalCellRemoveIDs.size(); i++) {
        if (fungalCellRemoveIDs[i] == fungus->getId()){
            fungalCellRemoveIDs.erase(fungalCellRemoveIDs.begin() + i);
            fungalCellRemoveTimes.erase(fungalCellRemoveTimes.begin() + i);
        }
    }
    setLastFungalCellChange(current_time);
    DEBUG_STDOUT("Conidia germinated. Chemotaxis cleanup initiated at " << current_time);
    dynamic_cast<AlveoleSite*>(site)->particle_manager_->setCleanChemotaxis(true);
}