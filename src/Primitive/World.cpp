/*
** EPITECH PROJECT, 2024
** tests
** File description:
** World
*/

#include "Primitive/World.hpp"

namespace Primitive
{

    World::World()
    {
    }

    World::World(std::shared_ptr<IPrimitive> object)
    {
        add(object);
    }

    void World::clear()
    {
        objects.clear();
    }

    void World::add(std::shared_ptr<IPrimitive> object)
    {
        objects.push_back(object);
    }

    bool World::hits(const Ray &ray, Interval rayT, HitRecord &record) const
    {
        HitRecord tempRec;
        bool hitAnything = false;
        double closestSoFar = rayT.max;

        for (const auto &object : objects) {
            if (object->hits(ray, Interval(rayT.min, closestSoFar), tempRec)) {
                hitAnything = true;
                closestSoFar = tempRec.t;
                record = tempRec;
            }
        }
        return hitAnything;
    }
} // namespace Primitive
