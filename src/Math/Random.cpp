/*
** EPITECH PROJECT, 2024
** tests
** File description:
** Random
*/

#include "Math/Random.hpp"

namespace Math
{
    double Random::randomDouble()
    {
        return rand() / (RAND_MAX + 1.0);
    }

    double Random::randomDouble(double min, double max)
    {
        return min + (max - min) * randomDouble();
    }
} // namespace Math
