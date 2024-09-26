/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** File
*/

#pragma once

#include <fstream>
#include <string>
#include "Color.hpp"

using std::ofstream;
using std::string;

//! Namespace for file operations
namespace File
{
    //! File class for handling file operations
    class File {
        public:
            //! Constructor that takes a filename, default is "output.ppm"
            File(const string &filename = "output.ppm");
            //! Destructor
            ~File();

            //! Returns the file stream
            ofstream &getStream();
            //! Writes a color to the file
            void writeColor(const Color &pixelColor);

        private:
            //! File stream
            ofstream _file;
    };
} // namespace File