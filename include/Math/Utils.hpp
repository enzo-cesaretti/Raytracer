/*
** EPITECH PROJECT, 2024
** tests
** File description:
** Utils
*/

#pragma once

//! Namespace for mathematical operations
namespace Math
{
    //! Utils class for mathematical utilities
    class Utils {
        public:
            //! Converts degrees to radians
            static double degreesToRadians(double degrees);
            //! Converts linear values to gamma values
            static double linearToGamma(double linear);
    };
} // namespace Math
