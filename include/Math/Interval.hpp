/*
** EPITECH PROJECT, 2024
** tests
** File description:
** Interval
*/

#pragma once

//! Namespace for mathematical operations
namespace Math
{
    //! Interval class for handling intervals
    class Interval {
        public:
            //! Default constructor
            Interval();
            //! Constructor that takes a minimum and a maximum
            Interval(double min, double max);
            //! Default destructor
            ~Interval() = default;

            //! Returns the size of the interval
            double size() const;
            //! Checks if a value is contained in the interval
            bool contains(double value) const;
            //! Checks if a value is surrounded by the interval
            bool surround(double value) const;
            //! Clamps a value to the interval
            double clamp(double value) const;

            //! Minimum of the interval
            double min;
            //! Maximum of the interval
            double max;
    };
} // namespace Math
