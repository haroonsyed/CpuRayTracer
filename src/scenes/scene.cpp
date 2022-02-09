#include "scene.h"
#include <math.h>

Scene::Scene(std::vector<SceneObj*>& objects, std::vector<Light*>& lights) :ambientCoeff{0.07} {
	this->objects = objects;
	this->lights = lights;
}

Pixel Scene::render(Ray& ray, int depth) {
    Intersection closest;
    Intersection hit;

    for (SceneObj* obj : objects) {
        hit = obj->doesIntersect(ray);
        if (hit.didHit) {
            closest = hit.t < closest.t ? hit : closest;
        }
    }

    //Init pixels
    Pixel p(0, 0, 0);
    Material mat = closest.mat;

    // Now color based on closes intersection
    if (closest.didHit) {
        ray.didHit = true;
        for (Light* light : lights) {
            Vector l = Vector(closest.intersectionPoint, light->position).normalize();
            Vector h = ((-1 * ray.vector) + l).normalize();
            double diffuse = mat.diffuse * light->intensity * std::max(0., closest.normal.dot(l));
            double specular = mat.specular * 255 * light->intensity * std::max(0.0, std::pow(closest.normal.dot(h), mat.phongExp));


            // Reflective calculation
            if (mat.mirror > 0 && depth < maxRecursions) {
                //New ray direction
                Vector recRayDir = ray.vector - (2 * (ray.vector.dot(closest.normal)))*closest.normal;
                Ray recRay(closest.intersectionPoint, recRayDir);
                Pixel recPixel = render(recRay, depth+1);
                p.r = mat.mirror *recPixel.r;
                p.g = mat.mirror* recPixel.g;
                p.b = mat.mirror * recPixel.b;
            }

            p.r = std::min(p.r + closest.mat.r * (diffuse + ambientCoeff) + specular, 255.);
            p.g = std::min(p.g + closest.mat.g * (diffuse + ambientCoeff) + specular, 255.);
            p.b = std::min(p.b + closest.mat.b * (diffuse + ambientCoeff) + specular, 255.);
        }
    }

    return p;
}