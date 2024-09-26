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

double random_double() {
    return rand() / (RAND_MAX + 1.0);
}

int main(int argc, char** argv)
{

    if (argc > 1 && (std::string(argv[1]) == "--help" || std::string(argv[1]) == "-h")) {
        printf("USAGE: ./raytracer <SCENE_FILE>\n  SCENE_FILE: scene configuration\n");
        return 0;
    }

    World world;

    auto material1 = make_shared<Lambertian>(Color(0.8, 0.3, 0.3));
    auto material2 = make_shared<Metal>(Color(0.8, 0.8, 0.8), 0.3);
    auto material3 = make_shared<Dielectric>(1.5);
    auto material4 = make_shared<Lambertian>(Color(0.8, 0.8, 0.0));
    auto material5 = make_shared<Metal>(Color(0.8, 0.6, 0.2), 1.0);

    for (int a = -11; a < 11; a++) {
        for (int b = -11; b < 11; b++) {
            double choose_mat = random_double();
            Point3D center(a + 0.9*random_double(), 0.2, b + 0.9*random_double());

            if ((center - Point3D(4, 0.2, 0)).length() > 0.9) {
                if (choose_mat < 0.8) {
                    world.add(make_shared<Sphere>(center, 0.2, material1));
                } else if (choose_mat < 0.95) {
                    world.add(make_shared<Sphere>(center, 0.2, material2));
                } else {
                    world.add(make_shared<Sphere>(center, 0.2, material3));
                }
            }
        }
    }

    Camera cam(1200, 800);
    cam.setLookFrom(Point3D(13, 2, 3));
    cam.setLookAt(Point3D(0, 0, 0));
    cam.setViewUp(Vector3D(0, 1, 0));
    cam.setVFOV(20.0);
    cam.setDefocusAngle(0.0);
    cam.setFocusDistance(10.0);

    cam.render(world);
    return 0;
}