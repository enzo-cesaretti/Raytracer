/*
** EPITECH PROJECT, 2024
** tests
** File description:
** Math
*/

#include "Math/Utils.hpp"
#include "Math/Constants.hpp"

namespace Math
{
    double Utils::degreesToRadians(double degrees)
    {
        return degrees * pi / 180.0;
    }

    double Utils::linearToGamma(double linear)
    {
        if (linear > 0)
            return sqrt(linear);
        return 0;
    }
} // namespace Math
