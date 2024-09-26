/*
** EPITECH PROJECT, 2024
** tests
** File description:
** Interval
*/

#include "Math/Interval.hpp"
#include "Math/Constants.hpp"

namespace Math
{

    Interval::Interval() : min(+infinity), max(-infinity)
    {
    }

    Interval::Interval(double min, double max) : min(min), max(max)
    {
    }

    double Interval::size() const
    {
        return (max - min);
    }

    bool Interval::contains(double value) const
    {
        return (value >= min && value <= max);
    }

    bool Interval::surround(double value) const
    {
        return (value > min && value < max);
    }

    double Interval::clamp(double x) const
    {
        if (x < min)
            return min;
        if (x > max)
            return max;
        return x;
    }
} // namespace Math
