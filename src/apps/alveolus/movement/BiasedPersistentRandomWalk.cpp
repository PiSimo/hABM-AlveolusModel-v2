//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#ifndef M_PI
#define M_PI    3.14159265358979323846f
#endif

#include "BiasedPersistentRandomWalk.h"

BiasedPersistentRandomWalk::BiasedPersistentRandomWalk(Agent *agent, double persistenceTime, double speed,
                                                       AlveoleSite* site) : Movement(site->getNumberOfSpatialDimensions()) {
    this->agent_ = agent;
    this->persistence_time_ = persistenceTime;

    alveolesite_ = site;

    sampler_ = std::make_unique<InversionSampler>();
    sampler_->setSampleFunction(0);

    if (agent->getInitialTime() > 0.0) {
        persistence_time_start_ = 0;
        persistence_time_left_ = alveolesite_->getRandomGenerator()->generateDouble() * persistenceTime;
    } else {
        persistence_time_start_ = alveolesite_->getRandomGenerator()->generateDouble() * persistenceTime;
        persistence_time_left_ = persistence_time_start_;
    }

    current_velocity_ = std::make_shared<Coordinate3D>();
    speed_ = speed;
    persistence_direction_ = std::make_unique<Coordinate3D>();
}

Coordinate3D *BiasedPersistentRandomWalk::move(double timestep, double dc) {
    setCurrentTimestep(timestep);
    if (persistentMove()) {
        *current_velocity_ = *movePersistent(timestep);
    } else {
        moveBiasedRandomly(timestep);
        agent_->setVariableOnEvent("reset-cumulative-gradient", 0);
        setNewPersistence();
    }
    decrementLeftTime(timestep);
    *current_move_ = *current_velocity_;
    return current_move_.get();
}

Coordinate3D *BiasedPersistentRandomWalk::movePersistent(double timestep) {
    double length = persistence_direction_->getMagnitude();
    if (length == 0) {
        *persistence_direction_ = *moveBiasedRandomly(timestep);
    } else {
        *persistence_direction_ = alveolesite_->generatePersistentDirectionVector(*current_pos_,
                                                                           speed_ * timestep,
                                                                           *persistence_direction_,
                                                                           persistent_angle_alpha_2_d_);
    }

    return persistence_direction_.get();
}

Coordinate3D *BiasedPersistentRandomWalk::moveBiasedRandomly(double timestep) {
    double length = speed_ * timestep;
    *current_velocity_ = alveolesite_->generateBiasedRandomDirectionVector(agent_, *current_pos_, length);
    persistent_angle_alpha_2_d_ = alveolesite_->getLatestAlpha2dTurningAngle();

    return current_velocity_.get();
}

void BiasedPersistentRandomWalk::decrementLeftTime(double timestep) {
    persistence_time_left_ -= timestep;
}

void BiasedPersistentRandomWalk::setNewPersistence() {
    *persistence_direction_ = *current_velocity_.get();
    persistence_time_left_ += persistence_time_;
}

bool BiasedPersistentRandomWalk::persistentMove() const {
    return (persistence_time_left_ > 0);
}

double BiasedPersistentRandomWalk::getStartingTime() {
    return round(persistence_time_start_);
}

void BiasedPersistentRandomWalk::setPreviousMove(Coordinate3D *prevMove) {
    *persistence_direction_ = *prevMove;
    persistent_angle_alpha_2_d_ = alveolesite_->getLatestAlpha2dTurningAngle();
}