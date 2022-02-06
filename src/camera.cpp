#include "camera.h"
#include "objects/sphere.h"
#include "lights/light.h"
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
    Vector sp = Vector(20,2.5,-2.3);
    Sphere sph = Sphere(sp, 2);
    //Light comes from side
    Vector lightDir(-1000, 0, 0);
    Light light = Light(lightDir,0.8);

    u.print();
    v.print();
    w.print();
    sph.print();
    
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

                Intersection hit = sph.doesIntersect(r);
                if (hit.didHit) {
                    Vector l = Vector(hit.intersectionPoint, light.position);
                    l.normalize();
                    int pixelVal = light.intensity * 255 * std::max(0., hit.normal.dot(l));
                    image[idx + 0] = 0;
                    image[idx + 1] = 0;
                    image[idx + 2] = pixelVal;
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
