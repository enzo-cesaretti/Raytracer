/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Dielectric
*/

#pragma once

#include "Color.hpp"
#include "Materials/Material.hpp"
#include "Primitive/HitRecord.hpp"
#include "Raytracer/Ray.hpp"

using Primitive::HitRecord;
using Raytracer::Ray;

//! Namespace for materials
namespace Materials
{
    //! Dielectric class, a type of material
    class Dielectric : public Material {
        public:
            //! Constructor that takes a refractive index
            Dielectric(double ri);
            //! Default destructor
            ~Dielectric() = default;

            //! Scatters a ray off the material
            bool scatter(const Ray &rIn, const HitRecord &record, Color &attenuation,
                Ray &scattered) const;

        private:
            //! Refractive index of the material
            double _ri;

            //! Calculates the reflectance of the material
            double _reflectance(double cosine, double ri) const;
    };
} // namespace Materials
