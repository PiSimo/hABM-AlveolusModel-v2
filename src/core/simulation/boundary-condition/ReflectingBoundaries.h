/* 
 * File:   ReflectingBoundaries.h
 * Author: jpollmae
 *
 * Created on 27. Februar 2012, 14:27
 */

#ifndef CORE_SIMULATION_REFLECTINGBOUNDARIES_H
#define CORE_SIMULATION_REFLECTINGBOUNDARIES_H

#include "core/simulation/neighbourhood/BoundaryCondition.h"

class ReflectingBoundaries : public BoundaryCondition {
public:
    ReflectingBoundaries(Site* site);

    void handleBoundaryCross(Agent* agent, Coordinate3D* moveVec, double current_time);

  std::string getTypeName();
    
private:

};

#endif /* CORE_SIMULATION_REFLECTINGBOUNDARIES_H */
