//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#include "VisualizerAlveolus.h"
#include "apps/alveolus/visualizer/PovFileAlveolus.h"
#include "core/visualisation/PovRayObject.h"
#include "core/utils/misc_util.h"


void VisualizerAlveolus::visualizeCurrentConfiguration(Site &site, const SimulationTime &time, int run,
                                                       bool simulation_end) const {
//    if (time.getCurrentTime() > 388) {parameters_.output_interval = 10;}
    bool writeout = (0 == time % static_cast<int>(parameters_.output_interval));

    // Generate visualization via PovFiles
    if (parameters_.pov_active && (writeout || simulation_end)) {

        Coordinate3D zoomed_camera = parameters_.camera_position;
        Coordinate3D look_at = parameters_.camera_look_at;

        // Code for moving camera
        auto moving_camera = false;

        // Code for turning camera around point of view
        if (moving_camera and time.getCurrentTime() < 10.0) {
            auto sph_cam = abm::util::toSphericCoordinates(zoomed_camera);
            SphericCoordinate3D sphC{sph_cam.r, sph_cam.theta + (10.0 - time.getCurrentTime())/60.0, sph_cam.phi};
            zoomed_camera = abm::util::toCartesianCoordinates(sphC);
        }

        // Code for zooming in and turning camera around point of view
        if (moving_camera and time.getCurrentTime() >= 10.0) {

            // point to look at
//            SphericCoordinate3D sphC{116.5, 1.5293, -0.555}; //for AMs
//            SphericCoordinate3D sphC{116.5, 1.535, 0.76}; //for AEC2
//            SphericCoordinate3D sphC{116.5, 2.3, -0.13}; //for AEC1
            SphericCoordinate3D sphC{116.5, 1.885, 0.42}; //ON AEC1

            if (time.getCurrentTime() <= 30.0) {
                look_at = abm::util::toCartesianCoordinates(sphC) * ((time.getCurrentTime()-5.0)/25.0);
            } else {
                look_at = abm::util::toCartesianCoordinates(sphC) * ((30.0-5.0)/25.0);;
            }
            double factor = time.getCurrentTime() > 30.0 ? 30.0 : time.getCurrentTime();
            zoomed_camera *= 40.0/(factor+30.0);

            if (time.getCurrentTime() <= 15.0) {
                auto sph_cam = abm::util::toSphericCoordinates(zoomed_camera);
                SphericCoordinate3D sphC{sph_cam.r, sph_cam.theta + (10.0 - time.getCurrentTime())/60.0, sph_cam.phi};
                zoomed_camera = abm::util::toCartesianCoordinates(sphC);
            } else {
                auto sph_cam = abm::util::toSphericCoordinates(zoomed_camera);
                SphericCoordinate3D sphC{sph_cam.r, sph_cam.theta + (10.0 - 15.0)/60.0, sph_cam.phi};
                zoomed_camera = abm::util::toCartesianCoordinates(sphC);
            }
        }
        // End code for moving camera

        const auto
                povDirTimestep = static_cast<boost::filesystem::path>(visualization_path_[run - 1]).append(
                abm::util::generateUniformString(time.getCurrentTime()));

        std::string filepath = abm::util::getLastNFolders(povDirTimestep.string(), 4) + ".png";
        site.addOutputPath(filepath); //send filepath to frontend api
        auto newPovFile = std::make_shared<PovFileAlveolus>(povDirTimestep.string());
        const auto boundary = "";

        std::string globals;
        newPovFile->setGlobalPart(globals);
        newPovFile->setDimensions(parameters_.px_width, parameters_.px_height);
        newPovFile->setCameraPart(PovRayObject::getCamera(zoomed_camera, look_at,
                                                          parameters_.camera_angle));
        newPovFile->setBackgroundPart(PovRayObject::getBackground(ColorRGB(1, 1, 1)));
        newPovFile->setLightPart("");
        for (const auto &lightsource : parameters_.light_sources) {
            newPovFile->addLightPart(PovRayObject::getLightsource(lightsource));
        }
        newPovFile->setIncludeTime(parameters_.include_time);
        newPovFile->setBorderPart(boundary);
        newPovFile->transcribeSite(site);
        newPovFile->transcribeParticles(site);
        newPovFile->transcribeAgents(site);
        newPovFile->doPovProcess(time.getCurrentTime());

        // Conclude simulation and generate video
        if (simulation_end) {
            Visualizer::concludeRun(site, run);
        }
    }
}
