//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#ifndef CORE_SIMULATION_CuboidSiteAlveolus_H
#define CORE_SIMULATION_CuboidSiteAlveolus_H

#include <string>
#include <iostream>

#include "core/simulation/Site.h"
#include "apps/alveolus/particles/ParticleManager.h"
#include "apps/alveolus/environment/Surface.h"

class ParticleManager;

struct PoreOfKohn {
    int id{};
    Coordinate3D position{};
};

struct AECTypeTwo {
    int id{};
    Coordinate3D position{};
    bool alive{};
};

struct AECTypeOne {
    int id{};
    Coordinate3D position{};
    std::vector<std::shared_ptr<Coordinate3D>> aec1_neighbors{};
    std::vector<std::shared_ptr<AECTypeTwo>> aec2_neighbors{};
    std::vector<std::shared_ptr<PoreOfKohn>> pok_neighbors{};
    bool alive{};
};

class AlveoleSite : public Site {
public:

    AlveoleSite(Randomizer *random_generator,
             std::shared_ptr<InSituMeasurements> measurements,
             std::string config_path, std::unordered_map<std::string,
             std::string> cmd_input_args, std::string output_path);

    void handleBoundaryCross(Agent * agent, Coordinate3D * movement, double current_time) final;
    /*!
     * Generates random direction vector on alveoleSite (sphere)
     * @param position Coordinate3D object that contains current position
     * @param length Double that containts desired length of random direction
     * @return Coordinate3D object that contains direction vector
     */
    Coordinate3D generateRandomDirectionVector(Coordinate3D position, double length) final;

    /// Same as generateRandomDirectionVector but based on previous movement
    Coordinate3D generatePersistentDirectionVector(Coordinate3D position, double length, Coordinate3D prevVector, double previousAlpha) final;

    /// Same as generateRandomDirectionVector but with a random bias (e.g. molecules)
    Coordinate3D generateBiasedRandomDirectionVector(Agent *agent, Coordinate3D position, double length);
    void setBoundaryCondition();
    Coordinate3D getLowerLimits();
    Coordinate3D getUpperLimits();
    bool overPOK(Coordinate3D position);
    bool containsPosition(Coordinate3D position) final;
    std::pair<bool, int> overAECT1(SphericCoordinate3D posConida);
    void adjustPosition(Coordinate3D& position);
    double getFeatureValueByName(std::string name) final;
    double getThicknessOfBorder() { return thicknessOfBorder; }
    double getLowerThetaBound() { return thetaLowerBound; }
    double getDistanceFromBoundary(Coordinate3D position);
    Coordinate3D getRandomPosition() final;
    Coordinate3D getRandomBoundaryPoint() final;
    Coordinate3D getRandomMinDistanceToBoundaryPosition(double minDistanceToBoundary);
    Coordinate3D getSiteCenter(){return centerOfSite;};
    double getRadiusAEC1() {return radiusAlvEpithTypeOne;};
    double getLengthAEC2() {return lengthAlvEpithTypeTwo;};
    double getRadiusPoK() {return radiusPoresOfKohn;};
    double getRadius() const override {return radius;};
    Surface getEnvSurface(){return env_surface_;};

    [[nodiscard]] std::string getType() const final { return "AlveoleSite"; }
    std::vector<std::shared_ptr<AECTypeOne>> getAECT1() { return alvEpithTypeOne; };
    std::vector<std::shared_ptr<AECTypeTwo>> getAECT2() { return alvEpithTypeTwo; };
    std::vector<std::shared_ptr<PoreOfKohn>> getPOK() { return poresOfKohn; };

    friend void InSituMeasurements::observeMeasurements(const SimulationTime &time);

    Coordinate3D generateBackShiftOnContacting(SphereRepresentation *active_sphere,
                                             SphereRepresentation *passiveSphere,
                                             double must_overhead) override;

    void initializeAgents(const abm::util::SimulationParameters::AgentManagerParameters &parameters,
                                      double current_time,
                                      double time_delta);

    void doAgentDynamics(Randomizer *random_generator, SimulationTime &time);

    void updateTimeStepSize(SimulationTime &time);
    int getClosestAECID(Coordinate3D position, bool over_aec1);
    std::unique_ptr<ParticleManager> particle_manager_;
    static double retrieveDirectionAngleAlpha(SphericCoordinate3D ownPos, SphericCoordinate3D goalPos);
private:
    /// Inserts the alveolar epithelium type 1 cells in the system
    void includeAlveolarEpitheliumType1();
    /// Inserts the pores of kohn in the system in the human case
    void includePoresOfKohnHuman();
    /// Inserts the  alveolar epithelium type 2 in the system in the human case
    void includeAlveolarEpitheliumType2Human();
    /// Inserts the pores of kohn in the system in the murine case
    void includePoresOfKohnGeneral();
    /// Inserts the  alveolar epithelium type 2 in the system in the murine case
    void includeAlveolarEpitheliumType2General();

    /// Surface function for alveolus
    Surface env_surface_;

    Coordinate3D generateDirectedVector(Coordinate3D position, SphericCoordinate3D posOfGoal, double length) final;
    Coordinate3D generateDirectedVector(Coordinate3D position, double alpha, double length) final;
    double minDistanceToPoK(const SphericCoordinate3D &sc3d);
    void calculateCrossPoints();

    void adjustAgents(double time_delta, double current_time);

    double radius;
    Coordinate3D centerOfSite;
    int organism{};
    bool obstacleIsOnType1{};
    int noOfPoK{};
    int noOfAEC2{};
    double thicknessOfBorder{};
    double surfactantThickness{};
    double thetaLowerBound{};
    double siteRadiusMin{};
    double radiusAlvEpithTypeOne{};
    double lengthAlvEpithTypeTwo{};
    double radiusPoresOfKohn{};
    double r0AEC1{};
    double r0AEC2{};
    double opR{};
    bool passiveMovementOn = false;

    SphericCoordinate3D posObstacle{};
    SphericCoordinate3D cellOfObstacle{};
    std::vector<std::pair<int, int> > pairAEC1Cells{};
    std::vector<std::shared_ptr<AECTypeOne>> alvEpithTypeOne{};
    std::vector<std::shared_ptr<AECTypeTwo>> alvEpithTypeTwo{};
    std::vector<std::shared_ptr<PoreOfKohn>> poresOfKohn{};
    std::vector<Coordinate3D> crossAEC1Points{};
    void updateTimestepForDC(double dc);
    void handleCmdInputArgs(std::unordered_map<std::string, std::string> cmd_input_args);
    void receiveFrontendParameter(abm::util::SimulationParameters &sim_para, abm::util::InputParameters &inp_para,
                                  const std::string &config_path, const std::string &output_path, std::string sid);
};

#endif /* CORE_SIMULATION_CuboidSiteAlveolus_H */