//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.


#include "FungalCellAlveolus.h"
#include "core/simulation/Site.h"
#include "core/simulation/morphology/SphericalMorphology.h"

#include "core/utils/macros.h"
#include "apps/alveolus/AlveoleSite.h"
#include "apps/alveolus/AgentManagerAlveolus.h"


void FungalCellAlveolus::handleInteractionEvent(InteractionEvent *ievent, double current_time) {

    if (ievent->getNextState() == "UptakenByAM") {
        auto aspState = getCellStateByName("UptakenByAM");
        if (aspState != 0 and abm::util::isSubstring(cellState->getStateName(), "Swelling")) {
            setState(aspState);
            INFO_STDOUT("Phagocytose: AspergillusFumigatus was phagocytosed");
            getSite()->getAgentManager()->removeFungalCellFromList(this->getId(), current_time);
            is_active_ = false;
            positionShiftAllowed = true;
        }
    }

    if (ievent->getNextState() == "GerminationInsideAM") {
        auto aspState = getCellStateByName("GerminationInsideAM");
        if (aspState != 0) {
            setState(aspState);
            INFO_STDOUT("Lysis: GerminationInsideAM of AspergillusFumigatus");
            positionShiftAllowed = false;
        }
//        setDeleted();
    }

    if (ievent->getNextState() == "KilledByAM") {
        auto aspState = getCellStateByName("KilledByAM");
        if (aspState != 0) {
            setState(aspState);
            INFO_STDOUT("Lysis: Death of AspergillusFumigatus");
        }
//        setDeleted();
    }
}



void FungalCellAlveolus::doMorphologicalChanges(double timestep, double current_time) {

    auto cs = cellState->getStateName();
//    std::cout << "Current CellState of id=" << id << ": " << cs << "\n";
    if (cs == "InitialCellState") {
        is_active_ = true;
        auto aspState = getCellStateByName("FungalOnAEC2");
        auto connected_aec = dynamic_cast<AlveoleSite*>(site)->overAECT1(abm::util::toSphericCoordinates(this->getPosition()));
        if (connected_aec.first) {
            aspState = getCellStateByName("FungalOnAEC1");
        }
        if (aspState != 0) {
            setState(aspState);
        }
    } else if (abm::util::isSubstring(cs, "Swelling")) {
        // Fungal swelling model
        swell_diameter_ += timestep * (rswelling_rate_ * swell_diameter_ * (1 - swell_diameter_/swell_carrying_capacity_));
        double new_radius = fc_parameters->morphology_parameters.radius + (swell_diameter_/2);
        this->surface->getBasicSphereOfThis()->setRadius(new_radius);

    } else if (abm::util::isSubstring(cs, "UptakenByAEC")) {
        if (is_active_) {
            is_active_ = false;
            getSite()->getAgentManager()->removeFungalCellFromList(this->getId(), current_time);
            positionShiftAllowed = false;
        }

        double radEnv = this->getSite()->getRadius();
        auto posCon = abm::util::toSphericCoordinates(this->getPosition());
        double radiusConidia = this->surface->getBasicSphereOfThis()->getRadius();
        if (posCon.r < radEnv + 1.9){
            posCon.r += 0.02;
            auto newPos = abm::util::toCartesianCoordinates(posCon);
            this->setPosition(newPos);
        }
        if (radiusConidia > 1.0){
            this->surface->getBasicSphereOfThis()->setRadius(radiusConidia - 0.01);
        }

    } else if (abm::util::isSubstring(cs, "Killed")) {
        double radiusConidia = this->surface->getBasicSphereOfThis()->getRadius();
        if (radiusConidia > 1.0){
            this->surface->getBasicSphereOfThis()->setRadius(radiusConidia - 0.01);
        }
    } else if (abm::util::isSubstring(cs, "Germination")) {

        if (!is_active_) {
            if (abm::util::isSubstring(cs, "GerminationInsideAEC")) {
                auto connected_aec = dynamic_cast<AlveoleSite *>(site)->overAECT1(
                        abm::util::toSphericCoordinates(this->getPosition()));
                if (connected_aec.first) {
                    dynamic_cast<AlveoleSite *>(site)->getAECT1()[connected_aec.second]->alive = false;
                } else {
                    dynamic_cast<AlveoleSite *>(site)->getAECT2()[connected_aec.second - dynamic_cast<AlveoleSite *>(site)->getAECT1().size()]->alive = false;
                }
            }

            is_active_ = true;
            dynamic_cast<AgentManagerAlveolus*>(site->getAgentManager())->addGerminatedFungalCellToList(this, current_time);
            positionShiftAllowed = false;
        }

        double radiusConidia = this->surface->getBasicSphereOfThis()->getRadius();
        if (radiusConidia < 2.3){
            this->surface->getBasicSphereOfThis()->setRadius(2.3);//radiusConidia + 0.1);
            auto pos = abm::util::toSphericCoordinates(this->getPosition());
            pos.r = 116.5;
            this->setPosition(abm::util::toCartesianCoordinates(pos));
        }

        if (hyphal_branches_.empty()) {
            hyphal_branches_.emplace_back(std::make_unique<HyphalBranch>(this, position, 0, Coordinate3D{0.0, 0.0, 0.0}));
            DEBUG_STDOUT("Start Hyphal Growth at " + std::to_string(current_time));
        } else {
            auto probability_next_hyphae = rate_next_mothercell_hyphae_ * timestep;
            if (probability_next_hyphae > site->getRandomGenerator()->generateDouble()) {
                hyphal_branches_.emplace_back(std::make_unique<HyphalBranch>(this, position, 0, Coordinate3D{0.0, 0.0, 0.0}));
                DEBUG_STDOUT("New HyphalBranch from ROOT at " + std::to_string(current_time));
            }
            for (auto &branch: hyphal_branches_) {
                branch->grow(timestep, current_time);
            }
        }
    }
}

bool FungalCellAlveolus::isActive() {
    auto cs = this->getCurrentCellState()->getStateName();
    return cs == "InitialCellState" || cs == "FungalResting" || cs == "FungalSwelling" || is_active_;
}

void FungalCellAlveolus::setup(double time_delta, double current_time, abm::util::SimulationParameters::AgentParameters * parameters) {
    fc_parameters = static_cast<abm::utilAlveolus::FungalParametersAlveolus * >(parameters);
    Cell::setup(time_delta, current_time, parameters);

    // Parameter for fungal swelling model - derived from fitted from ODE Model
    rswelling_rate_ = 0.0373; // in 1/min
    swell_diameter_ = 0.0053; // in µm
    swell_carrying_capacity_ = 1.84; // in µm
    this->surface->getBasicSphereOfThis()->setRadiusAtT0(fc_parameters->morphology_parameters.radius + swell_diameter_/2);
}
