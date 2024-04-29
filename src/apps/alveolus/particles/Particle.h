//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#ifndef COREABM_PARTICLE_H
#define COREABM_PARTICLE_H

#include <vector>
#include <memory>
#include "core/basic/Coordinate3D.h"
#include "ParticleNeighbourList.h"
#include "core/simulation/Site.h"

class ParticleNeighbourList;

class Particle {
public:
    Particle(int id, Coordinate3D position, double area, Site *site);

    void addNeighbour(Particle *p, double contact_area, double dc);

    Coordinate3D getPosition() { return position_; };
    int getId() { return id_; };
    double getArea() { return area_; };
    double getConcentration() { return concentration_; };
    bool getIsInSite() const { return is_in_site_; };
    Coordinate3D getGradient();
    double getGradientStrength();

    double estimateLowestTimestep(double dc);

    std::unique_ptr<ParticleNeighbourList> particle_neighbourlist_{};
    int associated_type1_aec_{};
    int associated_type2_aec_{};

    void doDiffusion(double timestep);
    void applyConcentrationChange(double timestep);
    void addConcentrationChange(double diffusion);

private:
    int id_{};
    Coordinate3D position_{};
    double area_{};
    double concentration_{};
    bool is_in_site_{};
    double conc_change_in_current_timestep_{};


};


#endif //COREABM_PARTICLE_H
