#include "scene.h"
#include <math.h>

Scene::Scene(std::vector<SceneObj*>& objects, std::vector<Light*>& lights) :ambientCoeff{0.07} {
	this->objects = objects;
	this->lights = lights;
}

Pixel Scene::render(Ray& ray, int depth) {
    Intersection closest;
    Intersection hit;

    // Ray should not intersect with generation point
    const double hitEpsilon = 0.0005;

    for (SceneObj* obj : objects) {
        hit = obj->doesIntersect(ray);
        if (hit.didHit) {
            closest = (hit.t < closest.t && hit.t > hitEpsilon) ? hit : closest;
        }
    }

    //Init pixels
    Pixel p(0,0,0);
    Material mat = closest.mat;

    // Now color based on closes intersection
    if(closest.didHit) {
        ray.didHit = true;
        for (Light* light : lights) {
            Vector l = Vector(closest.intersectionPoint, light->position).normalize();
            Vector h = ((-1 * ray.vector) + l).normalize();
            double diffuse = mat.diffuse * light->intensity * std::max(0., closest.normal.dot(l));
            double specular = mat.specular * 255 * light->intensity * std::max(0.0, std::pow(closest.normal.dot(h), mat.phongExp));

            if (enableShadows) {
                // Calculate the shadow rays
                Ray toLight(closest.intersectionPoint, light->position);
                toLight.vector.normalize();
                bool inShadow = false;
                for (SceneObj* obj : objects) {
                    hit = obj->doesIntersect(toLight);
                    if (hit.didHit && hit.t > hitEpsilon) {
                        p.r = p.g = p.b = 0;
                        inShadow = true;
                        break;
                    }
                }

                // Remember to add ambient pass as well
                if (inShadow) {
                    return p;
                }
            }

            // Reflective calculation
            Pixel ref(0, 0, 0);
            if (mat.mirror > 0 && depth < maxRecursions) {
                //New ray direction
                Vector recRayDir = ray.vector - (2*ray.vector.dot(closest.normal)*closest.normal);
                Ray recRay(closest.intersectionPoint, recRayDir);
                ref = render(recRay, depth + 1);
            }

            p.r = std::min(p.r + mat.mirror*ref.r + mat.r * (diffuse + ambientCoeff) + specular, 255.);
            p.g = std::min(p.g + mat.mirror*ref.g + mat.g * (diffuse + ambientCoeff) + specular, 255.);
            p.b = std::min(p.b + mat.mirror*ref.b + mat.b * (diffuse + ambientCoeff) + specular, 255.);
        }
    }
    else {
        // Give a background color of sky-blue
        p = Pixel(135, 206, 235);
    }

    return p;
}