/*
** EPITECH PROJECT, 2024
** tests
** File description:
** World
*/

#pragma once

#include <memory>
#include <vector>
#include "HitRecord.hpp"
#include "IPrimitive.hpp"
#include "Vector.hpp"

using Primitive::HitRecord;

//! Namespace for primitive objects
namespace Primitive
{
    //! World class for handling multiple primitive objects
    class World {
        public:
            //! Default constructor
            World();
            //! Constructor that takes a primitive object
            World(std::shared_ptr<IPrimitive> object);
            //! Default destructor
            ~World() = default;

            //! Clears all objects from the world
            void clear();
            //! Adds a primitive object to the world
            void add(std::shared_ptr<IPrimitive> object);

            //! Checks if a ray hits any object in the world
            bool hits(const Ray &ray, Interval rayT, HitRecord &rec) const;

        private:
            //! Vector of primitive objects
            std::vector<std::shared_ptr<IPrimitive>> objects;
    };
} // namespace Primitive
