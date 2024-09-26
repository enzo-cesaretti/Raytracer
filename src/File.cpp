/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** File
*/

#include "File.hpp"

#include "Math/Interval.hpp"
#include "Math/Utils.hpp"

using Math::Utils;

namespace File
{
    File::File(const std::string &filename)
    {
        _file.open(filename);
    }

    File::~File()
    {
        _file.close();
    }

    ofstream &File::getStream()
    {
        return _file;
    }

    void File::writeColor(const Color &pixelColor)
    {
        double r = Utils::linearToGamma(pixelColor.x);
        double g = Utils::linearToGamma(pixelColor.y);
        double b = Utils::linearToGamma(pixelColor.z);

        static const Math::Interval intensity(0.000, 0.999);
        int rbyte = int(256 * intensity.clamp(r));
        int gbyte = int(256 * intensity.clamp(g));
        int bbyte = int(256 * intensity.clamp(b));

        _file << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
    }
} // namespace File
