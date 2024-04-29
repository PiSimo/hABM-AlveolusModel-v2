//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#include "ParticleNeighbourList.h"

ParticleNeighbourList::ParticleNeighbourList(Particle *p) {
    particle_ = p;
}

void ParticleNeighbourList::addNeighbour(Particle *p, double area, double dc) {

    if (!existsInNeighbourList(p)) {
        neighbour_particles_.push_back(p);
        double distance = p->getPosition().calculateEuclidianDistance(particle_->getPosition());
        neighbour_distances_.push_back(distance);
        neighbour_contact_area_.push_back(area);

        double prefactor_pse = dc * area / (distance * particle_->getArea());
        prefactors_PSE_.push_back(prefactor_pse);

        double const prefactor_gradient = area / (distance * particle_->getArea());
        prefactors_gradient_.push_back(prefactor_gradient);

    }
}

bool ParticleNeighbourList::existsInNeighbourList(Particle *p) {
    bool inside = false;

    for (auto np: neighbour_particles_) {
        if (p == np) {
            inside = true;
            break;
        }
    }

    return inside;
}
