/*
** EPITECH PROJECT, 2024
** tests
** File description:
** main
*/

#include <iostream>
#include <memory>

#include "Color.hpp"
#include "Math/Constants.hpp"

#include "Primitive/HitRecord.hpp"
#include "Primitive/Sphere.hpp"
#include "Primitive/World.hpp"

#include "Core/Core.hpp"
#include "Raytracer/Camera.hpp"

#include "Materials/Dielectric.hpp"
#include "Materials/Lambertian.hpp"
#include "Materials/Metal.hpp"

using Primitive::Sphere;
using Raytracer::Camera;
using std::make_shared;

using Materials::Dielectric;
using Materials::Lambertian;
using Materials::Metal;

int main(int argc, char** argv)
{

    if (argc > 1 && (std::string(argv[1]) == "--help" || std::string(argv[1]) == "-h")) {
        printf("USAGE: ./raytracer <SCENE_FILE>\n  SCENE_FILE: scene configuration\n");
        return 0;
    }

    World world;

    auto materialGround = make_shared<Lambertian>(Color(0.8, 0.8, 0.0));
    auto materialCenter = make_shared<Lambertian>(Color(0.1, 0.2, 0.5));
    auto materialLeft = make_shared<Dielectric>(1.50);
    auto materialBubble = make_shared<Dielectric>(1.00 / 1.50);
    auto materialRight = make_shared<Metal>(Color(0.8, 0.6, 0.2), 1.0);

    world.add(make_shared<Sphere>(Point3D(0.0, -100.5, -1.0), 100.0, materialGround));
    world.add(make_shared<Sphere>(Point3D(0.0, 0.0, -1.2), 0.5, materialCenter));
    world.add(make_shared<Sphere>(Point3D(-1.0, 0.0, -1.0), 0.5, materialLeft));
    world.add(make_shared<Sphere>(Point3D(-1.0, 0.0, -1.0), 0.4, materialBubble));
    world.add(make_shared<Sphere>(Point3D(1.0, 0.0, -1.0), 0.5, materialRight));

    Camera cam(600, 400);
    cam.setLookFrom(Point3D(-2, 2, 1));
    cam.setLookAt(Point3D(0, 0, -1));
    cam.setViewUp(Vector3D(0, 1, 0));
    cam.setVFOV(60.0);
    cam.setDefocusAngle(0.0);
    cam.setFocusDistance(3.4);

    cam.render(world);
    return 0;
}
