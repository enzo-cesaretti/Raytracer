/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Lambertian
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
    //! Lambertian class, a type of material
    class Lambertian : public Material {
        public:
            //! Constructor that takes an albedo
            Lambertian(const Color &albedo);
            //! Default destructor
            ~Lambertian() = default;

            //! Scatters a ray off the material
            bool scatter(const Ray &rIn, const HitRecord &record, Color &attenuation,
                Ray &scattered) const override;

        private:
            //! Albedo of the material
            Color _albedo;
    };
} // namespace Materials
