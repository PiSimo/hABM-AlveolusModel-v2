//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#ifndef CORE_SIMULATION_BOUNDARYCONDITION_H
#define CORE_SIMULATION_BOUNDARYCONDITION_H

#include <memory>

#include "core/simulation/Agent.h"
#include "core/basic/Coordinate3D.h"

class Analyser;
class Site;

class BoundaryCondition {
public:
  // Abstract class for boundary condition
    explicit BoundaryCondition(Site *site);

    virtual ~BoundaryCondition() = default;
    virtual void handleBoundaryCross(Agent *agent, Coordinate3D *moveVec, double current_time);
    virtual std::string getTypeName();

protected:
    Site *site;
};

#endif /* CORE_SIMULATION_BOUNDARYCONDITION_H */
