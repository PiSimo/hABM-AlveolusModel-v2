//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#ifndef COREABM_PARTICLENEIGHBOURLIST_H
#define COREABM_PARTICLENEIGHBOURLIST_H


#include "Particle.h"

class Particle;


class ParticleNeighbourList {
public:
    ParticleNeighbourList(Particle *p);
    void addNeighbour(Particle *p, double area, double dc);
    bool existsInNeighbourList(Particle *p);

    std::vector<Particle *> &getNeighbours() { return neighbour_particles_; };
    std::vector<double> &getDistances() { return neighbour_distances_; };
    std::vector<double> &getContactAreas() { return neighbour_contact_area_; };
    std::vector<double> &getPreFactorsPSE() { return prefactors_PSE_; };
    std::vector<double> &getPreFactorsGradient() { return prefactors_gradient_; };

private:

    Particle* particle_;

    std::vector<Particle *> neighbour_particles_{};

    std::vector<double> neighbour_distances_;
    std::vector<double> neighbour_contact_area_;
    std::vector<double> prefactors_PSE_;
    std::vector<double> prefactors_gradient_;
};


#endif //COREABM_PARTICLENEIGHBOURLIST_H
