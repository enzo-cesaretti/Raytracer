/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Core
*/

#pragma once

#include <string>

#include "Primitive/World.hpp"
#include "Raytracer/Camera.hpp"
#include <libconfig.h++>

using namespace libconfig;

using Primitive::World;
using Raytracer::Camera;
using std::string;

//! Namespace for the core functionality
namespace Core
{
    //! Core class, handles the main functionality
    class Core {
        public:
            //! Default constructor
            Core();
            //! Default destructor
            ~Core() = default;

            //! Loads the scene from a file
            void loadFromFile(const string &filename);
            //! Renders the scene to a file
            void render(const string &filename);

        private:
            //! Camera of the scene
            Camera _camera;
            //! World of the scene
            World _world;
            //! Configuration of the scene
            Config _cfg;

            //! Sets up the camera
            void _setupCamera();
            //! Sets up the primitives
            void _setupPrimitives();
    };
} // namespace Core
