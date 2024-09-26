/*
** EPITECH PROJECT, 2024
** tests
** File description:
** Vector3D
*/

#pragma once

#include <cmath>
#include <iostream>

using std::sqrt;

//! Namespace for mathematical operations
namespace Math
{
    //! 3D Vector class
    class Vector3D {
        public:
            //! Default constructor
            Vector3D();
            //! Constructor with x, y and z values
            Vector3D(double x, double y, double z);

            //! Negation operator
            Vector3D operator-() const;

            //! Addition operator with another vector
            Vector3D operator+(const Vector3D &v) const;
            //! Subtraction operator with another vector
            Vector3D operator-(const Vector3D &v) const;
            //! Multiplication operator with another vector
            Vector3D operator*(const Vector3D &v) const;
            //! Division operator with another vector
            Vector3D operator/(const Vector3D &v) const;

            //! Addition operator with a scalar
            Vector3D operator+(double t) const;
            //! Subtraction operator with a scalar
            Vector3D operator-(double t) const;
            //! Multiplication operator with a scalar
            Vector3D operator*(double t) const;
            //! Division operator with a scalar
            Vector3D operator/(double t) const;

            //! Addition assignment operator with another vector
            Vector3D &operator+=(Vector3D &v);
            //! Subtraction assignment operator with another vector
            Vector3D &operator-=(Vector3D &v);
            //! Multiplication assignment operator with another vector
            Vector3D &operator*=(Vector3D &v);
            //! Division assignment operator with another vector
            Vector3D &operator/=(Vector3D &v);

            //! Addition assignment operator with a scalar
            Vector3D &operator+=(double t);
            //! Subtraction assignment operator with a scalar
            Vector3D &operator-=(double t);
            //! Multiplication assignment operator with a scalar
            Vector3D &operator*=(double t);
            //! Division assignment operator with a scalar
            Vector3D &operator/=(double t);

            //! Returns the length of the vector
            double length() const;
            //! Returns the squared length of the vector
            double lengthSquared() const;
            //! Checks if the vector is near zero
            double nearZero() const;

            //! Calculates the dot product with another vector
            double dot(const Vector3D &v) const;
            //! Calculates the cross product with another vector
            Vector3D cross(const Vector3D &v) const;
            //! Reflects the vector against a normal
            Vector3D reflect(const Vector3D &normal) const;
            //! Refracts the vector with a normal and a ratio of indices of refraction
            Vector3D refract(const Vector3D &normal, double etaiOverEtat) const;

            //! Returns a unit vector in the same direction as this vector
            Vector3D unitVector() const;

            //! Returns a random vector
            static Vector3D random();
            //! Returns a random vector with values between min and max
            static Vector3D random(double min, double max);

            //! Returns a random vector in a unit sphere
            static Vector3D randomInUnitSphere();
            //! Returns a random unit vector
            static Vector3D randomUnitVector();
            //! Returns a random vector on a hemisphere with a given normal
            static Vector3D randomOnHemisphere(const Vector3D &normal);
            //! Returns a random vector in a unit disk
            static Vector3D randomInUnitDisk();

            //! x component of the vector
            double x;
            //! y component of the vector
            double y;
            //! z component of the vector
            double z;
    };

    //! 3D Point class
    using Point3D = Vector3D;
} // namespace Math

using Math::Vector3D;

//! Output operator for Vector3D
std::ostream &operator<<(std::ostream &out, const Vector3D &v);