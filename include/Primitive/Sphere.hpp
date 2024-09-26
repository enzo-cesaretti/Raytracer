/*
** EPITECH PROJECT, 2024
** tests
** File description:
** Sphere
*/

#pragma once

#include <memory>
#include "Materials/Material.hpp"
#include "Primitive/IPrimitive.hpp"
#include "Vector.hpp"

using Materials::Material;
using std::shared_ptr;

//! Namespace for primitive objects
namespace Primitive
{
    //! Sphere class, a primitive object for ray tracing
    class Sphere : public IPrimitive {
        public:
            //! Constructor that takes a center, a radius and a material
            Sphere(const Point3D &center, double radius, shared_ptr<Material> material);
            //! Default destructor
            ~Sphere() = default;

            //! Checks if a ray hits the sphere
            bool hits(const Ray &ray, Interval rayT, HitRecord &rec) const;

        private:
            //! Center of the sphere
            Point3D _center;
            //! Radius of the sphere
            double _radius;
            //! Material of the sphere
            shared_ptr<Material> _material;
    };
} // namespace Primitive