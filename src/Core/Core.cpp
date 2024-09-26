/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Core
*/

#include "Core/Core.hpp"
#include <map>
#include "Primitive/IPrimitive.hpp"
#include <libconfig.h++>

using Primitive::IPrimitive;
using std::map;
using namespace libconfig;

namespace Core
{
    Core::Core() : _camera(0, 0), _world(), _cfg()
    {
    }

    void Core::loadFromFile(const string &filepath)
    {
        (void) filepath;
        try {
            _cfg.readFile("scene.cfg");
        } catch (const libconfig::FileIOException &fioex) {
            std::cerr << "I/O error while reading file." << std::endl;
            return;
        } catch (const libconfig::ParseException &pex) {
            std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine() << " - "
                      << pex.getError() << std::endl;
            return;
        }

        _setupCamera();
        _setupPrimitives();
    }

    void Core::render(const string &filename)
    {
        (void) filename;
        _camera.render(_world);
    }

    void Core::_setupCamera()
    {
        const Setting &camera = _cfg.lookup("camera");

        int width = camera["resolution"]["width"];
        int height = camera["resolution"]["height"];

        double lookFromX = camera["lookFrom"]["x"];
        double lookFromY = camera["lookFrom"]["y"];
        double lookFromZ = camera["lookFrom"]["z"];

        double lookAtX = camera["lookAt"]["x"];
        double lookAtY = camera["lookAt"]["y"];
        double lookAtZ = camera["lookAt"]["z"];

        double vfov = camera["vfov"];
        double defocusAngle = camera["defocusAngle"];
        double focusDistance = camera["focusDistance"];

        _camera = Camera(width, height);
        _camera.setLookFrom(Vector3D(lookFromX, lookFromY, lookFromZ));
        _camera.setLookAt(Vector3D(lookAtX, lookAtY, lookAtZ));
        _camera.setVFOV(vfov);
        _camera.setFocusDistance(focusDistance);
        _camera.setDefocusAngle(defocusAngle);
    }

    void Core::_setupPrimitives()
    {
    }
} // namespace Core
