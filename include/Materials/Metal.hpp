/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Metal
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
    //! Metal class, a type of material
    class Metal : public Material {
        public:
            //! Constructor that takes an albedo and a fuzz
            Metal(const Vector3D &albedo, double fuzz);
            //! Default destructor
            ~Metal() = default;

            //! Scatters a ray off the material
            bool scatter(const Ray &rayIn, const HitRecord &record, Vector3D &attenuation,
                Ray &scattered) const override;

        public:
            //! Albedo of the material
            Vector3D _albedo;
            //! Fuzz of the material
            double _fuzz;
    };
} // namespace Materials
