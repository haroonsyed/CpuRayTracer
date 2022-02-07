#include "camera.h"
#include "scenes/scene1.h"

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
    Scene scene = scene1;
    
    for (int i = 0; i < heightPix; i++)
    {
        for (int j = 0; j < widthPix; j++)
        {

            int idx = (i * widthPix + j) * 3;
            Vector* origin;
            Ray* r;

            if (mode == MODE::ORTHOGRAPHIC) {
                //Generate a ray facing normal to camera screen at pixel Vector
                origin = &(sOrigin +
                    u * (width * ((j-widthPix)/(double)widthPix) + width/2) +
                    v * (height * ((i-heightPix)/(double)heightPix) + height/2));
                r = &Ray(*origin,viewDirection);
            }

            else if (mode == MODE::PERSPECTIVE) {

                image[idx] = 0;
                image[idx + 1] = 0;
                image[idx + 2] = 0;

            }

            // Render the ray and set image array pixels
            Pixel pixel = scene.render(*r);
            image[idx] = pixel.r;
            image[idx + 1] = pixel.g;
            image[idx + 2] = pixel.b;

        }
    }

    return image;
}
