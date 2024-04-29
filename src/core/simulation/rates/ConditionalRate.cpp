//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#include <iostream>

#include "ConditionalRate.h"
#include "core/utils/macros.h"
#include "apps/alveolus/cells/FungalCellAlveolus.h"


double ConditionalRate::calculateProbability(double timestep, double current_time, Condition *cond,  Cell* cell, Site* site) const{
  double p = 0;
  if (cond != nullptr) {
    if (condition_->isFulfilled(cond)) {
        // If in the fungus is the ode swelling model is applied, then the uptake depends on the radius increase!
        if (cell->getTypeName() == "FungalCellAlveolus" && abm::util::isSubstring(cell->getCurrentCellState()->getStateName(), "Swelling")) {
            double r = cell->getSurface()->getBasicSphereOfThis()->getRadius();
            double rAtT0 = cell->getSurface()->getBasicSphereOfThis()->getRadiusAtT0();
            double rel_size_change = (r * r) / (rAtT0 * rAtT0);
            p = constant_rate_ * rel_size_change * timestep;
        } else {
            p = constant_rate_ * timestep;
        }
    }
  } else {
    ERROR_STDERR("condition can't be fulfilled: 0 constantrate=" + std::to_string(constant_rate_) + "current condition = " + cond->getStringCondition());
  }
  return p;
}