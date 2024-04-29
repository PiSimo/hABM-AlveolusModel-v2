//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#ifndef COREABM_PARTICLEMANAGER_H
#define COREABM_PARTICLEMANAGER_H

#include "apps/alveolus/io_utils_alveolus.h"
#include "apps/alveolus/AlveoleSite.h"
#include "Particle.h"
#include "StaticBalloonList.h"

class AlveoleSite;

struct TRIANGLE3D {
    bool outside;
    unsigned int neighbourIds[3];
};

class ParticleManager {
public:
    ParticleManager(abm::utilAlveolus::ParticleManagerParameters parameters, Site *site);

    void initializeParticles(std::string filename);

    std::vector<std::shared_ptr<Particle>> getAllParticles() { return all_particles_; };
    std::vector<std::shared_ptr<Particle>> getAECParticles() { return aec_particles_; };

    std::vector<TRIANGLE3D> getTriangles() { return triangles_; };
    double getDiffusionCoefficient() {return dc_; };

    bool steadyStateReached(double current_time);
    void inputOfParticles(double time_delta, double current_time);
    void setCleanChemotaxis(bool val) { clean_chemotaxis_ = val; };

    std::unique_ptr<StaticBalloonList> particle_balloon_list_;
private:
    void computeMaxPossibleTimestep();
    void extractTriangles();
    void cleanUpAllParticles();
    void insertConcentrationAtArea(double time_delta, double current_time);

    AlveoleSite *site_{};
    double dc_{};
    double s_aec_{};
    double start_chemotaxis_{};
    bool visualize_concentration_{};

    int number_aecs_{};
    bool allow_higher_dt_{};
    bool clean_chemotaxis_{};

    std::vector<std::shared_ptr<Particle>> all_particles_{};
    std::vector<std::shared_ptr<Particle>> aec_particles_{};
    std::vector<int> aec_particles_cells_{};
    double sum_area_aec_particles_{};
    std::vector<double> sum_area_aec_particles_cells_{};
    std::vector<double> aec_secretion_rate_per_grid_{};
    std::vector<TRIANGLE3D> triangles_{};
};


#endif //COREABM_PARTICLEMANAGER_H
