/*
** EPITECH PROJECT, 2024
** tests
** File description:
** HitRecord
*/

#pragma once

#include <memory>
#include "Materials/Material.hpp"
#include "Raytracer/Ray.hpp"

using Raytracer::Ray;
using std::shared_ptr;

using Materials::Material;

//! Namespace for primitive objects
namespace Primitive
{
    //! HitRecord class, used to record information about ray hits
    class HitRecord {
        public:
            //! Point of intersection
            Point3D p;
            //! Normal at the point of intersection
            Vector3D normal;
            //! Parameter t of the ray equation
            double t;
            //! Boolean indicating if the intersection is on the front face
            bool frontFace;
            //! Material of the intersected object
            shared_ptr<Material> material;

            //! Sets the normal and the front face based on the ray direction
            void setFaceNormal(const Ray &ray, const Vector3D &outwardNormal);
    };
} // namespace Primitive
