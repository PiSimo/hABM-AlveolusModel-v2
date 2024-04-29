//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#include <cmath>

#include "core/simulation/AgentManager.h"
#include "core/simulation/factories/CellFactory.h"
#include "core/simulation/Interactions.h"
#include "core/simulation/cells/interaction/PhagocyteFungusInteraction.h"
#include "core/analyser/InSituMeasurements.h"
#include "core/utils/macros.h"
#include "core/simulation/factories/RateFactory.h"
#include "core/simulation/Site.h"
#include "core/simulation/states/InteractionState.h"


AgentManager::AgentManager(abm::util::SimulationParameters& parameters, Site *site) {
    this->site = site;
    time_delta_ = parameters.time_stepping;
    idHandling = 0;
    idHandlingSphereRepresentation = 0;
    for (auto& agent: parameters.site_parameters->agent_manager_parameters.agents){
        agent_types_.emplace_back(agent->type);
    }
}

void AgentManager::inputOfAgents(double current_time, Randomizer *random_generator) {
    for (auto agent_name: agent_types_) {
        double lambda = site->getInputRate(agent_name);
        if (lambda > 0) {
            if (current_time == 0) {
                // Generate the initial nextInputEventTime
                lastInputEventTime = 0;
                nextInputEventTime = 1.0 / (lambda) * log(1.0 / random_generator->generateDouble());
                DEBUG_STDOUT("Next input of " + agent_name + " at " + std::to_string(nextInputEventTime) + " with lambda input rate =" +
                             std::to_string(lambda));
            }
            if (current_time >= nextInputEventTime) {
                //Generate nextInputEventTime when time the previously drawn nextInputEventTime is exceeded
                insertAgentAtBoundary(site, agent_name, current_time);
                lastInputEventTime = nextInputEventTime;
                double diff = 1.0 / (lambda) * log(1.0 / random_generator->generateDouble());
                nextInputEventTime = lastInputEventTime + diff;
                DEBUG_STDOUT("Insert " + agent_name + " at " + std::to_string(current_time) + ". Next input at "
                + std::to_string(nextInputEventTime) + " with lambda input rate =" + std::to_string(lambda));
            }
        }
    }
}

void AgentManager::insertAgentAtBoundary(Site *site, std::string agentType, double current_time) {
    Coordinate3D initialPosition;
    Coordinate3D initialVector;

    Agent *agent = nullptr;
    int rejections = 0;

    // Add an agent to the system without having any collisions
    do {
        if (agent != nullptr) {
            removeAgent(site, agent, current_time);
        }
        initialPosition = site->getRandomBoundaryPoint();
        initialVector = site->getBoundaryInputVector();
        agent = createAgent(site, agentType, initialPosition, &initialVector, current_time);
        rejections++;
    } while ((agent->getInteractions()->hasCollisions() && rejections < 10000));
    if (rejections > 9999) {
        DEBUG_STDOUT("Could not find a position for the agent at the boundary. Agent is not added to the system.");
        if (agent != nullptr) removeAgent(site, agent, current_time);
    }
}

Agent *AgentManager::createAgent(Site *site, std::string agenttype, Coordinate3D c, Coordinate3D *prevMove, double current_time) {
    auto agent = emplace_back(site->getCellFactory()->createCell(agenttype, std::make_unique<Coordinate3D>(c), generateNewID(),
                                                      site, time_delta_, current_time));
    agent->getMovement()->setPreviousMove(prevMove);

    return agent.get();
}

void AgentManager::replaceAgent(Site *site,Agent *agent, std::unique_ptr<Coordinate3D> newCoord, Coordinate3D *prevMove,
                                double current_time) {

    std::string agentType = agent->getTypeName();
    auto newAgent = site->getCellFactory()->createCell(agentType, std::move(newCoord), idHandling, site, time_delta_, current_time);
    if (newAgent != 0) {
        newAgent->getMovement()->setPreviousMove(prevMove);
        std::replace_if(allAgents.begin(), allAgents.end(), [agent](const auto &a) { return agent == a.get(); },
                        newAgent);
        idHandling++;
    }
    agent->setDeleted();

}

void
AgentManager::replaceAgent(Site *site, Agent *agentToReplace, std::shared_ptr<Agent> newAgent, double current_time) {

    // If the new agent is the nullptr, delete the agent
    if (!newAgent) {
        auto all_interactions = agentToReplace->getInteractions()->getAllInteractions();
        for (size_t i = 0; i < all_interactions.size(); i++) {
            if (all_interactions.at(i)->getInteractionName() == "PhagocyteFungusInteraction") {
                Cell *cell1 = all_interactions.at(i)->getFirstCell();
                Cell *cell2 = all_interactions.at(i)->getSecondCell();
                if (cell1->getCurrentCellState()->getStateName() == "FungalPhagocytosed") {
                    cell1->setDeleted();
                } else if (cell2->getCurrentCellState()->getStateName() == "FungalPhagocytosed"){
                    cell2->setDeleted();
                }
            }
        }
        agentToReplace->setDeleted();
    } else {
        std::replace_if(allAgents.begin(),
                        allAgents.end(),
                        [agent = agentToReplace](const auto &a) { return agent == a.get(); },
                        newAgent);
    }

}

void AgentManager::removeAgent(Site *site, Agent *agent, double current_time) {

    // Remove agent and all its corresponding spheres in the neighbourhoodlocator
    for (auto sphRep: agent->getSurface()->getAllSpheresOfThis()) {
        site->getNeighbourhoodLocator()->removeSphereRepresentation(sphRep);
    }
    agent->setDeleted();
    if (abm::util::isSubstring("FungalCell", agent->getTypeName())) {
        removeFungalCellFromList(agent->getId(), current_time);
    }
    allAgents.erase(std::remove_if(allAgents.begin(),
                                   allAgents.end(),
                                   [agent](const auto &a) { return agent == a.get(); }), allAgents.end());
}

int AgentManager::getAgentQuantity(std::string agenttype) {
    int count = 0;
    for (auto agent: allAgents) {
        if (agent->getCurrentCellState()->getStateName() != "Death" && agent != 0) {
            if (agent->getTypeName() == agenttype) {
                count++;
            }
        }
    }
    return count;
}

const std::vector<std::shared_ptr<Agent>> &AgentManager::getAllAgents() {
    return allAgents;

}

void AgentManager::cleanUpAgents(double current_time) {

    for (auto it = allAgents.begin(); it != allAgents.end();) {
        if (*it == 0) {
            it = allAgents.erase(it);
        } else {
            if ((*it)->isDeleted()) {
                for (const auto &sphere: (*it)->getMorphology()->getAllSpheresOfThis()) {
                    site->getNeighbourhoodLocator()->removeSphereRepresentation(sphere);
                    removeSphereRepresentation(sphere);
                }
                if (abm::util::isSubstring("FungalCell", (*it)->getTypeName())) { this->removeFungalCellFromList((*it)->getId(), current_time); }
                it = allAgents.erase(it);
            } else {
                it++;
            }
        }
    }
}

int AgentManager::getNextSphereRepresentationId(SphereRepresentation *sphereRep) {
    sphereIdToCell[idHandlingSphereRepresentation] =
            sphereRep->getMorphologyElementThisBelongsTo()->getMorphologyThisBelongsTo()->getCellThisBelongsTo();
    sphereIdToSphereRep[idHandlingSphereRepresentation] = sphereRep;
    allSphereRepresentations.insert(sphereRep);
    return idHandlingSphereRepresentation++;
}

Cell *AgentManager::getCellBySphereRepId(int sphereRepId) {
    if (sphereIdToCell.find(sphereRepId) != sphereIdToCell.end()) {
        return sphereIdToCell[sphereRepId];
    }
    return nullptr;
}

SphereRepresentation *AgentManager::getSphereRepBySphereRepId(int sphereRepId) {
    if (sphereIdToSphereRep.find(sphereRepId) != sphereIdToSphereRep.end()) {
        return sphereIdToSphereRep[sphereRepId];
    }
    return nullptr;
}

void AgentManager::removeSphereRepresentation(SphereRepresentation *sphereRep) {
    allSphereRepresentations.erase(sphereRep);
    sphereIdToSphereRep.erase(sphereRep->getId());
    sphereIdToCell.erase(sphereRep->getId());
}

int AgentManager::getIdHandling() const {
    return idHandling;
}

void AgentManager::incrementIdHandling() {
    idHandling++;
}

std::vector<std::string> AgentManager::getAllAgentTypes(){
    std::vector<std::string> agent_names;
    for (auto agent: allAgents) {
        auto name = agent->getTypeName();
        auto it = find(agent_names.begin(), agent_names.end(), name);
        if (it == agent_names.end()){
            agent_names.emplace_back(name);
        }
    }
    return agent_names;
}

double AgentManager::getOccupancyDensityOfSpace() {
    double cellVolume = 0;
    Coordinate3D lowerLim = site->getLowerLimits();
    Coordinate3D upperLim = site->getUpperLimits();

    double x = abs(lowerLim.x) + upperLim.x;
    double y = abs(lowerLim.y) + upperLim.y;
    double z = abs(lowerLim.z) + upperLim.z;
    double siteVolume = 0;
    if (site->getNumberOfSpatialDimensions() == 2) {
        siteVolume = x * y;
    } else if (site->getNumberOfSpatialDimensions() == 3) {
        siteVolume = x * y * z;
    }

    for (size_t i = 0; i < allAgents.size(); i++) {
        cellVolume = cellVolume + allAgents[i]->getMorphology()->getVolume();
    }
    double occupancy = (cellVolume * 100) / siteVolume;
    return occupancy;
}

void AgentManager::removeFungalCellFromList(int id, double current_time) {
    for (size_t i = 0; i < activeFungalCells.size(); i++) {
        if (activeFungalCells.at(i)->getId() == id) {
            activeFungalCells.erase(activeFungalCells.begin() + i);
            fungalCellRemoveTimes.push_back(current_time);
            fungalCellRemoveIDs.push_back(id);
            setLastFungalCellChange(current_time);
            break;
        }
    }
}