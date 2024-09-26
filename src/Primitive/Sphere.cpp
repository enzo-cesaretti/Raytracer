/*
** EPITECH PROJECT, 2024
** tests
** File description:
** Sphere
*/

#include "Primitive/Sphere.hpp"

using Math::Interval;

namespace Primitive
{
    Sphere::Sphere(const Point3D &center, double radius, shared_ptr<Material> material)
        : _center(center), _radius(radius), _material(material)
    {
    }

    bool Sphere::hits(const Ray &ray, Interval rayT, HitRecord &record) const
    {
        Vector3D oc = _center - ray.origin();
        double a = ray.direction().lengthSquared();
        double h = ray.direction().dot(oc);
        double c = oc.lengthSquared() - pow(_radius, 2);
        double delta = pow(h, 2) - a * c;
        if (delta < 0)
            return false;
        double sqrtd = sqrt(delta);
        double root = (h - sqrtd) / a;
        if (!rayT.surround(root)) {
            root = (h + sqrtd) / a;
            if (!rayT.surround(root))
                return false;
        }
        record.t = root;
        record.p = ray.at(record.t);
        Vector3D outwardNormal = (record.p - _center) / _radius;
        record.setFaceNormal(ray, outwardNormal);
        record.material = _material;
        return true;
    };
} // namespace Primitive
