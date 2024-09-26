/*
** EPITECH PROJECT, 2024
** tests
** File description:
** Ray
*/

#include "Raytracer/Ray.hpp"

namespace Raytracer
{

    Ray::Ray()
    {
    }

    Ray::Ray(const Point3D &origin, const Vector3D &direction)
        : _origin(origin), _direction(direction)
    {
    }

    Point3D Ray::origin() const
    {
        return _origin;
    }

    Vector3D Ray::direction() const
    {
        return _direction;
    }

    Point3D Ray::at(double t) const
    {
        return _origin + _direction * t;
    }
} // namespace Raytracer
