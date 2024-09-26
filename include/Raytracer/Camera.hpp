/*
** EPITECH PROJECT, 2024
** tests
** File description:
** Camera
*/

#pragma once

#include "Color.hpp"
#include "File.hpp"
#include "Primitive/World.hpp"
#include "Raytracer/Ray.hpp"
#include "Vector.hpp"

using Primitive::World;
using Raytracer::Ray;

//! Namespace for ray tracing operations
namespace Raytracer
{
    //! Camera class for ray tracing
    class Camera {
        public:
            //! Constructor that takes width and height
            Camera(const int width, const int height);
            //! Default destructor
            ~Camera() = default;

            //! Sets the look from point
            void setLookFrom(const Vector3D &lookFrom);
            //! Sets the look at point
            void setLookAt(const Vector3D &lookAt);
            //! Sets the view up vector
            void setViewUp(const Vector3D &viewUp);
            //! Sets the vertical field of view
            void setVFOV(const double fov);
            //! Sets the defocus angle
            void setDefocusAngle(const double defocusAngle);
            //! Sets the focus distance
            void setFocusDistance(const double focusDistance);

            //! Renders the world
            void render(const World &world);

        private:
            //! Initializes the camera
            void _init();
            //! Returns a ray from the camera through the pixel at (x, y)
            Ray _getRay(const int x, const int y) const;
            //! Returns the color of a ray
            Color _rayColor(const Ray &ray, int depth, const World &world) const;
            //! Samples a square
            Vector3D _sampleSquare() const;
            //! Samples a defocus disk
            Point3D _defocusDiskSample() const;

            //! Width of the camera
            int _width;
            //! Height of the camera
            int _height;
            //! Number of samples per pixel
            int _samplesPerPixel;

            //! Vertical field of view
            double _vfov;
            //! Look from point
            Vector3D _lookFrom;
            //! Look at point
            Vector3D _lookAt;
            //! View up vector
            Vector3D _viewUp;

            //! Defocus angle
            double _defocusAngle;
            //! Focus distance
            double _focusDistance;

            //! U vector of the defocus disk
            Vector3D _defocusDiskU;
            //! V vector of the defocus disk
            Vector3D _defocusDiskV;

            //! Scale of the pixel samples
            double _pixelSamplesScale;
            //! Origin of the camera
            Point3D _origin;
            //! Location of the pixel
            Point3D _pixelLocation;
            //! Delta U of the pixel
            Vector3D _pixelDeltaU;
            //! Delta V of the pixel
            Vector3D _pixelDeltaV;
            //! U vector of the camera
            Vector3D _u;
            //! V vector of the camera
            Vector3D _v;
            //! W vector of the camera
            Vector3D _w;
    };
} // namespace Raytracer
