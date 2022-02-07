#include "scene.h"
#include <math.h>

Scene::Scene(std::vector<SceneObj*>& objects, std::vector<Light*>& lights) :ambientCoeff{0.05} {
	this->objects = objects;
	this->lights = lights;
}

Pixel Scene::render(Ray& ray) {
    Intersection closest = Intersection();
    Intersection hit;

    for (SceneObj* obj : objects) {
        hit = obj->doesIntersect(ray);
        if (hit.didHit) {
            closest = hit.t < closest.t ? hit : closest;
        }
    }

    //Init pixels
    Pixel p(0, 0, 0);

    // Now color based on closes intersection
    if (closest.didHit) {
        for (Light* light : lights) {
            Vector l = Vector(closest.intersectionPoint, light->position).normalize();
            Vector h = (-1 * ray.vector + l).normalize();
            double diffusePass = closest.mat.diffuse * light->intensity * std::max(0., closest.normal.dot(l));
            double specularPass = closest.mat.specular * light->intensity * std::max(0., std::pow(closest.normal.dot(h), closest.mat.specular * 20));
            p.r = std::min(p.r + closest.mat.r * (diffusePass + ambientCoeff) + 255 * (specularPass), 255.);
            p.g = std::min(p.g + closest.mat.g * (diffusePass + ambientCoeff) + 255 * (specularPass), 255.);
            p.b = std::min(p.b + closest.mat.b * (diffusePass + ambientCoeff) + 255 * (specularPass), 255.);
        }
    }

    return p;
}