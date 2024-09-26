/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Lambertian
*/

#include "Materials/Lambertian.hpp"

namespace Materials
{
    Lambertian::Lambertian(const Color &albedo) : _albedo(albedo)
    {
    }

    bool Lambertian::scatter(
        const Ray &rIn, const HitRecord &record, Color &attenuation, Ray &scattered) const
    {
        (void) rIn;
        Vector3D scatterDirection = record.normal + Vector3D::randomUnitVector();
        if (scatterDirection.nearZero())
            scatterDirection = record.normal;
        scattered = Ray(record.p, scatterDirection);
        attenuation = _albedo;
        return true;
    }
} // namespace Materials
