//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#include "PovFileAlveolus.h"
#include "core/basic/Coordinate3D.h"
#include "apps/alveolus/AlveoleSite.h"
#include "core/visualisation/PovRayObject.h"

void PovFileAlveolus::transcribeSite(Site &site) {
    AlveoleSite &alveoleSite = dynamic_cast<AlveoleSite&>(site);

    addPovObject("background { color rgb <1.0, 1.0, 1.0> }");

    Coordinate3D center = alveoleSite.getSiteCenter();
    double radius = alveoleSite.getRadius();

    double thetaLowerBound = alveoleSite.getLowerThetaBound();
    double thickness = alveoleSite.getThicknessOfBorder();
    ColorRGB color_base_alveolus = ColorRGB(1, 1, 0, 0.3);
    ColorRGB crgbTori = ColorRGB(0.5, 0.5, 0.5, 0.0);

    ColorRGB e1_alive = ColorRGB(1, 1, 0, 0.4);
    ColorRGB e1_dead = ColorRGB(0.7, 0.7, 0, 0.4);
    ColorRGB crgbE1 = ColorRGB(1, 1, 0, 0.8);

    ColorRGB e2_alive = ColorRGB(0, 1, 1, 0.4);
    ColorRGB e2_dead = ColorRGB(0, 0.7, 0.7, 0.4);
    ColorRGB crgbE2 = ColorRGB(0, 1, 0.8, 0.7);

    ColorRGB crgbPoK = ColorRGB(0, 0, 0, 0.5);

    Coordinate3D rightUpBox = Coordinate3D{radius + thickness, radius + thickness, radius * cos(thetaLowerBound)};
    Coordinate3D lowDownBox = Coordinate3D{-(radius + thickness), -(radius + thickness), -(radius + thickness)};
    std::string povBoxAlveolusBoundaries = PovRayObject::getBox(lowDownBox, rightUpBox, color_base_alveolus);

//    ColorRGB color_capi = ColorRGB(1.0, 0, 0, 0.8);
//    std::string outerBoundaryCap = PovRayObject::getSphere(center, radius + thickness + 5.0, color_capi);
//    std::string innerBoundaryCap = PovRayObject::getSphere(center, radius + thickness, color_capi);
//    std::string boundarySiteCap = PovRayObject::getDifference(outerBoundaryCap, innerBoundaryCap);
//
//    for (int i = 0; i<6; i++) {
//        auto posx = alveoleSite.getRandomPosition();
//        auto possph = abm::util::toSphericCoordinates(posx);
//        possph.r += thickness + 5.0;
//        posx = abm::util::toCartesianCoordinates(possph);
//        auto hole = PovRayObject::getSphere(posx, 15.0, color_capi);
//        auto hole_cap = PovRayObject::getIntersection(boundarySiteCap, hole);
////        addPovObject(hole_cap);
//        boundarySiteCap = PovRayObject::getDifference(boundarySiteCap, hole_cap);
//    }
//
//    addPovObject(boundarySiteCap);

    for (auto& aec1: alveoleSite.getAECT1()){

        crgbE1 = aec1->alive ? crgbE1 = e1_alive :  e1_dead;

        double radiusCell = alveoleSite.getRadiusAEC1();
        Coordinate3D posCell = aec1->position;

        std::string cellSphere = PovRayObject::getSphere(posCell, radiusCell, crgbE1);
        std::string outerBoundary = PovRayObject::getSphere(center, radius + thickness, crgbE1);
        std::string innerBoundary = PovRayObject::getSphere(center, radius, crgbE1);
        std::string boundarySite = PovRayObject::getDifference(outerBoundary, innerBoundary);
        std::string cellPlate = PovRayObject::getIntersection(boundarySite, cellSphere);
        std::vector<std::string> boxes; //all neighbouring cells including the big box induced by the lower bound of theta
        std::vector<std::string> boxEC2;

        boxes.push_back(povBoxAlveolusBoundaries);

        for (auto& aec1_: aec1->aec1_neighbors){
            Coordinate3D nConn = Coordinate3D({aec1_->x, aec1_->y, aec1_->z}) - posCell;;
            SphericCoordinate3D nConnect = abm::util::toSphericCoordinates(nConn);
            Coordinate3D rightUp = Coordinate3D{radiusCell, radiusCell, nConnect.r / 2.0};
            Coordinate3D lowDown = Coordinate3D{-radiusCell, -radiusCell, -radiusCell};
            boxes.push_back(PovRayObject::getBox(lowDown, rightUp, crgbE1, nConnect, posCell));
        }

        for (auto& aec2_: aec1->aec2_neighbors){

            crgbE1 = aec2_->alive ? crgbE2 = e2_alive : e2_dead;

            Coordinate3D nConn = aec2_->position - posCell;
            Coordinate3D posBox = aec2_->position;
            double lengthCell = alveoleSite.getLengthAEC2();
            SphericCoordinate3D posCellSpheric = abm::util::toSphericCoordinates(posBox);
            SphericCoordinate3D posCellSphericVec = SphericCoordinate3D{posCellSpheric.r, posCellSpheric.theta,
                                                                        posCellSpheric.phi};
            Coordinate3D rightUp = Coordinate3D{lengthCell / 2.0, lengthCell / 2.0, lengthCell / 2.0};
            Coordinate3D lowDown = Coordinate3D{-lengthCell / 2.0, -lengthCell / 2.0, -lengthCell / 2.0};
            boxEC2.push_back(PovRayObject::getBox(lowDown, rightUp, crgbE1, posCellSphericVec, posBox));
        }

        for (auto& pok_: aec1->pok_neighbors) {
            Coordinate3D nConn = pok_->position - posCell;
            Coordinate3D posPoK = pok_->position;
            double radiusPoK = alveoleSite.getRadiusPoK();
            SphericCoordinate3D sphericPosPok = abm::util::toSphericCoordinates(posPoK);
            sphericPosPok.r += thickness;
            Coordinate3D posPoK2 = abm::util::toCartesianCoordinates(sphericPosPok);
            sphericPosPok.r -= sphericPosPok.r - (thickness + 1);
            posPoK = abm::util::toCartesianCoordinates(sphericPosPok);
            std::string poreSphere = PovRayObject::getCylinder(posPoK, posPoK2, radiusPoK, crgbPoK);
            boxEC2.push_back(poreSphere);
        }
        std::string voronoiCell = PovRayObject::getIntersection(cellPlate, boxes);
        std::string voronoiCellDiffBoxes = PovRayObject::getDifference(voronoiCell, boxEC2);
        addPovObject(voronoiCellDiffBoxes);
    }

    for (auto& aec2: alveoleSite.getAECT2()) {
        double lengthCell = alveoleSite.getLengthAEC2();
        Coordinate3D posBox = aec2->position;
        SphericCoordinate3D posCellSpheric = abm::util::toSphericCoordinates(posBox);
        SphericCoordinate3D posCellSphericVec = SphericCoordinate3D{posCellSpheric.r, posCellSpheric.theta,posCellSpheric.phi};
        Coordinate3D rightUp = Coordinate3D{lengthCell / 2.0, lengthCell / 2.0, lengthCell / 2.0};
        Coordinate3D lowDown = Coordinate3D{-lengthCell / 2.0, -lengthCell / 2.0, -lengthCell / 2.0};
        std::string cellBox = PovRayObject::getBox(lowDown, rightUp, crgbE2, posCellSphericVec, posBox);
        std::string outerBoundary = PovRayObject::getSphere(center, radius + thickness, crgbE2);
        std::string innerBoundary = PovRayObject::getSphere(center, radius - 2.0, crgbE2);
        std::string boundarySite = PovRayObject::getDifference(outerBoundary, innerBoundary);
        std::string boundarySite2 = PovRayObject::getIntersection(boundarySite,
                                                                  povBoxAlveolusBoundaries);
        std::string boxPlate = PovRayObject::getIntersection(boundarySite2, cellBox);
        addPovObject(boxPlate);
    }

    for (auto& pok: alveoleSite.getPOK()) {
        double radiusPoK = alveoleSite.getRadiusPoK();
        Coordinate3D posPoK = pok->position;
        SphericCoordinate3D sphericPosPok = abm::util::toSphericCoordinates(posPoK);
        sphericPosPok.r += thickness;
        Coordinate3D posPoK2 = abm::util::toCartesianCoordinates(sphericPosPok);
        sphericPosPok.r -= (thickness + 1);
        posPoK = abm::util::toCartesianCoordinates(sphericPosPok);
        std::string poreSphere = PovRayObject::getCylinder(posPoK, posPoK2, radiusPoK, crgbPoK);
        std::string outerBoundary = PovRayObject::getSphere(center, radius + thickness, crgbPoK);
        std::string innerBoundary = PovRayObject::getSphere(center, radius, crgbPoK);
        std::string boundarySite = PovRayObject::getDifference(outerBoundary, innerBoundary);
        std::string platePoreOfKohn = PovRayObject::getIntersection(boundarySite, poreSphere);
        addPovObject(platePoreOfKohn);
    }
}

void PovFileAlveolus::transcribeParticles(Site &site) {
    AlveoleSite &alveoleSite = dynamic_cast<AlveoleSite&>(site);
    auto particles = alveoleSite.particle_manager_->getAllParticles();
    auto triangles = alveoleSite.particle_manager_->getTriangles();

//    ColorRGB col_part = ColorRGB(0, 0, 0, 0.3);
//    for (auto p: alveoleSite.particle_manager_->getAECParticles()) {
//        addPovObject(PovRayObject::getSphere(p->getPosition(), 0.5, col_part));
//    }
//    double maxx = 0.001;
//    for (auto p: alveoleSite.particle_manager_->getAECParticles()) {
//        if (sqrt(p->getConcentration()) > maxx) {
//            maxx = sqrt(p->getConcentration());
//        }
//    }
//
//
//    for (auto p: alveoleSite.particle_manager_->getAECParticles()) {
//        if (sqrt(p->getConcentration()) > 1e-4) {
//            ColorRGB col_part = ColorRGB(0, 0, 0, 1 - sqrt(p->getConcentration())/maxx);
//            addPovObject(PovRayObject::getSphere(p->getPosition(), sqrt(p->getConcentration())/maxx, col_part));
//        }
//    }

    //output of isolines
    const int nIsolines = 5;
    double isolinesConc[nIsolines] = {24.0, 12.0, 6.0, 3, 1.5};

    auto itT = triangles.begin();
    while (itT != triangles.end()) {
        TRIANGLE3D t3d = *itT;
        auto p1 = particles[t3d.neighbourIds[0]];
        auto p2 = particles[t3d.neighbourIds[1]];
        auto p3 = particles[t3d.neighbourIds[2]];

        double c1, c2, c3;
        c1 = p1->getConcentration();
        c2 = p2->getConcentration();
        c3 = p3->getConcentration();

        double minConc = std::min(std::min(c1, c2), c3);
        double maxConc = std::max(std::max(c1, c2), c3);

        Coordinate3D pointIso1 = Coordinate3D(), pointIso2 = Coordinate3D();
        for (int i = 0; i < nIsolines; i++) {

            if (minConc <= isolinesConc[i] && maxConc >= isolinesConc[i]) {

                //find the positions of isoline vertices on the triangle
                double relDist12 = (isolinesConc[i] - c1) / (c2 - c1);
                double relDist23 = (isolinesConc[i] - c2) / (c3 - c2);
                double relDist31 = (isolinesConc[i] - c3) / (c1 - c3);

                if (relDist12 < 1 && relDist12 > 0) {
                    Coordinate3D connect(p2->getPosition() - p1->getPosition());
                    connect *= relDist12;
                    pointIso1 = p1->getPosition();
                    pointIso1 += connect;
                }

                if (relDist23 < 1 && relDist23 > 0) {
                    Coordinate3D connect(p3->getPosition() - p2->getPosition());
                    connect *= relDist23;

                    if (pointIso1.x == 0 && pointIso1.y == 0 && pointIso1.z == 0) {
                        pointIso1 = p2->getPosition();
                        pointIso1 += connect;
                    } else {
                        pointIso2 = p2->getPosition();
                        pointIso2 += connect;
                    }
                }

                if (relDist31 < 1 && relDist31 > 0) {
                    Coordinate3D connect(p1->getPosition() - p3->getPosition());
                    connect *= relDist31;
                    pointIso2 = p3->getPosition();
                    pointIso2 += connect;
                }
            }

            //add to xml file
            bool isZeroIso1OrIso2 = (pointIso1.x == 0 && pointIso1.y == 0 && pointIso1.z == 0) || (pointIso2.x == 0 && pointIso2.y == 0 && pointIso2.z == 0);
            if (!isZeroIso1OrIso2) {
                ColorRGB crgb = ColorRGB(1.0, 1.0, 1.0, 0.0);
                double radius = 1.5 / (i + 1);
                addPovObject(PovRayObject::getCylinder(pointIso1, pointIso2, radius, crgb));
                addPovObject(PovRayObject::getSphere(pointIso1, radius, crgb));
                addPovObject(PovRayObject::getSphere(pointIso2, radius, crgb));
            }
            pointIso1 = Coordinate3D();
            pointIso2 = Coordinate3D();
        }
        itT++;
    }
}

void PovFileAlveolus::transcribeAgents(Site &site) {
    AlveoleSite &alveoleSite = dynamic_cast<AlveoleSite&>(site);
    Coordinate3D center = alveoleSite.getSiteCenter();
    double site_radius = alveoleSite.getRadius();
    double site_thickness = alveoleSite.getThicknessOfBorder();

    for (auto agent: *alveoleSite.getAgentManager()) {
        for (auto sphere: agent->getSurface()->getAllSpheresOfThis()) {
            auto position = sphere->getPosition();
            auto newpos = abm::util::toSphericCoordinates(position);
            SphericCoordinate3D newpos2{newpos.r - 2.0, newpos.theta, newpos.phi};
            position = abm::util::toCartesianCoordinates(newpos2);
            auto radius = sphere->getRadius();
            auto color = agent->getSurface()->getColorRGB();
            auto sphereCell = PovRayObject::getSphere(position, radius*1.01, *color);

            if (abm::util::isSubstring("ImmuneCell", agent->getTypeName())) {
                std::string alveole = PovRayObject::getSphere(center, site_radius - 2.0, *color);
                std::string smallalveole = PovRayObject::getSphere(center, site_radius - 50.0, *color);
                std::string innerCell = PovRayObject::getIntersection(sphereCell, alveole);
                addPovObject(PovRayObject::getDifference(innerCell, smallalveole));
            } else {
                addPovObject(sphereCell);
            }
        }
    }
}
