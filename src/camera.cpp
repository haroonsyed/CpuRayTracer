#include "camera.h"
#include "objects/sphere.h"
#include "lights/light.h"
#include "scenes/scene.h"
//#include "scenes/scene.h"
//#include "scenes/scene1.h"

Camera::Camera(Vector& cameraLoc, Vector& cameraVec, int widthPix, int heightPix) :cameraLoc{ 0,0,0 }, viewDirection{1,0,0} {
    this->cameraLoc = cameraLoc;
    this->viewDirection = cameraVec;
    this->widthPix = widthPix;
    this->heightPix = heightPix;
    this->aspectRatio = ((double)widthPix) / heightPix;
    this->height = height / aspectRatio;
    viewDirection.normalize();
}

Camera::~Camera() {
    //Deallocate all necessary data
    if (image != nullptr) {
        delete[] image;
    }
}

unsigned char* Camera::renderImage() {

    // Create the image (RGB Array) to be displayed
    image = new unsigned char[widthPix * heightPix * 3];
    // Figure out real world increments for screen based on number of pixels
    double heightInc = height / heightPix;
    double widthInc = width / widthPix;
    // Determine the screen origin
    Vector sOrigin =  f_len * viewDirection + cameraLoc;
    //Determine screen plane
    Vector w = -1*viewDirection;
    Vector u = (up.cross(w)) / ((up.cross(w)).magnitude());
    Vector v = w.cross(u);
    //Determine left, right, top, bottom edges of the screen
    Vector sLeft = sOrigin - u * (width / 2);
    Vector sRight = sOrigin + u * (width / 2);
    Vector sTop = sOrigin + v * (height / 2);
    Vector sBottom = sOrigin - v * (height / 2);

    //Choose scene
    //Scene scene = scene1;
    Vector* sp = new Vector(10,1,-2.3);
    Material mat1(0,0,255);
    Sphere* sph = new Sphere(*sp, 1, mat1);
    Vector* sp2 = new Vector(20,3,-2.3);
    Material mat2(0, 255, 0);
    Sphere* sph2 = new Sphere(*sp2, 1, mat2);

    //Lighting
    Vector lightPos(0, 15, 0);
    Light* light1 = new Light(lightPos, 0.8);

    std::vector<SceneObj*> objs{ sph, sph2 };
    std::vector<Light*> lights{light1};

    Scene scene(objs, lights);

    u.print();
    v.print();
    w.print();
    
    for (int i = 0; i < heightPix; i++)
    {
        for (int j = 0; j < widthPix; j++)
        {

            int idx = (i * widthPix + j) * 3;

            if (mode == MODE::ORTHOGRAPHIC) {

                //Generate a ray facing normal to camera screen at pixel Vector
                Vector origin = sOrigin +
                    u * (width * (j-widthPix)/(double)widthPix ) +
                    v * (height* (i-heightPix)/(double)heightPix );
                Ray r = Ray(origin,viewDirection);

                Intersection closest = Intersection();
                Intersection hit;

                for (SceneObj* obj : scene.objects) {
                    hit = obj->doesIntersect(r);
                    if (hit.didHit) {
                        closest = hit.t < closest.t ? hit : closest;
                    }
                }

                // Now color based on closes intersection
                if (closest.didHit) {
                    for (Light* light : scene.lights) {
                        Vector l = Vector(closest.intersectionPoint, light->position);
                        l.normalize();
                        double pixelIntensity = light->intensity * std::max(0., closest.normal.dot(l));
                        image[idx + 0] = closest.mat.r * pixelIntensity;
                        image[idx + 1] = closest.mat.g * pixelIntensity;
                        image[idx + 2] = closest.mat.b * pixelIntensity;
                    }
                }
                else {
                    image[idx + 0] = 0;
                    image[idx + 1] = 0;
                    image[idx + 2] = 0;
                }
            }

            else if (mode == MODE::PERSPECTIVE) {

                image[idx] = 0;
                image[idx + 1] = 0;
                image[idx + 2] = 0;

            }

        }
    }

    return image;
}
