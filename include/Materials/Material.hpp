/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Material
*/

#pragma once

#include "Color.hpp"
#include "Raytracer/Ray.hpp"

using Raytracer::Ray;

namespace Primitive
{
    class HitRecord;
}

using Primitive::HitRecord;

//! Namespace for materials
namespace Materials
{
    //! Material class, base class for all materials
    class Material {
        public:
            //! Default constructor
            Material() = default;
            //! Default destructor
            virtual ~Material() = default;

            //! Virtual function for scattering a ray off the material
            virtual bool scatter(const Ray &r_in, const HitRecord &record, Color &attenuation,
                Ray &scattered) const = 0;
    };
} // namespace Materials
