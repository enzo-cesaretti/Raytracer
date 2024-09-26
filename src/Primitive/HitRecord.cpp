/*
** EPITECH PROJECT, 2024
** tests
** File description:
** HitRecord
*/

#include "Primitive/HitRecord.hpp"

namespace Primitive
{
    void HitRecord::setFaceNormal(const Ray &ray, const Vector3D &outwardNormal)
    {
        frontFace = ray.direction().dot(outwardNormal) < 0;
        normal = frontFace ? outwardNormal : -outwardNormal;
    }
} // namespace Primitive
