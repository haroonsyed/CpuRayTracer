#include "camera.h"

Camera::Camera(Point* cameraLoc, Vector* v) {
    this->cameraLoc = cameraLoc;
    this->viewDirection = v;
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
    viewDirection->print();
    Point sOrigin =  f_len * (*viewDirection) + (*cameraLoc);
    sOrigin.print();
    //Determine screen plane
    Vector w = *viewDirection;
    Vector u = ((*up).cross(w)) / (((*up).cross(w)).magnitude());
    Vector v = w.cross(u);
    w.print();
    u.print();
    v.print();
    
    for (int i = 0; i < heightPix; i++)
    {
        for (int j = 0; j < widthPix; j++)
        {

            int idx = (i * widthPix + j) * 3;

            if (mode == MODE::ORTHOGRAPHIC) {

                //Generate a ray facing normal to camera screen at pixel point
                
                
                image[idx] = (unsigned char)(255 * i * j / heightPix / widthPix); //((i+j) % 2) * 255;
                image[idx + 1] = 0;
                image[idx + 2] = 0;

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
