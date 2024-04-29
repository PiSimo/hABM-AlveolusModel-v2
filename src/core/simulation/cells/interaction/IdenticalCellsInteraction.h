//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#ifndef CORE_SIMULATION_IDENTICALCELLSINTERCTION_H
#define CORE_SIMULATION_IDENTICALCELLSINTERCTION_H

#include <string>

#include "core/simulation/Interaction.h"


class IdenticalCellsInteraction : public Interaction {
public:
    // Class for default interaction after collision between two identical cell types.
    IdenticalCellsInteraction(std::string identifier, Cell *cell1, Cell *cell2, double time_delta, double current_time);
    [[nodiscard]] std::string getInteractionName() const final;
};

#endif /* CORE_SIMULATION_IDENTICALCELLSINTERCTION_H */
