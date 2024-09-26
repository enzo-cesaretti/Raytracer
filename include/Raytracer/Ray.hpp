/*
** EPITECH PROJECT, 2024
** tests
** File description:
** Ray
*/

#pragma once

#include "Vector.hpp"

using Math::Point3D, Math::Vector3D;

//! Namespace for ray tracing operations
namespace Raytracer
{
    //! Ray class for ray tracing
    class Ray {
        public:
            //! Default constructor
            Ray();
            //! Constructor that takes an origin and a direction
            Ray(const Point3D &origin, const Vector3D &direction);
            //! Default destructor
            ~Ray() = default;

            //! Returns the origin of the ray
            Point3D origin() const;
            //! Returns the direction of the ray
            Vector3D direction() const;

            //! Returns a point at a distance t along the ray
            Point3D at(double t) const;

        private:
            //! Origin of the ray
            Point3D _origin;
            //! Direction of the ray
            Vector3D _direction;
    };
} // namespace Raytracer
