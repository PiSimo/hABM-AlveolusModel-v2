//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#include "AlveoleSite.h"

#include "CellFactoryAlveolus.h"
#include "apps/alveolus/AgentManagerAlveolus.h"
#include "apps/alveolus/InSituMeasurementsAlveolus.h"
#include "apps/alveolus/particles/ParticleManager.h"
#include "core/simulation/Interactions.h"
#include "core/simulation/boundary-condition/AbsorbingBoundaries.h"
#include "core/simulation/neighbourhood/BalloonListNHLocator.h"
#include "external/json.hpp"
#include "io_utils_alveolus.h"
#include <utility>

#include <fstream>

using json = nlohmann::json;

AlveoleSite::AlveoleSite(Randomizer* random_generator,
                       std::shared_ptr<InSituMeasurements> measurements,
                       std::string config_path,
                       std::unordered_map<std::string, std::string> cmd_input_args,
                       std::string output_path)
                       : Site(random_generator, std::move(measurements), config_path,  cmd_input_args, output_path) {

//    SYSTEM_STDOUT("Initialize AlveoleSite ...");
    measurements_->setSite(this);

    auto sid = cmd_input_args.find("sid") != cmd_input_args.end() ? cmd_input_args.find("sid")->second : "";
    const auto simulator_config = static_cast<boost::filesystem::path>(config_path).append("simulator-config.json");
    parameters_ = abm::utilAlveolus::getSimulationParameters(simulator_config.string());

    // Read in input parameters
    const auto input_config = static_cast<boost::filesystem::path>(config_path).append("input-config.json");
    input_parameters_ = abm::util::getInputParameters(input_config.string());

    // Read in cmd input and screening parameters
    parameters_.cmd_input_args = cmd_input_args;
    handleCmdInputArgs(cmd_input_args);

    // Read parameters from frontend if frontend-api.json exists
    receiveFrontendParameter(parameters_, input_parameters_, config_path, output_path, sid);

    // Initialize factories
    interaction_factory_ = std::make_unique<InteractionFactory>(parameters_.interaction_parameters, parameters_.use_interactions);
    rate_factory_ = std::make_unique<RateFactory>(input_parameters_.rates);
    cell_factory_ = std::make_unique<CellFactoryAlveolus>(parameters_.site_parameters);
    cell_state_factory_ = std::make_unique<CellStateFactory>(parameters_.site_parameters, rate_factory_.get());
    interaction_state_factory_ = std::make_unique<InteractionStateFactory>(parameters_.interaction_parameters, rate_factory_.get());
    agent_manager_ = std::make_unique<AgentManagerAlveolus>(parameters_, this);

    dimensions = parameters_.dimensions;
    setStoppingCondition(parameters_.stopping_criteria);

    auto* alveolus_parameters = static_cast<abm::utilAlveolus::AlveolusSiteParameter*>(parameters_.site_parameters.get());
    setBoundaryCondition();
    identifier_ = alveolus_parameters->identifier;
    centerOfSite = alveolus_parameters->site_center;
    radius = alveolus_parameters->site_radius;
    thetaLowerBound = alveolus_parameters->theta_lower_bound;
    siteRadiusMin = radius;
    surfactantThickness = alveolus_parameters->surfactant_thickness;
    thicknessOfBorder = alveolus_parameters->thickness_of_border;
    radiusPoresOfKohn = alveolus_parameters->radius_pores_of_kohn;
    radiusAlvEpithTypeOne = alveolus_parameters->radius_alv_epith_type_one;
    lengthAlvEpithTypeTwo = alveolus_parameters->length_alv_epth_type_two;
    noOfPoK = alveolus_parameters->number_of_pok;
    noOfAEC2 = alveolus_parameters->number_of_aec2;
    opR = alveolus_parameters->objects_per_row;
    organism = alveolus_parameters->organism;

    // Build alveolus
    includeAlveolarEpitheliumType1();
    if (organism == 1) {
        includePoresOfKohnHuman();
        includeAlveolarEpitheliumType2Human();
    } else {
        calculateCrossPoints();
        includePoresOfKohnGeneral();
        includeAlveolarEpitheliumType2General();
    }

    // Initialize neighbourhood locator
    neighbourhood_locator_ = std::make_unique<BalloonListNHLocator>(alveolus_parameters->agent_manager_parameters.agents, getLowerLimits(), getUpperLimits(), this);

    // Insert agents into alveolus
    initializeAgents(alveolus_parameters->agent_manager_parameters, 0, parameters_.time_stepping);
    agent_manager_->setInitFungalQuantity();
    adjustAgents(parameters_.time_stepping, 0);//
    env_surface_ = Surface(parameters_.site_parameters->surface);

    // Initialize particles and basic variables
    particle_manager_ = std::make_unique<ParticleManager>(alveolus_parameters->particle_manager_parameters, this);
    boundary_input_vector_ = Coordinate3D();
}

void AlveoleSite::handleCmdInputArgs(std::unordered_map<std::string, std::string>cmd_input_args) {
    // Parameters to be screened or from cmd input
    // You can add your parameters you wanna screen below here
    for (const auto&[key, value] : cmd_input_args) {
        if ("dc" == key) {
            auto* alveolus_parameters = static_cast<abm::utilAlveolus::AlveolusSiteParameter*>(parameters_.site_parameters.get());
            alveolus_parameters->particle_manager_parameters.diffusion_constant = std::stod(value);
//            SYSTEM_STDOUT("Set parameter: " << key << " = " << value);
            updateTimestepForDC(alveolus_parameters->particle_manager_parameters.diffusion_constant);
        }
        if ("sAEC" == key) {
            auto* alveolus_parameters = static_cast<abm::utilAlveolus::AlveolusSiteParameter*>(parameters_.site_parameters.get());
            alveolus_parameters->particle_manager_parameters.molecule_secretion_per_cell = std::stod(value);
//            SYSTEM_STDOUT("Set parameter: " << key << " = " << value);
        }
        if ("t0sAEC" == key) {
            auto* alveolus_parameters = static_cast<abm::utilAlveolus::AlveolusSiteParameter*>(parameters_.site_parameters.get());
            alveolus_parameters->particle_manager_parameters.start_secrection = std::stod(value);
        }
    }
    if (cmd_input_args.size() > 0) {
        for (const auto &agent: parameters_.site_parameters->agent_manager_parameters.agents) {
            if (abm::util::isSubstring("ImmuneCell", agent->type)) {
                for (const auto &[key, value]: cmd_input_args) {
                    if ("icNum" == key) {
                        agent->number = std::stod(value);
//                        SYSTEM_STDOUT("Set parameter: " << key << " = " << value);
                    }
                    if ("vAM" == key) {
                        agent->movement_parameters.mean = std::stod(value);
                    }
                }
            }
            if (abm::util::isSubstring("FungalCell", agent->type)) {
                auto *fc_parameters = static_cast<abm::util::SimulationParameters::AgentParameters *>(agent.get());
                for (const auto &[key, value]: cmd_input_args) {
                    if ("fcNum" == key) {
                        fc_parameters->number = std::stoi(value);
//                        SYSTEM_STDOUT("Set parameter: " << key << " = " << value);
                    }
                }
            }
        }

        for (const auto &input_rate: input_parameters_.rates) {

            for (const auto &[key, value]: cmd_input_args) {
                //uptake rates AECs
                if (key == "rupAEC2" && input_rate->key == "UptakenByAEC2") {
                    input_rate->rate = std::stod(value);
                }
                if (key == "rupAEC1" && input_rate->key == "UptakenByAEC1") {
                    input_rate->rate = std::stod(value);
                }
                //uptake by AM
                if (key == "rupAM" && input_rate->key == "UptakenByAM") {
                    input_rate->rate = std::stod(value);
                }

                //germination rate
                if (key == "germfac" && (input_rate->key == "GerminationOutside")) {
                    input_rate->rate = std::stod(value);
                }
                if (key == "germfac" && (input_rate->key == "GerminationInsideAEC1" || input_rate->key == "GerminationInsideAEC2" || input_rate->key == "GerminationInsideAM")) {
                    input_rate->rate = std::stod(value);
                }

                //kill by aec rate
                if (key == "killaec" && (input_rate->key == "KilledByAEC1" || input_rate->key == "KilledByAEC2")) {
                    input_rate->rate = std::stod(value);
                }
                if (key == "killam" && (input_rate->key == "KilledByAM")) {
                    input_rate->rate = std::stod(value);
                }
            }
        }

    }
}

void AlveoleSite::updateTimestepForDC(double dc) {
    // Stable timesteps for corresponding diffusion coefficients dc based on previous stability analysis
    if (abm::util::approxEqual(dc, 60))
        parameters_.time_stepping = 0.05;
    else if (abm::util::approxEqual(dc, 600))
        parameters_.time_stepping = 0.005;
    else if (abm::util::approxEqual(dc, 6000))
        parameters_.time_stepping = 0.0005;
    else {
        parameters_.time_stepping = 2 / dc;
    }
    SYSTEM_STDOUT("Updated timestep to " << parameters_.time_stepping);
}

void AlveoleSite::setBoundaryCondition() {
    boundary_condition_ = std::make_unique<AbsorbingBoundaries>(this);
}

bool AlveoleSite::containsPosition(Coordinate3D position) {
    SphericCoordinate3D sPos = abm::util::toSphericCoordinates(position - centerOfSite);
    bool insideMainSite = sPos.theta >= thetaLowerBound;

    bool insidePoreOfKohn = false;
    if (insideMainSite) {
        double distance;
        for (const auto &pore : poresOfKohn) {
            distance = position.calculateEuclidianDistance(pore->position);
            if (distance < radiusPoresOfKohn) {
                insidePoreOfKohn = true;
                break;
            }
        }
    }
    bool inside = insideMainSite && !insidePoreOfKohn;
    return inside;
}

void AlveoleSite::adjustPosition(Coordinate3D& position) {
    auto sph_pos = abm::util::toSphericCoordinates(position);
    sph_pos.r = radius;
    auto new_cart_cord = abm::util::toCartesianCoordinates(sph_pos);
    position = new_cart_cord;
}

void AlveoleSite::includeAlveolarEpitheliumType1() {
    int counter_aec1 = 0;
    for (double theta = thetaLowerBound; theta <= M_PI; theta += M_PI / (0.5 * opR)) {
        const double numberOfObjectsPerPhiRow = std::max(floor(1.0 * opR * sin(theta)), 1.0);
        for (double phi = 0; phi + 1e-8 < 2 * M_PI; phi += 2 * M_PI / numberOfObjectsPerPhiRow) {
            AECTypeOne aec1;
            aec1.position = abm::util::toCartesianCoordinates(SphericCoordinate3D{radius + thicknessOfBorder / 2.0, theta, phi});
            aec1.id = counter_aec1;
            aec1.alive = true;
            alvEpithTypeOne.emplace_back(std::make_shared<AECTypeOne>(aec1));
            counter_aec1++;
        }
    }

    for (auto& aec1: alvEpithTypeOne) {
        for (auto& aec1_it: alvEpithTypeOne) {
            auto distance = (aec1_it->position - aec1->position).getMagnitude();
            if (distance < 2.0 * radiusAlvEpithTypeOne && distance > 1.0) {
                aec1->aec1_neighbors.emplace_back(std::make_shared<Coordinate3D>(aec1_it->position));
                if (distance < 1.5 * radiusAlvEpithTypeOne) {
                    if (aec1->id < aec1_it->id) pairAEC1Cells.emplace_back(aec1_it->id, aec1->id);
                }
            }
        }
    }

}

void AlveoleSite::includePoresOfKohnHuman() {
    for (int j = 0; j < noOfPoK; j++) {
        SphericCoordinate3D pos_spheric{};
        size_t iterations = 0; int rand;
        bool condition1Theta, condition2Theta, MaxItNotReached, MindistReached;
        do {
            if (!pairAEC1Cells.empty()) {
                rand = random_generator_->generateInt(pairAEC1Cells.size() - 1);
                auto pair = pairAEC1Cells[rand];
                auto pos1 = alvEpithTypeOne[pair.first]->position;
                auto pos2 = alvEpithTypeOne[pair.second]->position;
                auto diff_half_way = (pos1 - pos2) * 0.5 + pos2;
                pos_spheric = abm::util::toSphericCoordinates(diff_half_way);
                pos_spheric.r = radius;
            } else {
                break;
            }
            MindistReached = minDistanceToPoK(pos_spheric) > radiusPoresOfKohn * 3;
            condition1Theta = pos_spheric.theta < M_PI - (30.0 / 116.5);
            condition2Theta = pos_spheric.theta > thetaLowerBound + 0.35;
            MaxItNotReached = iterations < 1000;
            iterations++;
        } while(!(condition1Theta && condition2Theta && MaxItNotReached && MindistReached));
        PoreOfKohn pore{j, abm::util::toCartesianCoordinates(pos_spheric)};
        poresOfKohn.push_back(std::make_shared<PoreOfKohn>(pore));
        if (!pairAEC1Cells.empty()) pairAEC1Cells.erase(pairAEC1Cells.begin() + rand);
    }

    for (auto &pok: poresOfKohn) {
        for (auto &aec: alvEpithTypeOne) {
            Coordinate3D nConn = pok->position - aec->position;
            if (nConn.getMagnitude() < radiusAlvEpithTypeOne + radiusPoresOfKohn) {
                aec->pok_neighbors.emplace_back(pok);
            }
        }
    }

}

void AlveoleSite::includeAlveolarEpitheliumType2Human() {
    for (int j = 0; j < noOfAEC2; j++) {
        SphericCoordinate3D pos_spheric{};
        size_t iterations = 0; int rand;
        bool MaxItNotReached, MindistReached;
        do {
            if (!pairAEC1Cells.empty()) {
                rand = random_generator_->generateInt(pairAEC1Cells.size() - 1);
                auto pair = pairAEC1Cells[rand];
                auto pos1 = alvEpithTypeOne[pair.first]->position;
                auto pos2 = alvEpithTypeOne[pair.second]->position;
                auto diff_half_way = (pos1 - pos2) * 0.5 + pos2;
                pos_spheric = abm::util::toSphericCoordinates(diff_half_way);
                pos_spheric.r = radius;
            } else {
                break;
            }
            MindistReached = minDistanceToPoK(pos_spheric) > radiusPoresOfKohn * 2;
            MaxItNotReached = iterations < 1000;
            iterations++;
        } while(!(MaxItNotReached && MindistReached));
        int number_type_one = alvEpithTypeOne.size();
        AECTypeTwo aec2{j + number_type_one, abm::util::toCartesianCoordinates(pos_spheric), true};
        alvEpithTypeTwo.push_back(std::make_shared<AECTypeTwo>(aec2));
        if (!pairAEC1Cells.empty()) pairAEC1Cells.erase(pairAEC1Cells.begin() + rand);
    }

    for (auto &aec2: alvEpithTypeTwo) {
        for (auto &aec: alvEpithTypeOne) {
            Coordinate3D nConn = aec2->position - aec->position;
            if (nConn.getMagnitude() < radiusAlvEpithTypeOne + lengthAlvEpithTypeTwo) {
                aec->aec2_neighbors.emplace_back(aec2);
            }
        }
    }

}


void AlveoleSite::calculateCrossPoints() {
    crossAEC1Points.clear();
    while (crossAEC1Points.size() < 10000) {
        Coordinate3D pos = getRandomMinDistanceToBoundaryPosition(5);
        std::vector<double> distances;
        for (size_t j = 0; j < alvEpithTypeOne.size(); j++) {
            distances.push_back(abm::util::toSphericCoordinates(alvEpithTypeOne.at(j)->position).calculateSphericalDistance(abm::util::toSphericCoordinates(pos)));
        }
        std::sort(distances.begin(), distances.end(), [](double u, double v) -> bool { return u > v; });
        for (size_t j = 0; j < distances.size(); j++) {
        }
        if (abs(distances.at(distances.size() - 1) - distances.at(distances.size() - 2)) < 2) {
            crossAEC1Points.push_back(pos);
        }
    }
}

void AlveoleSite::includePoresOfKohnGeneral() {
    calculateCrossPoints();
    double mindist{};
    Coordinate3D posPOK{};
    int iterations = 0;
    // Place the Pores of Kohn at the intersections between neighbouring AECT1
    for (int j = 0; j < noOfPoK; j++) {
        do {
            mindist = std::numeric_limits<double>::max();
            // Potential PoK positions were determined in crosspoints, now we pick
            int a = random_generator_->generateInt(crossAEC1Points.size() - 1);
            posPOK = crossAEC1Points.at(a);
            for (const auto &pore : poresOfKohn) {
                double dist = posPOK.calculateEuclidianDistance(pore->position);
                if (dist < mindist) mindist = dist;
            }
            iterations++;
        } while (mindist < 2 * radiusPoresOfKohn && iterations < 1000); //fpt measurement condition
        if (iterations < 1000) {
            PoreOfKohn pore{j, posPOK};
            poresOfKohn.push_back(std::make_shared<PoreOfKohn>(pore));
        } else {
            ERROR_STDERR("could not find a position for the pore of Kohn!!!");
        }
    }

    for (auto &pok: poresOfKohn) {
        for (auto &aec: alvEpithTypeOne) {
            Coordinate3D nConn = pok->position - aec->position;
            if (nConn.getMagnitude() < radiusAlvEpithTypeOne + radiusPoresOfKohn) {
                aec->pok_neighbors.emplace_back(pok);
            }
        }
    }
}

void AlveoleSite::includeAlveolarEpitheliumType2General() {
    double mindistPOK{}, mindistAEC2{};
    Coordinate3D posAEC2;
    int iterations = 0;
    // Place the AEC2 at the intersections between neighbouring AEC1
    for (int j = 0; j < noOfAEC2; j++) {
        do {
            mindistPOK = std::numeric_limits<double>::max();
            mindistAEC2 = std::numeric_limits<double>::max();
            // Potential AEC2 positions were determined in crossAEC1Points, now we pick
            int a = random_generator_->generateInt(crossAEC1Points.size() - 1);
            posAEC2 = crossAEC1Points.at(a);
//            for (size_t k = 0; k < poresOfKohn.size(); k++) {
            for (auto &pore: poresOfKohn){
                double dist = posAEC2.calculateEuclidianDistance(pore->position);
                if (dist < mindistPOK) mindistPOK = dist;
            }
            for (const auto &aec2 : alvEpithTypeTwo) {
                double dist = posAEC2.calculateEuclidianDistance(aec2->position);
                if (dist < mindistAEC2) mindistAEC2 = dist;
            }
            iterations++;
            } while ((mindistPOK < radiusPoresOfKohn + lengthAlvEpithTypeTwo || mindistAEC2 < lengthAlvEpithTypeTwo * sqrt(3.0)) && iterations < 1000); //fpt measurement condition
        if (iterations < 1000) {
            int number_type_one = alvEpithTypeOne.size();
            AECTypeTwo aec2{j + number_type_one, posAEC2, true};
            alvEpithTypeTwo.push_back(std::make_shared<AECTypeTwo>(aec2));
        } else {
            ERROR_STDERR("could not find a position for the AEC2!!!");
        }
    }

    for (auto &aec2: alvEpithTypeTwo) {
        for (auto &aec: alvEpithTypeOne) {
            Coordinate3D nConn = aec2->position - aec->position;
            if (nConn.getMagnitude() < radiusAlvEpithTypeOne + lengthAlvEpithTypeTwo) {
                aec->aec2_neighbors.emplace_back(aec2);
            }
        }
    }
}

Coordinate3D AlveoleSite::generateRandomDirectionVector(Coordinate3D position, double length) {
    double x, y, z, subst, r, phi, theta, u, dtheta, alpha, vix, viy, viz, radiusOrbit;
    SphericCoordinate3D currentPos = abm::util::toSphericCoordinates(position - centerOfSite);

    switch (dimensions) {
        case 2:
            radiusOrbit = currentPos.r;
            dtheta = length / radiusOrbit; //in rad
            alpha = random_generator_->generateDouble(M_PI * 2.0); //direction of the vector
            alpha2dTurningAngle = alpha;

            vix = radiusOrbit * sin(dtheta) * cos(alpha);
            viy = radiusOrbit * sin(dtheta) * sin(alpha);
            viz = radiusOrbit * (cos(dtheta) - 1);
            phi = currentPos.phi;
            theta = currentPos.theta;

            x = cos(phi) * (cos(theta) * vix + sin(theta) * viz) - sin(phi) * viy;
            y = sin(phi) * (cos(theta) * vix + sin(theta) * viz) + cos(phi) * viy;
            z = cos(theta) * viz - sin(theta) * vix;

            break;

        default:
            u = random_generator_->generateDouble();//sampler->sample();
            phi = random_generator_->generateDouble(M_PI * 2.0);
            r = length;
            subst = 2 * r * sqrt(u * (1 - u));
            x = subst * cos(phi);
            y = subst * sin(phi);
            z = r * (1 - 2 * u);

            break;
    }

    return Coordinate3D{x, y, z};
}

Coordinate3D AlveoleSite::generateBiasedRandomDirectionVector(Agent *agent, Coordinate3D position, double length) {

    Coordinate3D result{}, randomPart{}, directedPart{}, intermediatePositions{};
    intermediatePositions = position;

    double p = agent->getFeatureValueByName("migration-bias-probability"); // probability to move up the gradient
    double alpha = agent->getFeatureValueByName("gradient-direction"); // direction of the gradient as sensed by the

    // Biased Persistent Random Walk with mixed parts of random and directed walk
    if (random_generator_->generateInt(1) > 0) {
        randomPart = generateRandomDirectionVector(position, (1.0 - p) * length);
        intermediatePositions += randomPart;
        directedPart = generateDirectedVector(intermediatePositions, alpha, p * length);
        intermediatePositions += directedPart;
    } else {
        directedPart = generateDirectedVector(intermediatePositions, alpha, p * length);;
        intermediatePositions += directedPart;
        randomPart = generateRandomDirectionVector(intermediatePositions, (1.0 - p) * length);
        intermediatePositions += randomPart;
    }

    result = generateDirectedVector(position, abm::util::toSphericCoordinates(intermediatePositions - centerOfSite),
                                    length);
    return result;
}

Coordinate3D AlveoleSite::generatePersistentDirectionVector(Coordinate3D position,
                                                            double length,
                                                            Coordinate3D prevVector,
                                                            double previousAlpha) {
    double x, y, z, subst, r, phi, theta, u, dtheta, alpha, vix, viy, viz, radiusOrbit;
    SphericCoordinate3D currentPos = abm::util::toSphericCoordinates(position - centerOfSite);

    switch (dimensions) {
        case 2:
            radiusOrbit = currentPos.r;
            dtheta = length / radiusOrbit; //in rad
            alpha = previousAlpha; //direction of the vector

            vix = radiusOrbit * sin(dtheta) * cos(alpha);
            viy = radiusOrbit * sin(dtheta) * sin(alpha);
            viz = radiusOrbit * (cos(dtheta) - 1);
            phi = currentPos.phi;
            theta = currentPos.theta;

            x = cos(phi) * (cos(theta) * vix + sin(theta) * viz) - sin(phi) * viy;
            y = sin(phi) * (cos(theta) * vix + sin(theta) * viz) + cos(phi) * viy;
            z = cos(theta) * viz - sin(theta) * vix;

            break;

        default:
            x = prevVector.x;
            y = prevVector.y;
            z = prevVector.z;

            break;
    }

    return Coordinate3D{x, y, z};
}

Coordinate3D AlveoleSite::generateDirectedVector(Coordinate3D position, SphericCoordinate3D posOfGoal, double length) {
    double x = 0, y = 0, z = 0, phi = 0, theta = 0, dtheta = 0, alpha = 0, vix = 0, viy = 0, viz = 0, radiusOrbit = 0;
    SphericCoordinate3D currentPos = abm::util::toSphericCoordinates(position - centerOfSite);

    switch (dimensions) {
        case 2:
            radiusOrbit = currentPos.r;
            dtheta = length / radiusOrbit; //in rad
            alpha = retrieveDirectionAngleAlpha(currentPos, posOfGoal); //direction of the vector
            alpha2dTurningAngle = alpha;

            vix = radiusOrbit * sin(dtheta) * cos(alpha);
            viy = radiusOrbit * sin(dtheta) * sin(alpha);
            viz = radiusOrbit * (cos(dtheta) - 1);
            phi = currentPos.phi;
            theta = currentPos.theta;

            x = cos(phi) * (cos(theta) * vix + sin(theta) * viz) - sin(phi) * viy;
            y = sin(phi) * (cos(theta) * vix + sin(theta) * viz) + cos(phi) * viy;
            z = cos(theta) * viz - sin(theta) * vix;

            break;

        default:
            x = 0;
            y = 0;
            z = 0;

            break;
    }

    return Coordinate3D{x, y, z};
}

Coordinate3D AlveoleSite::generateDirectedVector(Coordinate3D position, double alpha, double length) {
    double x = 0, y = 0, z = 0, phi = 0, theta = 0, dtheta = 0, vix = 0, viy = 0, viz = 0, radiusOrbit = 0;
    SphericCoordinate3D currentPos = abm::util::toSphericCoordinates(position - centerOfSite);

    switch (dimensions) {
        case 2:
            radiusOrbit = currentPos.r;
            dtheta = length / radiusOrbit; //in rad
            alpha2dTurningAngle = alpha;

            vix = radiusOrbit * sin(dtheta) * cos(alpha);
            viy = radiusOrbit * sin(dtheta) * sin(alpha);
            viz = radiusOrbit * (cos(dtheta) - 1);
            phi = currentPos.phi;
            theta = currentPos.theta;

            x = cos(phi) * (cos(theta) * vix + sin(theta) * viz) - sin(phi) * viy;
            y = sin(phi) * (cos(theta) * vix + sin(theta) * viz) + cos(phi) * viy;
            z = cos(theta) * viz - sin(theta) * vix;

            break;

        default:
            x = 0;
            y = 0;
            z = 0;

            break;
    }

    return Coordinate3D{x, y, z};
}

std::pair<bool, int> AlveoleSite::overAECT1(SphericCoordinate3D posConidia) {
    posObstacle = posConidia;
    int aec_id = 0;
    double minDistance = std::numeric_limits<double>::max();
    for (auto& aec1: alvEpithTypeOne) {
        double curr_dist = abm::util::toSphericCoordinates(aec1->position).calculateSphericalDistance(posObstacle);
        if (curr_dist < minDistance) {
            minDistance = curr_dist;
            cellOfObstacle = abm::util::toSphericCoordinates(aec1->position);
            aec_id = aec1->id;
        }
    }
    obstacleIsOnType1 = true;

//    check if obstacle is on type II

    for (auto& aec2: alvEpithTypeTwo) {
        auto spheric = abm::util::toSphericCoordinates(aec2->position);
        double arcOfIntervalTheta = 0.5 * lengthAlvEpithTypeTwo / (radius);
        double thetaObstacle = posObstacle.theta;
        double thetaAEC2 = spheric.theta;
        //first condition: the spore has to be in a defined theta range [\theta-d\theta, \theta+d\theta]
        if ((thetaObstacle <= thetaAEC2 + arcOfIntervalTheta) && (thetaObstacle >= thetaAEC2 - arcOfIntervalTheta)) {
            double d = spheric.calculateEuclidianDistance(posObstacle);
            double dmax = sqrt(lengthAlvEpithTypeTwo * lengthAlvEpithTypeTwo / 4.0 +
                         (thetaObstacle - thetaAEC2) * (thetaObstacle - thetaAEC2) *
                         radius * radius);
            // second condition: the spore should have a maximum distance from
            if (d <= dmax) {
                cellOfObstacle = spheric;
                obstacleIsOnType1 = false;
                aec_id = aec2->id;
                break;
            }
        }
    }
    return {obstacleIsOnType1, aec_id};
}

int AlveoleSite::getClosestAECID(Coordinate3D position, bool over_aec1) {
    int id = -1;
    double min_dist = std::numeric_limits<double>::max();
    if (over_aec1) {
        for (auto& aec1: alvEpithTypeOne) {
            double dist = aec1->position.calculateEuclidianDistance(position);
            if (dist < min_dist) {
                min_dist = dist;
                id = aec1->id;
            }
        }
        return id;
    } else {
        for (auto& aec2: alvEpithTypeTwo) {
            double dist = aec2->position.calculateEuclidianDistance(position);
            if (dist < min_dist) {
                min_dist = dist;
                id = aec2->id;
            }
        }
        return id;
    }
}

double AlveoleSite::retrieveDirectionAngleAlpha(SphericCoordinate3D ownPos, SphericCoordinate3D goalPos) {
    double alpha = 0;
    double dphi = ownPos.phi - goalPos.phi;
    double dphiAbs = fabs(dphi);
    double c = ownPos.theta;
    double b = goalPos.theta;
    double acosarg = sin(ownPos.theta) * sin(goalPos.theta) * cos(dphi) + cos(ownPos.theta) * cos(goalPos.theta);
    if (abs(acosarg) > 1) INFO_STDOUT("WARNING: ACOS argument might be greater than zero");
    double a = (abs(acosarg) < 1) ? acos(acosarg) : 0;
    if (c == 0) {
        alpha = goalPos.phi;
    } else {
        if (b == 0) {
            alpha = M_PI;
        } else {
            //compute beta by cases
            double beta;
            if (ownPos.phi == goalPos.phi) {
                if (ownPos.theta > goalPos.theta) {
                    beta = 0;
                } else {
                    beta = M_PI;
                }
            } else {
                acosarg = (cos(b) - cos(a) * cos(c)) / (sin(a) * sin(c));
                if (abs(acosarg) > 1) INFO_STDOUT("WARNING: ACOS argument might be greater than zero");
                beta = (abs(acosarg) < 1) ? acos(acosarg) : 0;
            }
            //compute alpha by cases
            if ((ownPos.phi <= goalPos.phi && dphiAbs <= M_PI) || (ownPos.phi > goalPos.phi && dphiAbs > M_PI)) {
                alpha = M_PI - beta;
            } else {
                alpha = M_PI + beta;
            }
        }
    }
    return alpha;
}

void AlveoleSite::handleBoundaryCross(Agent* agent, Coordinate3D* move_vec, double current_time) {
    boundary_condition_->handleBoundaryCross(agent, move_vec, current_time);
}

Coordinate3D AlveoleSite::getRandomPosition() {
    Coordinate3D randPos{};
    do {
        double x, y, z, phi, theta;
        double u, subst;
        switch (dimensions) {
            case 2: //on/in the surface of the sphere site
                u = random_generator_->generateDouble();
                phi = random_generator_->generateDouble(M_PI * 2.0);

                subst = 2 * radius * sqrt(u * (1 - u));
                x = subst * cos(phi);
                y = subst * sin(phi);
                z = radius * (1 - 2 * u);
                break;
            case 3:
                do {
                    x = random_generator_->generateDouble(-1.0 * radius, radius);
                    y = random_generator_->generateDouble(-1.0 * radius, radius);
                    z = random_generator_->generateDouble(-1.0 * radius, radius);
                } while (x * x + y * y + z * z >= radius * radius);
                break;
            default:
                do {
                    x = random_generator_->generateDouble(-1.0 * radius, radius);
                    y = random_generator_->generateDouble(-1.0 * radius, radius);
                    z = random_generator_->generateDouble(-1.0 * radius, radius);
                } while (x * x + y * y + z * z >= radius * radius);
                break;
        }
        //offset of the given coordinate elements to the center position of this site
        x += centerOfSite.x;
        y += centerOfSite.y;
        z += centerOfSite.z;

        randPos = Coordinate3D{x, y, z};
    } while (!containsPosition(randPos));
    return randPos;
}

Coordinate3D AlveoleSite::getRandomBoundaryPoint() {
    Coordinate3D boundaryPoint{};
    // Decide whether to use one of pores of Kohn or the alveolar entrance ring
    double lengthOfPoKLineElements = 2 * M_PI * radiusPoresOfKohn * noOfPoK;
    double lengthOfAERLineElements = 2 * M_PI * radius * sin(thetaLowerBound);
    do {
        double decisionRand = random_generator_->generateDouble(lengthOfPoKLineElements + lengthOfAERLineElements);
        if (decisionRand < lengthOfPoKLineElements) {
            // Use a pore of Kohn as boundary point
            unsigned int entrancePoKindex = random_generator_->generateInt(noOfPoK - 1);
            boundaryPoint = poresOfKohn[entrancePoKindex]->position;
            Coordinate3D shiftFromPoKCenter = generateRandomDirectionVector(
                    boundaryPoint, radiusPoresOfKohn * thetaLowerBound);
            boundaryPoint += shiftFromPoKCenter;
            DEBUG_STDOUT("entering an AM at PoK");
        } else {
            // Use the alveolar entrance ring as boundary point
            double r, phi, theta;
            SphericCoordinate3D sc3d{};
            boundaryPoint = getRandomPosition();
            sc3d = abm::util::toSphericCoordinates(boundaryPoint - centerOfSite);
            r = sc3d.r;
            phi = sc3d.phi;
            theta = thetaLowerBound + 0.001;
            sc3d = SphericCoordinate3D{r, theta, phi};
            boundaryPoint = abm::util::toCartesianCoordinates(sc3d);
        }
    } while (!containsPosition(boundaryPoint));

    // Generate a boundary vector in order to keep the agent within the system at least for the next step
    Coordinate3D nextPos = Coordinate3D();
    do {
        boundary_input_vector_ = generateRandomDirectionVector(boundaryPoint, 1);
        nextPos = boundaryPoint;
        nextPos += boundary_input_vector_;
    } while (!containsPosition(nextPos));

    return boundaryPoint;
}

double AlveoleSite::getDistanceFromBoundary(Coordinate3D position) {
    double minDistance = 1000000;

    if (containsPosition(position)) {
        //check alveolar entrance ring
        SphericCoordinate3D posSpheric = abm::util::toSphericCoordinates(position);
        double dtheta = posSpheric.theta - thetaLowerBound;
        minDistance = dtheta * posSpheric.r;

        // Check for pores of Kohn
        std::vector<SphericCoordinate3D>::iterator it;
        for (auto &pore: poresOfKohn){
            SphericCoordinate3D poreOfKohnPos = abm::util::toSphericCoordinates(pore->position);
            auto distance = posSpheric.calculateSphericalDistance(poreOfKohnPos);
            if (distance - radiusPoresOfKohn < minDistance) {
                minDistance = distance - radiusPoresOfKohn;
            }
        }
    }
    if (minDistance < 0) minDistance = 0;

    return minDistance;
}

Coordinate3D AlveoleSite::getRandomMinDistanceToBoundaryPosition(double minDistanceToBoundary) {
    Coordinate3D position{};
    do {
        position = getRandomPosition();
    } while (getDistanceFromBoundary(position) < minDistanceToBoundary);

    return position;
}

double AlveoleSite::minDistanceToPoK(const SphericCoordinate3D &sc3d) {
    double minDistance = std::numeric_limits<double>::max(); //µm
    for (auto &pore: poresOfKohn) {
        auto distance = abm::util::toSphericCoordinates(pore->position).calculateSphericalDistance(sc3d);
        if (distance < minDistance) {
            minDistance = distance;
        }
    }
    return minDistance;
}

Coordinate3D AlveoleSite::getLowerLimits() {
    return Coordinate3D{centerOfSite.x - 1.2 * radius, centerOfSite.y - 1.2 * radius, centerOfSite.z - 1.2 * radius};
}

Coordinate3D AlveoleSite::getUpperLimits() {
    return Coordinate3D{centerOfSite.x + 1.2 * radius, centerOfSite.y + 1.2 * radius, centerOfSite.z + 1.2 * radius};
}

void AlveoleSite::adjustAgents(double time_delta, double current_time) {

    //repositioning to be on the surface again
    auto &allAgents = agent_manager_->getAllAgents();
    auto it = allAgents.begin();

    Coordinate3D origCoord, newCoord;
    SphericCoordinate3D sphereCoord;

    while (it != allAgents.end()) {
        origCoord = (*it)->getPosition();
        sphereCoord = abm::util::toSphericCoordinates(origCoord - centerOfSite);
        sphereCoord.r = radius;
        newCoord = abm::util::toCartesianCoordinates(sphereCoord);
        (*it)->setPosition(newCoord);

        it++;
    }

    //resolve conflicts
    it = allAgents.begin();

    while (it != allAgents.end()) {
        (*it)->getInteractions()->avoidNewInteractions(time_delta, current_time);
        it++;
    }

}

double AlveoleSite::getFeatureValueByName(std::string name) {
    double value = 0;
    if (name == "surfactantThickness") {
        value = surfactantThickness;
    }
    if (name == "radius") {
        value = radius;
    }
    if (name == "radius") {
        value = radius;
    }
    if (name == "radiusPoresOfKohn") {
        value = radiusPoresOfKohn;
    }
    if (name == "radiusAlvEpithTypeOne") {
        value = radiusAlvEpithTypeOne;
    }
    if (name == "lengthAlvEpithTypeTwo") {
        value = lengthAlvEpithTypeTwo;
    }
    return value;
}


Coordinate3D AlveoleSite::generateBackShiftOnContacting(SphereRepresentation* activeSphere, SphereRepresentation* passiveSphere, double mustOverhead) {

    Coordinate3D normalVecBetwCells = activeSphere->getEffectiveConnection(passiveSphere);
    double overlap = passiveSphere->getRadius() + activeSphere->getRadius() - normalVecBetwCells.getMagnitude();

    Coordinate3D backShift = normalVecBetwCells;
    if (overlap > 0 && backShift.getMagnitude() !=0 ) {
        backShift *= -(overlap - mustOverhead)/backShift.getMagnitude();
        auto potential_postion_sph = abm::util::toSphericCoordinates(activeSphere->getPosition() + backShift);
        potential_postion_sph.r = radius;
        auto potential_postion = abm::util::toCartesianCoordinates(potential_postion_sph);
        backShift = potential_postion - activeSphere->getPosition();
    } else {
        backShift *=0;
    }

    return backShift;
}

void AlveoleSite::updateTimeStepSize(SimulationTime &time) {
    if (particle_manager_->getDiffusionCoefficient() > 500) {
        if (particle_manager_->steadyStateReached(time.getCurrentTime()) &&
            !large_timestep_active) {// && abs((systime_min) - round(systime_min)) < 0.000001) {
            // increase the timestep as particle dynamics are not affected anymore
            time.updateDeltaT(0.1);
            large_timestep_active = true;
            DEBUG_STDOUT("Increasing timestep to " << time.getCurrentDeltaT() << " at time " << time.getCurrentTime());
        }
        // If a conidia is found, reduce timestep again to process particle dynamics
        if (!particle_manager_->steadyStateReached(time.getCurrentTime()) && large_timestep_active) {
            time.updateDeltaT(time.getLastDeltaT());
            large_timestep_active = false;
            DEBUG_STDOUT("Decreasing timestep to " << time.getCurrentDeltaT() << " at time " << time.getCurrentTime());
        }
    }
}

void AlveoleSite::initializeAgents(const abm::util::SimulationParameters::AgentManagerParameters &parameters,
                                   double current_time,
                                   double time_delta) {

    agent_manager_->setLastFungalCellChange(0.0);
    std::vector<Coordinate3D> AMpos;

    // Loop over agent types
    for (const auto &agent_parameters: parameters.agents) {
        auto initDistribution = agent_parameters->initial_distribution;
        std::string inputDistributionPath = boost::filesystem::path(agent_parameters->input_distribution_path).string();
        const auto name = agent_parameters->type;
        input_rates_[name] = agent_parameters->input_lambda;
        int numberOfAgents = static_cast<int>(agent_parameters->number);

        if (abm::util::isSubstring("ImmuneCell", name)) {
            std::stringstream entirePath;
            if (numberOfAgents < 0 and organism == 1) {
                entirePath << inputDistributionPath << "AM4-375" << "/";
            } else {
                int pathAM = (organism == 1) ? numberOfAgents : static_cast<int>(agent_parameters->number * 10);
                entirePath << inputDistributionPath << "AM" << std::to_string(pathAM) << "/";
            }
            // baseInputRates are the mean value over all calibrated lambda values / AM numbers for each system and result from previous analysis
            double baseInputRate = (organism == 1) ? 0.011863324353554 : 0.051869337535733;
            if (initDistribution == 1 && !abm::util::folderExists(entirePath.str())) {
                initDistribution = 0;
                // actual input rate correlates linearly with AM number
                input_rates_[name] = baseInputRate * agent_parameters->number;
                ERROR_STDERR(
                        "WARNING: For given AM number, input distribution " + entirePath.str() + " does not exist. \nChoose randomly and adjust lambda input rate.");
            } else if (initDistribution == 0 && input_rates_[name] == 0.0) {
                // actual input rate correlates linearly with AM number
                input_rates_[name] = baseInputRate * agent_parameters->number;
                ERROR_STDERR("WARNING: Input rate is 0.0. Change it to constant AM inputs.");
            }

            // Determine the numberOfAgents to put into the system
            if (initDistribution == 0 && agent_parameters->binomial_distribution.activated) {
                int curNo{};
                double p = agent_parameters->binomial_distribution.p; // p ~ 1/Total number of Alveoli in lung
                auto n = agent_parameters->binomial_distribution.n; // n ~ Total number of AM in lung
                double pRand{};
                do {
                    curNo = static_cast<int>(getRandomGenerator()->generateInt(30));
                    pRand = getRandomGenerator()->generateDouble();
                } while (pRand > abm::util::bernoulliProbability(n, curNo, p));
                numberOfAgents = curNo;
            }

            // Load AM distribution from input files and corresponding lambda value
            if (initDistribution == 1) {
                DEBUG_STDOUT("Choose AM positions from distributions.");
                inputDistributionPath = entirePath.str();
                // Choose input rate from calibrated lambda for the specific AM number
                std::stringstream pathToLambdaValue;
                pathToLambdaValue << inputDistributionPath << "lambdaInputRate.txt";
#pragma omp critical
                {
                    input_rates_[name] = abm::util::readLambdaValueFromFile(pathToLambdaValue.str());
                }
                std::vector<std::string> fileNames = abm::util::getFileNamesFromDirectory(inputDistributionPath, "POK");
                bool AMinside = false;
                while (!AMinside) {
                    AMpos.clear();
                    // Pick AM positions randomly from input file
                    int pick = getRandomGenerator()->generateInt(0, fileNames.size() - 1);
                    std::stringstream pathToFile;
                    pathToFile << inputDistributionPath << fileNames[pick];
#pragma omp critical
                    {
                        abm::util::read3DCoordinatesFromFile(AMpos, pathToFile.str());
                    }
                    DEBUG_STDOUT("Insert " + std::to_string(AMpos.size()) + " AMs from " + pathToFile.str());
                    // Check if all AM are inside the alveolus, it may happen that they are placed over a PoK
                    AMinside = true;
                    for (auto &AMpo : AMpos) {
                        if (!containsPosition(AMpo)) {
                            AMinside = false;
                        }
                    }
                }
                numberOfAgents = AMpos.size();
            }
        }

        // Create agents
        for (auto agent_pos = 0; agent_pos < numberOfAgents; agent_pos++) {
            Coordinate3D initialPosition{};
            std::shared_ptr<Agent> agent{};
            // place conidia to certain position
//            SphericCoordinate3D sphC{116.5, 1.5293, -0.555}; //For AMs
//            SphericCoordinate3D sphC{116.5, 1.535, 0.76}; //ON AEC2
//            SphericCoordinate3D sphC{116.5, 2.35, -0.16}; //ON AEC1
//            SphericCoordinate3D sphC{116.5, 1.915, 0.42}; //ON AEC1

            switch (initDistribution) {
                case 0:
                    initialPosition = getRandomPosition(); //abm::util::toCartesianCoordinates(sphC); //// place conidia to certain position
                    break;
                case 1:
                    // AM is placed according to a distribution which is loaded from file
                    if (abm::util::isSubstring("ImmuneCell", name)) {
                        DEBUG_STDOUT("Insert AM" << agent_pos << " at position " << AMpos.at(agent_pos).printCoordinates()
                                                 << ", " << containsPosition(AMpos.at(agent_pos)) << ", "
                                                 << containsPosition(AMpos.at(agent_pos)));
                        initialPosition = AMpos.at(agent_pos); // abm::util::toCartesianCoordinates(sphC1); //
                    } else {
                        initialPosition = getRandomPosition();
                    }
                    break;
                default:
                    initialPosition = getRandomPosition();
                    break;
            }
            agent = agent_manager_->emplace_back(cell_factory_->createCell(name, std::make_unique<Coordinate3D>(initialPosition),
                                                                         agent_manager_->generateNewID(),this,
                                                                         time_delta, current_time));

            if (abm::util::isSubstring("FungalCell", name)) agent_manager_->addFungalCellToList(agent.get());
        }

    }
}

void AlveoleSite::doAgentDynamics(Randomizer *random_generator, SimulationTime &time) {

    const auto current_time = time.getCurrentTime();
    const auto dt = time.getCurrentDeltaT();

    const auto &all_agents = agent_manager_->getAllAgents();
    if (!all_agents.empty()) {
        // Loop over all agents (random order)
        const auto current_order = abm::util::generateRandomPermutation(random_generator, all_agents.size());
        for (auto agent_idx = current_order.begin(); agent_idx < current_order.end(); ++agent_idx) {
            auto curr_agent = all_agents[*agent_idx];
            if (nullptr != curr_agent) {
                // Do all actions for one timestep for each agent (-> Cell.cpp)
                curr_agent->doAllActionsForTimestep(dt, current_time);
                // Remove spherical representations if the current agent got deleted
                if (curr_agent->isDeleted()) {
                    for (const auto &sphere: curr_agent->getMorphology()->getAllSpheresOfThis()) {
                        neighbourhood_locator_->removeSphereRepresentation(sphere);
                        agent_manager_->removeSphereRepresentation(sphere);
                    }
                    curr_agent = nullptr;
                }
            }
        }

        // Loop over all particles if steady state is not reached
        if (!particle_manager_->steadyStateReached(current_time)) {
            for (const auto &cur_particle: particle_manager_->getAllParticles()) {
                // Do all actions for one timestep for each particle
                cur_particle->doDiffusion(dt);
            }
            // Initialize Particles
            //TODO: this has to be done: after hyphae grew a certain amount of sphere, chemotaxis has to be activated for new aec cells
//            agent_manager_->trackingOfFungalElements();

            particle_manager_->inputOfParticles(dt, current_time);
            for (const auto &cur_particle: particle_manager_->getAllParticles()) {
                // Apply actual concentration change to particles
                cur_particle->applyConcentrationChange(dt);
            }
        }

        // Clean up agents
    }
    agent_manager_->cleanUpAgents(current_time);
    agent_manager_->inputOfAgents(current_time, random_generator);
//        measurements_->observeMeasurements(time);
    std::static_pointer_cast<InSituMeasurementsAlveolus>(measurements_)->observeMeasurements(time);
    updateTimeStepSize(time);
}

void AlveoleSite::receiveFrontendParameter(abm::util::SimulationParameters &sim_para, abm::util::InputParameters &inp_para,
                                    const std::string &config_path, const std::string &output_path, std::string sid) {

    const auto visualizer_config = static_cast<boost::filesystem::path>(config_path).append("visualisation-config.json").string();
    const auto fe_config_sid = static_cast<boost::filesystem::path>(output_path).append("frontend-api"+sid+".json").string();

    if (boost::filesystem::exists(fe_config_sid)  && sid != "") {
        std::ifstream json_file_fe(fe_config_sid);
        json fe_para;
        json_file_fe >> fe_para;
        auto visp = abm::util::getViualizerParameters(visualizer_config);

        sim_para.max_time = fe_para["frontend-api"]["simulation_parameter"]["max_time"].value("value", 100);
        auto number_images = fe_para["frontend-api"]["simulation_parameter"]["output_images"].value("value", 10);

        if (number_images > 0) {
            visp.output_interval = int(sim_para.max_time / (number_images * sim_para.time_stepping));
        } else {
            visp.pov_active = false;
        }

        visp.output_interval = std::max(int(sim_para.max_time / (number_images * sim_para.time_stepping)), 1);
        visp.output_video = false; // important for the frontend, this must be false

        auto* alveole_para = static_cast<abm::utilAlveolus::AlveolusSiteParameter*>(sim_para.site_parameters.get());
        alveole_para->particle_manager_parameters.molecule_secretion_per_cell = fe_para["frontend-api"]["alveolar_epithelial_cells"]["secretion_rate"].value("value", 1500);
        alveole_para->particle_manager_parameters.diffusion_constant = fe_para["frontend-api"]["alveolar_epithelial_cells"]["diffusion_coefficient"].value("value", 20);

        for (auto& rate: inp_para.rates) {
            if (rate->key == "FungalInternalized") {
                rate->rate = fe_para["frontend-api"]["alveolar_epithelial_cells"]["AEC_uptake_rate"].value("value", 0.003);
            }
        }

        for (auto& agent: sim_para.site_parameters->agent_manager_parameters.agents){
            if (abm::util::isSubstring("FungalCell", agent->type)) {
                agent->number = int(fe_para["frontend-api"]["aspergillus_fumigatus"]["number"].value("value", 10));
                agent->morphology_parameters.radius = fe_para["frontend-api"]["aspergillus_fumigatus"]["radius"].value("value", 1.25);
            } else if (abm::util::isSubstring("ImmuneCell", agent->type)) {
                agent->number = int(fe_para["frontend-api"]["alveolar_macrophages"]["number"].value("value", 10));
                agent->morphology_parameters.radius = fe_para["frontend-api"]["alveolar_macrophages"]["radius"].value("value", 10.6);
            }
        }
        sim_para.visualizer_to_overwrite = visp;
    }
}
