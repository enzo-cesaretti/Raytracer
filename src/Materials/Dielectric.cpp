/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Dielectric
*/

#include "Materials/Dielectric.hpp"
#include "Math/Random.hpp"

using Math::Random;

namespace Materials
{
    Dielectric::Dielectric(double ri) : _ri(ri)
    {
    }

    bool Dielectric::scatter(const Ray &rIn, const Primitive::HitRecord &record,
        Color &attenuation, Ray &scattered) const
    {
        attenuation = Color(1.0, 1.0, 1.0);
        double ri = record.frontFace ? (1.0 / _ri) : _ri;

        Vector3D unitDirection = rIn.direction().unitVector();
        double cosTheta = std::fmin((-unitDirection).dot(record.normal), 1.0);
        double sinTheta = std::sqrt(1.0 - cosTheta * cosTheta);

        bool cannotRefract = ri * sinTheta > 1.0;
        Vector3D direction = (cannotRefract || _reflectance(cosTheta, ri) > Random::randomDouble())
            ? unitDirection.reflect(record.normal)
            : unitDirection.refract(record.normal, ri);

        scattered = Ray(record.p, direction);
        return true;
    }

    double Dielectric::_reflectance(double cosine, double ri) const
    {
        double r0 = (1 - ri) / (1 + ri);
        r0 = pow(r0, 2);
        return r0 + (1 - r0) * pow((1 - cosine), 5);
    }
} // namespace Materials
