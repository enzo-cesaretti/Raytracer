/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Material
*/

#include "Materials/Material.hpp"

namespace Materials
{
    bool Material::scatter(
        const Ray &r_in, const HitRecord &record, Color &attenuation, Ray &scattered) const
    {
        (void) r_in;
        (void) record;
        (void) attenuation;
        (void) scattered;
        return false;
    }
} // namespace Materials
