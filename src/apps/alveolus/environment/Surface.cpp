//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#include "Surface.h"
#include "core/utils/misc_util.h"

Surface::Surface(const std::string& type) {

    std::string surface = "sphere";

    auto sphericSurfaceGradient = [](const Coordinate3D& point) -> Coordinate3D {
        // The gradient of a point on a sphere would be just perpendicular to the surface, so vector from the origin
        auto sph_point = abm::util::toSphericCoordinates(point);
        sph_point.r = 1.0;
        auto new_point = abm::util::toCartesianCoordinates(sph_point);
        return Coordinate3D{new_point.x, new_point.y, new_point.z};
    };

    auto sphericSurfaceFunction = [](const Coordinate3D& point) -> Coordinate3D {
        // A point would be just projected on the surface of the sphere by increasing the radius
        double radius = 116.5;
        auto sph_point = abm::util::toSphericCoordinates(point);
        sph_point.r = radius;
        auto new_point = abm::util::toCartesianCoordinates(sph_point);
        return Coordinate3D{new_point.x, new_point.y, new_point.z};
    };

    auto planeSurfaceGradient = [](const Coordinate3D& point) -> Coordinate3D {
        // The gradient of the standard plane would be the vector (0, 0, 1.0)
        return Coordinate3D{0.0, 0.0, -1.0};
    };

    auto planeSurfaceFunction = [](const Coordinate3D& point) -> Coordinate3D {
        // The point of the standard plane would be the vector (x, y, 0)
        return Coordinate3D{point.x, point.y, 0.0001};
    };

    auto quadraticSurface = [](const Coordinate3D& point) -> Coordinate3D {
        double a = 0.002;
        double z = point.x * point.x + point.x * point.y + point.y * point.y + point.x + point.y;
        return Coordinate3D{point.x, point.y, a * z};
    };
    auto quadraticGradient = [](const Coordinate3D& point) -> Coordinate3D {
        double a = 0.002;
        double dx = 2 * point.x + point.y + 1.0;
        double dy = 2 * point.y + point.x + 1.0;
        return Coordinate3D{a * dx, a * dy, -1.0};
    };

    auto sincSurface = [](const Coordinate3D& point) -> Coordinate3D {
        double f = M_PI * 0.02;
        double a = 20.0;
        double z = a * sin(f * point.x);
        return Coordinate3D{point.x, point.y, z};
    };

    auto sincGradient = [](const Coordinate3D& point) -> Coordinate3D {
        double f = M_PI * 0.02;
        double a = 20.0;
        double dx = a * f * cos(f * point.x);
        return Coordinate3D{dx, 0, -1.0};
    };

    if (surface == "quadratic") {
        surface_gradient_ = quadraticGradient;
        surface_function_ = quadraticSurface;
    } else if (surface == "sinus") {
        surface_gradient_ = sincGradient;
        surface_function_ = sincSurface;
    } else if (surface == "sphere") {
        surface_gradient_ = sphericSurfaceGradient;
        surface_function_ = sphericSurfaceFunction;
    }  else {
        surface_gradient_ = planeSurfaceGradient;
        surface_function_ = planeSurfaceFunction;
    }
}

std::pair<Coordinate3D, Coordinate3D> Surface::perpendicularVectors(const Coordinate3D& point) const {
    Coordinate3D gradient = surfaceGradient(point);
    Coordinate3D tangent1, tangent2;

    if (std::abs(gradient.x) >= std::abs(gradient.y) && std::abs(gradient.x) >= std::abs(gradient.z)) {
        tangent1 = gradient.crossProduct(Coordinate3D{0, 1, 0});
        tangent1.setMagnitude(1.0);
    } else {
        gradient.crossProduct(Coordinate3D{1, 0, 0}).setMagnitude(1.0);
        tangent1.setMagnitude(1.0);
    }

    gradient.crossProduct(tangent1).setMagnitude(1.0);
    tangent2.setMagnitude(1.0);

    return std::make_pair(tangent1, tangent2);
}

Coordinate3D Surface::perpendicularVector(const Coordinate3D& point, const Coordinate3D& tangent1) const {
    Coordinate3D gradient = surfaceGradient(point);

    // Calculate the second tangent vector
    Coordinate3D tangent2 = gradient.crossProduct(tangent1);
    tangent2.setMagnitude(1.0);

    return tangent2;
}

Coordinate3D Surface::surfaceGradient(const Coordinate3D& point) const {
    if (surface_points_.empty()) {
        // Use the surface function
        return surface_gradient_(point);
    } else {
        if (surface_points_.size() < 4) {
            throw std::runtime_error("At least 4 points are required to approximate the gradient.");
        }

        // Find the closest point in the list
        size_t closest_point_index = findClosestPointIndex(surface_points_, point);

        // Calculate the gradient using the finite difference method
        Coordinate3D point_x1 = surface_points_[(closest_point_index + 1) % surface_points_.size()];
        Coordinate3D point_x2 = surface_points_[(closest_point_index + 2) % surface_points_.size()];
        Coordinate3D point_y1 = surface_points_[(closest_point_index + 3) % surface_points_.size()];

        Coordinate3D dz_dx = (point_x1 - point_x2) * (1.0 / (point_x1 - point_x2).getMagnitude());
        Coordinate3D dz_dy = (point_y1 - surface_points_[closest_point_index]) * (1.0 / (point_y1 - surface_points_[closest_point_index]).getMagnitude());

        // Combine the partial derivatives to form the gradient vector
        return Coordinate3D{dz_dx.x, dz_dy.y, -(dz_dx.x + dz_dy.y)};
    }
}

Coordinate3D Surface::surfacePoint(const Coordinate3D& point) const {
    if (surface_points_.empty()) {
        // Use the surface function
        return surface_function_(point);
    } else {
        // Find the closest point in the list
        size_t closest_point_index = findClosestPointIndex(surface_points_, point);

        // Combine the partial derivatives to form the gradient vector
        return surface_points_[closest_point_index];
    }
}


// Helper function to find the closest point in the list
size_t Surface::findClosestPointIndex(const std::vector<Coordinate3D>& points, const Coordinate3D& target) const {
    double min_distance = std::numeric_limits<double>::max();
    size_t closest_point_index = 0;

    for (size_t i = 0; i < points.size(); ++i) {
        Coordinate3D diff = points[i] - target;
        double distance = diff.getMagnitude();

        if (distance < min_distance) {
            min_distance = distance;
            closest_point_index = i;
        }
    }

    return closest_point_index;
}

// Some Surface Functions:

// Define the surface function for a sine wave surface
//double A = 1;
//double B = 1;
//double C = 0;
//double D = 1;
//double E = 0;
//
//auto sineSurfaceFunction = [A, B, C, D, E](const Coordinate3D& point) -> Coordinate3D {
//    // Compute the partial derivatives of the sine wave surface function with respect to x and y
//    double dz_dx = -A * B * sin(B * (point.x + C) + D * (point.y + E));
//    double dz_dy = -A * D * sin(B * (point.x + C) + D * (point.y + E));
//
//    // The gradient of the surface is the vector (dz_dx, dz_dy, -1)
//    return Coordinate3D(dz_dx, dz_dy, -1);
//};

// For a sphere
//double R = 5; // Sphere radius
//
//auto sphereSurfaceFunction = [R](const Coordinate3D& point) -> Coordinate3D {
//    // Compute the partial derivatives of the sphere implicit equation with respect to x, y, and z
//    double dx = 2 * point.x;
//    double dy = 2 * point.y;
//    double dz = 2 * point.z;
//
//    // The gradient of the surface is the vector (dx, dy, dz)
//    return Coordinate3D(dx, dy, dz);
//};

