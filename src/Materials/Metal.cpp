/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Metal
*/

#include "Materials/Metal.hpp"

namespace Materials
{
    Metal::Metal(const Vector3D &albedo, double fuzz) : _albedo(albedo), _fuzz(fuzz < 1 ? fuzz : 1)
    {
    }

    bool Metal::scatter(
        const Ray &rIn, const HitRecord &record, Vector3D &attenuation, Ray &scattered) const
    {
        Vector3D reflected = rIn.direction().reflect(record.normal);
        reflected = reflected.unitVector() + (Vector3D::randomUnitVector() * _fuzz);
        scattered = Ray(record.p, reflected);
        attenuation = _albedo;
        return scattered.direction().dot(record.normal) > 0;
    }
} // namespace Materials
