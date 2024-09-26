/*
** EPITECH PROJECT, 2024
** tests
** File description:
** Random
*/

#pragma once

#include <random>

//! Namespace for mathematical operations
namespace Math
{
    //! Random class for generating random numbers
    class Random {
        public:
            //! Generates a random double between 0.0 and 1.0
            static double randomDouble();
            //! Generates a random double between min and max
            static double randomDouble(double min, double max);
    };
} // namespace Math
