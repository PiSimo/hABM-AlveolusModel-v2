//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#include "ImmuneCellMacrophage.h"

#include "core/analyser/Analyser.h"
//#include "core/io/InputConfiguration.h"
//#include "core/simulation/Particle.h"
#include "core/simulation/Site.h"
#include "apps/alveolus/AlveoleSite.h"
#include "apps/alveolus/movement/BiasedPersistentRandomWalk.h"


void ImmuneCellMacrophage::handleInteractionEvent(InteractionEvent *ievent, double current_time) {
    if (ievent->getNextState().compare("Pierce") == 0) {
        auto macrState = getCellStateByName("Death");
        if (macrState != 0) {
            setState(macrState);
        }
    }
}

std::string ImmuneCellMacrophage::getTypeName() {
    return "ImmuneCellMacrophage";
}

unsigned int ImmuneCellMacrophage::getCurrentNoOfUptakes() {
    return currentNoOfUptakes;
}

void ImmuneCellMacrophage::interactWithMolecules(double timestep) {

    // Get the particles for the interaction procedure of AM with molecules

//    AlveoleSite &alveoleSite = dynamic_cast<AlveoleSite*>(site);


    const auto &allParticles = alveolesite->particle_manager_->getAllParticles();
    if (allParticles.size() > 0) {
        // Initialize variables
        std::vector<unsigned int> interactionParticles;
        alveolesite->particle_manager_->particle_balloon_list_->setThreshold(radius);
        alveolesite->particle_manager_->particle_balloon_list_->getInteractions(getPosition(), interactionParticles);

        double dReceptorsConc = 0, dReceptors = 0, dLRComplexes = 0, dRinternalized = 0;
        Coordinate3D curGradient{0.0, 0.0, 0.0}, curAvgGradient{0.0, 0.0, 0.0};
        double radiusAM = radius;
        auto it = interactionParticles.begin();
        // Calculate current receptor-concentration over the cell surface and loop over particles
        double receptorsConc = receptors / (M_PI * radiusAM * radiusAM);
        while (it != interactionParticles.end()) {
            auto currentParticle = allParticles[(*it)];

            // Calculate receptor ligand dynamics
            double ligandsConc = currentParticle->getConcentration();
            dReceptorsConc -= k_blr * ligandsConc * receptorsConc;

            // Update receptor and complexes concentration changes
            if (isinf(dReceptorsConc)) dReceptorsConc = 0;
            dReceptors += dReceptorsConc * currentParticle->getArea();
            dLRComplexes -= dReceptorsConc * currentParticle->getArea();

            // If diffusion constant is very high, only internal AM dynamics considered
            // -> no exchange with the environment, profile of concentration is frozen at steady state
            if (alveolesite->particle_manager_->getDiffusionCoefficient() < 500) {
                currentParticle->addConcentrationChange(dReceptorsConc * timestep);
            }


            dReceptorsConc = 0;
            curGradient = currentParticle->getGradient();
            curAvgGradient += curGradient;

            it++;
        }

        curAvgGradient *= 1.0 / interactionParticles.size(); // 1/(µm²*µm) -> concentration change per micrometer

        // Compute the current absolute difference in LR number at front and rear of the macrophage
        double dLRdiff =
                k_blr * 4.0 * radiusAM * radiusAM * radiusAM / (3.0) * receptorsConc * curAvgGradient.getMagnitude() *
                timestep;
        curAvgGradient.setMagnitude(dLRdiff);

        // Apply changes for Receptor-Ligand model corresponding to Guo et al. (2007) model
        cumulativePersistenceGradient += curAvgGradient;
        consumedLigandsPersistence += dLRComplexes;
        dReceptors += k_r * Rinternalized;
        dLRComplexes -= k_i * LRComplexes;
        dRinternalized += k_i * LRComplexes - k_r * Rinternalized;
        receptors += dReceptors * timestep;
        if (receptors < 0) receptors = 0;
        LRComplexes += dLRComplexes * timestep;
        Rinternalized += dRinternalized * timestep;
    }
}

void ImmuneCellMacrophage::setVariableOnEvent(std::string variable, double value) {
    if (variable.compare("AMonAECT") == 0) {
        if (timeOfAECThit == -1) {
            //overwrite this variable only on the first event that occurs
            timeOfAECThit = value;
        }
    }

    if (variable.compare("reset-cumulative-gradient") == 0) {
        cumulativePersistenceGradient = {0.0, 0.0, 0.0};
    }
}

double ImmuneCellMacrophage::getFeatureValueByName(std::string featureName) {
    double value = 0;
    if (featureName.compare("migration-bias-probability") == 0) {
        double LRdiff_front_rear = cumulativePersistenceGradient.getMagnitude();

        // Alternative proportionality factor calculated from Farrell et al. (1990)
        value = LRdiff_front_rear * 0.6 / (0.424 * 500.0);
        if (value > 1.0) {
            value = 1.0;
        }
    }

    if (featureName.compare("receptor-difference-front-rear") == 0) {
        value = cumulativePersistenceGradient.getMagnitude();
    }
    double radius = alveolesite->getFeatureValueByName("radius");

    if (featureName.compare("gradient-direction") == 0) {
        Coordinate3D currentCumGradient = cumulativePersistenceGradient;
        if (currentCumGradient.getMagnitude() == 0) {
            //if no gradient was detectable then take random direction
            value = alveolesite->getRandomGenerator()->generateDouble(2.0 * M_PI);
        } else {
            currentCumGradient.setMagnitude(1.0);
            SphericCoordinate3D ownPos = abm::util::toSphericCoordinates(*position);
            Coordinate3D ownPosCart = getPosition();
            ownPosCart += currentCumGradient;
            SphericCoordinate3D gradientPos = abm::util::toSphericCoordinates(ownPosCart);
            gradientPos.r = radius;
            value = alveolesite->retrieveDirectionAngleAlpha(ownPos, gradientPos);
        }
    }
    return value;
}

void ImmuneCellMacrophage::setup(double time_delta,
                                 double current_time,
                                 abm::util::SimulationParameters::AgentParameters *parameters) {
    timeOfAECThit = -1;

    // Reference values from Guo et al. (2007)
    receptors = 50000.0;
    LRComplexes = 0.0;
    Rinternalized = 0.0;
    alveolesite = dynamic_cast<AlveoleSite*>(site);

    ic_parameters = static_cast<abm::utilAlveolus::ImmuneCellMacrophage *>(parameters);
//    auto ma_parameters = static_cast<abm::utilAlveolus::ImmuneCellMacrophage *>(parameters);
    k_blr = ic_parameters->k_blr;
    k_i = ic_parameters->k_i;
    k_r = ic_parameters->k_r;
    cumulativePersistenceGradient = {0.0, 0.0, 0.0};
    Cell::setup(time_delta, current_time, parameters);
    if (ic_parameters->movement_parameters.type == "BiasedPersistentRandomWalk") {
        movement = std::make_unique<BiasedPersistentRandomWalk>(this, parameters->movement_parameters.persistence_time,
                                                                parameters->movement_parameters.mean,
                                                                alveolesite);
        movement->setCurrentPosition(position.get());
        setMovement(movement);
    }
    radius = surface->getAllSpheresOfThis().front()->getRadius();
}