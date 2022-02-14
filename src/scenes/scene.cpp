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

            bool inShadow = false;
            if (enableShadows) {
                // Calculate the shadow rays
                Ray toLight = Ray(closest.intersectionPoint, l);
                for (SceneObj* obj : objects) {
                    hit = obj->doesIntersect(toLight);
                    if (hit.didHit && hit.t > hitEpsilon) {

                        // Just add ambient light
                        inShadow = true;
                        break;
                    }
                }
            }

            if (inShadow) {
                continue;
            }

            double diffuse = mat.diffuse * light->intensity * std::max(0., closest.normal.dot(l));
            double specular = mat.specular * 255 * light->intensity * std::max(0.0, std::pow(closest.normal.dot(h), mat.phongExp));

            // Reflective calculation
            Pixel ref(0, 0, 0);
            if (mat.mirror > 0 && depth < maxRecursions) {
                //New ray direction
                Vector recRayDir = ray.vector - (2*ray.vector.dot(closest.normal)*closest.normal);
                Ray recRay(closest.intersectionPoint, recRayDir);
                ref = render(recRay, depth + 1);
            }

            p.r = std::min(p.r + mat.mirror*ref.r + mat.r * (diffuse) + specular, 255.);
            p.g = std::min(p.g + mat.mirror*ref.g + mat.g * (diffuse) + specular, 255.);
            p.b = std::min(p.b + mat.mirror*ref.b + mat.b * (diffuse) + specular, 255.);
            

        }
    }
    else {
        // Give a background color of sky-blue
        return Pixel(135, 206, 235);
    }

    // Add ambient
    p.r = std::min(p.r + mat.r * (ambientCoeff), 255.);
    p.g = std::min(p.g + mat.g * (ambientCoeff), 255.);
    p.b = std::min(p.b + mat.b * (ambientCoeff), 255.);

    return p;
}