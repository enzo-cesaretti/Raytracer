/*
** EPITECH PROJECT, 2024
** tests
** File description:
** IPrimitive
*/

#pragma once

#include "Math/Interval.hpp"
#include "Primitive/HitRecord.hpp"

using Math::Interval;

//! Namespace for primitive objects
namespace Primitive
{
    //! IPrimitive interface, base class for all primitive objects
    class IPrimitive {
        public:
            //! Default destructor
            virtual ~IPrimitive() = default;

            //! Pure virtual function for checking if a ray hits the primitive object
            virtual bool hits(const Ray &ray, Interval rayT, HitRecord &rec) const = 0;
    };
} // namespace Primitive
