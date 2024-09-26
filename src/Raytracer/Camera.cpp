/*
** EPITECH PROJECT, 2024
** tests
** File description:
** Camera
*/

#include "Raytracer/Camera.hpp"
#include "Math/Constants.hpp"
#include "Math/Interval.hpp"
#include "Math/Random.hpp"
#include "Math/Utils.hpp"
#include "Primitive/World.hpp"
#include "Vector.hpp"

using Math::Random;
using Math::Utils;

namespace Raytracer
{

    Camera::Camera(const int width, const int height)
        : _width(width), _height(height), _vfov(90.0), _lookFrom(0, 0, 0), _lookAt(0, 0, -1),
          _viewUp(0, 1, 0), _defocusAngle(0), _focusDistance(0)
    {
    }

    void Camera::setLookFrom(const Vector3D &lookFrom)
    {
        _lookFrom = lookFrom;
    }

    void Camera::setLookAt(const Vector3D &lookAt)
    {
        _lookAt = lookAt;
    }

    void Camera::setViewUp(const Vector3D &viewUp)
    {
        _viewUp = viewUp;
    }

    void Camera::setVFOV(const double fov)
    {
        _vfov = fov;
    }

    void Camera::setDefocusAngle(const double defocusAngle)
    {
        _defocusAngle = defocusAngle;
    }

    void Camera::setFocusDistance(const double focusDistance)
    {
        _focusDistance = focusDistance;
    }

    void Camera::render(const World &world)
    {
        File::File file("output.ppm");
        file.getStream() << "P3\n" << _width << ' ' << _height << "\n255\n";

        _init();
        for (int y = 0; y < _height; y++) {
            std::clog << "\rScanlines remaining: " << (_height - y) << ' ' << std::flush;
            for (int x = 0; x < _width; x++) {
                Color pixelColor(0, 0, 0);
                for (int sample = 0; sample < _samplesPerPixel; sample++) {
                    Ray r = _getRay(x, y);
                    pixelColor = pixelColor + _rayColor(r, 50, world);
                }
                file.writeColor(pixelColor * _pixelSamplesScale);
            }
        }
        std::clog << "\rDone.                 \n";
    }

    void Camera::_init()
    {
        _samplesPerPixel = 100;
        _pixelSamplesScale = 1.0 / _samplesPerPixel;

        _origin = _lookFrom;

        // double focalLength = (_lookFrom - _lookAt).length();
        double theta = Utils::degreesToRadians(_vfov);
        double h = tan(theta / 2.0);
        double veiwportHeight = 2 * h * _focusDistance;
        double viewportWidth = veiwportHeight * (double(_width) / _height);

        Vector3D _viewportU(viewportWidth, 0, 0);
        Vector3D _viewportV(0, -veiwportHeight, 0);

        _w = (_lookFrom - _lookAt).unitVector();
        _u = _viewUp.cross(_w).unitVector();
        _v = _w.cross(_u);

        _viewportU = _u * viewportWidth;
        _viewportV = -_v * veiwportHeight;

        _pixelDeltaU = _viewportU / double(_width);
        _pixelDeltaV = _viewportV / double(_height);

        Vector3D viewportUpperLeft =
            _origin - (_w * _focusDistance) - _viewportU / 2 - _viewportV / 2;
        _pixelLocation = viewportUpperLeft + (_pixelDeltaU + _pixelDeltaV) * 0.5;

        double defocusRadius = _focusDistance * tan(Utils::degreesToRadians(_defocusAngle / 2));
        _defocusDiskU = _u * defocusRadius;
        _defocusDiskV = _v * defocusRadius;
    }

    Ray Camera::_getRay(int x, int y) const
    {
        Vector3D offset = _sampleSquare();
        Vector3D pixelSample =
            _pixelLocation + (_pixelDeltaU * (x + offset.x)) + (_pixelDeltaV * (y + offset.y));
        Point3D rayOrigin = (_defocusAngle <= 0) ? _origin : _defocusDiskSample();
        Vector3D rayDirection = pixelSample - rayOrigin;
        return Ray(rayOrigin, rayDirection);
    }

    Vector3D Camera::_sampleSquare() const
    {
        return Vector3D(Random::randomDouble() - 0.5, Random::randomDouble() - 0.5, 0);
    }

    Point3D Camera::_defocusDiskSample() const
    {
        Point3D p = Vector3D::randomInUnitDisk();
        return _origin + (_defocusDiskU * p.x) + (_defocusDiskV * p.y);
    }

    Color Camera::_rayColor(const Ray &r, int depth, const World &world) const
    {
        if (depth <= 0)
            return Color(0, 0, 0);

        HitRecord record;
        if (world.hits(r, Interval(0.0001, Math::infinity), record)) {
            Ray scattered;
            Color attenuation;
            if (record.material->scatter(r, record, attenuation, scattered))
                return attenuation * _rayColor(scattered, depth - 1, world);
            return Color(0, 0, 0);
        }

        Vector3D unitDirection = r.direction().unitVector();
        double a = 0.5 * (unitDirection.y + 1.0);
        return Color(1.0, 1.0, 1.0) * (1.0 - a) + Color(0.5, 0.7, 1.0) * a;
    }
} // namespace Raytracer
