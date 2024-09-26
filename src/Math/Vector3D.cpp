/*
** EPITECH PROJECT, 2024
** tests
** File description:
** Vector3D
*/

#include "Math/Constants.hpp"
#include "Math/Random.hpp"
#include "Vector.hpp"

using Math::Random;

namespace Math
{
    Vector3D::Vector3D() : x(0), y(0), z(0)
    {
    }

    Vector3D::Vector3D(double x, double y, double z) : x(x), y(y), z(z)
    {
    }

    Vector3D Vector3D::operator-() const
    {
        return Vector3D(-x, -y, -z);
    }

    Vector3D Vector3D::operator+(const Vector3D &v) const
    {
        return Vector3D(x + v.x, y + v.y, z + v.z);
    }

    Vector3D Vector3D::operator-(const Vector3D &v) const
    {
        return Vector3D(x - v.x, y - v.y, z - v.z);
    }

    Vector3D Vector3D::operator*(const Vector3D &v) const
    {
        return Vector3D(x * v.x, y * v.y, z * v.z);
    }

    Vector3D Vector3D::operator/(const Vector3D &v) const
    {
        return Vector3D(x / v.x, y / v.y, z / v.z);
    }

    Vector3D Vector3D::operator+(double t) const
    {
        return Vector3D(x + t, y + t, z + t);
    }

    Vector3D Vector3D::operator-(double t) const
    {
        return Vector3D(x - t, y - t, z - t);
    }

    Vector3D Vector3D::operator*(double t) const
    {
        return Vector3D(x * t, y * t, z * t);
    }

    Vector3D Vector3D::operator/(double t) const
    {
        return Vector3D(x / t, y / t, z / t);
    }

    Vector3D &Vector3D::operator+=(Vector3D &v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    Vector3D &Vector3D::operator-=(Vector3D &v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

    Vector3D &Vector3D::operator*=(Vector3D &v)
    {
        x *= v.x;
        y *= v.y;
        z *= v.z;
        return *this;
    }

    Vector3D &Vector3D::operator/=(Vector3D &v)
    {
        x /= v.x;
        y /= v.y;
        z /= v.z;
        return *this;
    }

    Vector3D &Vector3D::operator+=(double t)
    {
        x += t;
        y += t;
        z += t;
        return *this;
    }

    Vector3D &Vector3D::operator-=(double t)
    {
        x -= t;
        y -= t;
        z -= t;
        return *this;
    }

    Vector3D &Vector3D::operator*=(double t)
    {
        x *= t;
        y *= t;
        z *= t;
        return *this;
    }

    Vector3D &Vector3D::operator/=(double t)
    {
        x /= t;
        y /= t;
        z /= t;
        return *this;
    }

    double Vector3D::length() const
    {
        return sqrt(lengthSquared());
    }

    double Vector3D::lengthSquared() const
    {
        return x * x + y * y + z * z;
    }

    double Vector3D::nearZero() const
    {
        const double s = 1e-8;
        return (std::fabs(x) < s) && (std::fabs(y) < s) && (std::fabs(z) < s);
    }

    double Vector3D::dot(const Vector3D &v) const
    {
        return x * v.x + y * v.y + z * v.z;
    }

    Vector3D Vector3D::cross(const Vector3D &v) const
    {
        return Vector3D(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
    }

    Vector3D Vector3D::reflect(const Vector3D &normal) const
    {
        return *this - normal * this->dot(normal) * 2;
    }

    Vector3D Vector3D::refract(const Vector3D &normal, double etaiOverEtat) const
    {
        double cosTheta = fmin(-this->dot(normal), 1.0);
        Vector3D rOutPerp = (*this + normal * cosTheta) * etaiOverEtat;
        Vector3D rOutParallel = normal * -sqrt(fabs(1.0 - rOutPerp.lengthSquared()));
        return rOutPerp + rOutParallel;
    }

    Vector3D Vector3D::unitVector() const
    {
        return *this / length();
    }

    Vector3D Vector3D::random()
    {
        return Vector3D(Random::randomDouble(), Random::randomDouble(), Random::randomDouble());
    }

    Vector3D Vector3D::random(double min, double max)
    {
        return Vector3D(Random::randomDouble(min, max), Random::randomDouble(min, max),
            Random::randomDouble(min, max));
    }

    Vector3D Vector3D::randomInUnitSphere()
    {
        while (true) {
            Vector3D p = Vector3D::random(-1, 1);
            if (p.lengthSquared() < 1)
                return p;
        }
    }

    Vector3D Vector3D::randomUnitVector()
    {
        return randomInUnitSphere().unitVector();
    }

    Vector3D Vector3D::randomOnHemisphere(const Vector3D &normal)
    {
        Vector3D onUnitSphere = randomUnitVector();
        if (onUnitSphere.dot(normal) > 0.0)
            return onUnitSphere;
        return -onUnitSphere;
    }

    Vector3D Vector3D::randomInUnitDisk()
    {
        while (true) {
            Vector3D p = Vector3D(Random::randomDouble(-1, 1), Random::randomDouble(-1, 1), 0);
            if (p.lengthSquared() < 1)
                return p;
        }
    }
} // namespace Math

std::ostream &operator<<(std::ostream &out, const Vector3D &v)
{
    return out << v.x << ' ' << v.y << ' ' << v.z;
}
