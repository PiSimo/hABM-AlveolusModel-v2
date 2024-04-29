//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#ifndef COREABM_SURFACE_H
#define COREABM_SURFACE_H

#include <vector>
#include "core/basic/Coordinate3D.h"
#include <cmath>
#include <functional>

class Surface {
public:
    Surface(const std::string& type="");

    std::pair<Coordinate3D, Coordinate3D> perpendicularVectors(const Coordinate3D& point) const;

    Coordinate3D perpendicularVector(const Coordinate3D& point, const Coordinate3D& tangent1) const;

    Coordinate3D surfacePoint(const Coordinate3D& point) const;

    Coordinate3D surfaceGradient(const Coordinate3D& point) const;

    size_t findClosestPointIndex(const std::vector<Coordinate3D>& points, const Coordinate3D& target) const;

private:
    std::vector<Coordinate3D> surface_points_;
    std::function<Coordinate3D(const Coordinate3D&)> surface_function_;
    std::function<Coordinate3D(const Coordinate3D&)> surface_gradient_;
};


#endif //COREABM_SURFACE_H
