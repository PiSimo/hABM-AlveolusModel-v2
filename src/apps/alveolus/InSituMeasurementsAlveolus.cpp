//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#include "InSituMeasurementsAlveolus.h"
#include "core/simulation/Site.h"


InSituMeasurementsAlveolus::InSituMeasurementsAlveolus(std::unordered_set<std::string> active_measurements, const std::string& id){

    active_measurements_ = active_measurements;
    for (const auto& active_ : active_measurements_) {
        // Remove everything after "%" in the active measurement string
        auto active = active_;
        int char_pos = active_.find("%");
        if (char_pos > 0) {
            active = active_.substr(0, char_pos);
        }

        // Here define your own measurements
        if ("alveole-statistics" == active) {
            pair_measurements_["alveole-statistics"] = std::make_unique<PairMeasurement>(id, "time", "nOfC", "nOfM");
        } else if ("alveolus_measurement" == active) {
            pair_measurements_["alveolus"] = std::make_unique<PairMeasurement>(id, "alveolus");
        } else if ("agent-statistics" == active) {
            time_last_measurement_["agent-statistics"] = 0.0;
            pair_measurements_["agent-statistics"] = std::make_unique<PairMeasurement>(id, "time", "agent", "agentid",
                                                                                       "state", "radius", "x", "y", "z",
                                                                                       "cellpart", "cellpart_id");
        } else if ("molecules" == active) {
            pair_measurements_["molecules"] = std::make_unique<PairMeasurement>(id, "name", "time", "x", "y", "z", "value", "part_id");
        } else if ("environment" == active) {
            pair_measurements_["environment"] = std::make_unique<PairMeasurement>(id, "x", "y", "z", "radius_or_length",
                                                                                  "type", "additional");
        }
    }
}
void InSituMeasurementsAlveolus::observeMeasurements(const SimulationTime& time) {
    using std::make_pair;
    const auto& current_time = time.getCurrentTime();

    for (const auto& active_ : active_measurements_) {

        // Code snippet to let your measurement only execute ever X-th simulation step
        // Name your measurement as "measurment%X" -> alveolus: "agent-statistics%25" ... every 25th step
        // Default if no value is given: Every 10th step
        int every_x_step = 10;
        auto active = active_;
        int char_pos = active_.find("%");
        if (char_pos > 0) {
            every_x_step = stoi(active_.substr(char_pos + 1, active_.size()));
            active = active_.substr(0, char_pos);
        }
        bool do_measurement = ((time.getCurrentTimeStep() % every_x_step) == 0) || site_->stopSimulation || time.lastStepBeforEnd();

        //Define here all your measurements
        // Measurements ever X timestep
        if ("alveole-statistics" == active && do_measurement) {
            pair_measurements_["alveole-statistics"]->addValuePairs(current_time,
                                                                    site_->getAgentManager()->getAgentQuantity(
                                                                            "FungalCellAlveolus"),
                                                                    site_->getAgentManager()->getAgentQuantity(
                                                                            "ImmuneCellMacrophage"));
        } else if ("alveolus_measurement" == active && do_measurement) {
            for (const auto agent : site_->getAgentManager()->getAllAgents()) {
                pair_measurements_["alveolus"]->addValuePairs(current_time,
                                                                      agent->getTypeName());
            }
        } else if ("agent-statistics" == active && do_measurement) {
            for (const auto agent: site_->getAgentManager()->getAllAgents()) {
                if (agent->getTypeName() == "FungalCellAlveolus") {
                    std::string cellpart = "Mothercell";
//                for (const auto cellparts: agent->getMorphology()->getAllSpheresOfThis()) {
                    const auto cellparts = agent->getMorphology()->getBasicSphereOfThis();
//                    if (cellparts->getCreationTime() >= time_last_measurement_["agent-statistics"] || cellpart != "Hyphae") {
                    pair_measurements_["agent-statistics"]->addValuePairs(current_time,
                                                                          agent->getTypeName(), agent->getId(),
                                                                          agent->getCurrentCellState()->getStateName(),
                                                                          cellparts->getRadius(),
                                                                          cellparts->getPosition().x,
                                                                          cellparts->getPosition().y,
                                                                          cellparts->getPosition().z,
                                                                          cellpart, cellparts->getDescription());
                    // First cellpart is always "Mothercell" - everything else is Hyphae
//                        cellpart = "Hyphae";
//                    }
//                }
                }
            }
            time_last_measurement_["agent-statistics"] = current_time;
        } else if ("molecules" == active && do_measurement) {
            auto alveoleSite = dynamic_cast<AlveoleSite*>(site_);
            for (auto part: alveoleSite->particle_manager_->getAllParticles()) {
                Coordinate3D pos = part->getPosition();
                double value = part->getConcentration();
                pair_measurements_["molecules"]->addValuePairs("molecule", current_time, pos.x, pos.y, pos.z, value, part->getId());
            }
            time_last_measurement_["molecules"] = current_time;
        }


        if (time.getMaxTime() - time.getCurrentTime() <= 0.0 or site_->stopSimulation) {
            if ("environment" == active) {
                if ("environment" == active) {
                    auto alveoleSite = dynamic_cast<AlveoleSite*>(site_);
                    double radAEC1 = alveoleSite->getRadiusAEC1();
                    double lengthAEC2 = alveoleSite->getLengthAEC2();
                    double radPOK = alveoleSite->getRadiusPoK();
                    double thetaBorder = alveoleSite->getLowerThetaBound();
                    double radius_alv = alveoleSite->getRadius();
                    double thickness = alveoleSite->getThicknessOfBorder();
                    pair_measurements_["environment"]->addValuePairs(0.0, 0.0, 0.0, radius_alv, "InnerAlveolus",
                                                                     thetaBorder);
                    pair_measurements_["environment"]->addValuePairs(0.0, 0.0, 0.0, radius_alv + thickness,
                                                                     "OuterAlveolus",
                                                                     thetaBorder);

                    for (auto& aec1: alveoleSite->getAECT1()) {
                        auto pos = aec1->position;
                        std::string type = "AEC1";
                        pair_measurements_["environment"]->addValuePairs(pos.x, pos.y, pos.z, radAEC1, type, aec1->id);

                        for (auto &part_: alveoleSite->particle_manager_->getAllParticles()) {
                            if (aec1->id == part_->associated_type1_aec_) {
                                auto pos_part_ = part_->getPosition();
                                if (abm::util::toSphericCoordinates(pos_part_).theta > thetaBorder) {
                                    std::string type = "Particle";
                                    pair_measurements_["environment"]->addValuePairs(pos_part_.x, pos_part_.y,
                                                                                     pos_part_.z, 0.0, type, aec1->id);
                                }
                            }
                        }

//                        for (auto &aec1_: aec1.aec1_neighbors) {
//                            auto pos_neigh = aec1_;
//                            std::string type = "AEC1neigh";
//                            pair_measurements_["environment"]->addValuePairs(pos_neigh.x, pos_neigh.y, pos_neigh.z, radAEC1, type, aec1.id);
//                        }
//
//                        for (auto &aec2_: aec1.aec2_neighbors) {
//                            auto pos_neigh = aec2_.position;
//                            std::string type = "AEC2neigh";
//                            pair_measurements_["environment"]->addValuePairs(pos_neigh.x, pos_neigh.y, pos_neigh.z, lengthAEC2, type, aec1.id);
//                        }
//
//                        for (auto &pok_: aec1.pok_neighbors) {
//                            auto pos_neigh = pok_.position;
//                            std::string type = "POKneigh";
//                            pair_measurements_["environment"]->addValuePairs(pos_neigh.x, pos_neigh.y, pos_neigh.z, radPOK, type, aec1.id);
//                        }
                    }

                    for (auto& aec2: alveoleSite->getAECT2()) {
                        auto pos = aec2->position;
                        if (pos.getMagnitude() > 0) {
                            std::string type = "AEC2";
                            pair_measurements_["environment"]->addValuePairs(pos.x, pos.y, pos.z, lengthAEC2, type,
                                                                             aec2->id);
                        }
                    }
                    for (auto& pok: alveoleSite->getPOK()) {
                        auto pos = pok->position;
                        if (pos.getMagnitude() > 0) {
                            std::string type = "PoK";
                            pair_measurements_["environment"]->addValuePairs(pos.x, pos.y, pos.z, radPOK, type, pok->id);
                        }
                    }
                }
                time_last_measurement_["environment"] = current_time;
            }
        }
    }
}
void InSituMeasurementsAlveolus::writeToFiles(const std::string &output_dir) const {
    InSituMeasurements::writeToFiles(output_dir);
}
