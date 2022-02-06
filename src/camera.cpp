#include "camera.h"
#include "ray.h"
#include "objects/sphere.h"
//#include "scenes/scene.h"
//#include "scenes/scene1.h"

Camera::Camera(Vector& cameraLoc, Vector& cameraVec) :cameraLoc{ 0,0,0 }, viewDirection{1,0,0} {
    this->cameraLoc = cameraLoc;
    this->viewDirection = cameraVec;
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
    Vector sp = Vector(0,0,5);
    Sphere sph = Sphere(sp, 3);

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
                Vector origin = sOrigin  + 
                            u*(width/2*(j-widthPix/2)) +
                            v*(height/2*(i-heightPix/2));
                Ray r = Ray(origin,viewDirection);

                image[idx + 0] = 0;
                image[idx + 1] = 0;
                image[idx + 2] = sph.doesIntersect(r) ? 255 : 0;

                // Loop through all objects in the scene and see if there is an intersection
                /*for (SceneObj* o : scene.objects) {
                    image[idx + 0] = 0;
                    image[idx + 1] = 0;
                    image[idx + 2] = o->doesIntersect(r) ? 255 : 0;
                }*/
                
                //image[idx] = (unsigned char)(255 * i * j / heightPix / widthPix); //((i+j) % 2) * 255;
                //image[idx + 1] = 0;
                //image[idx + 2] = 0;

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
