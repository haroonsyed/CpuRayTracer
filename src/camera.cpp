#include "camera.h"
#include "scenes/scene1.h"

Camera::Camera(Vector& cameraLoc, Vector& cameraVec, int widthPix, int heightPix) :cameraLoc{ 0,0,0 }, viewDirection{1,0,0} {
    this->cameraLoc = cameraLoc;
    this->viewDirection = cameraVec;
    this->widthPix = widthPix;
    this->heightPix = heightPix;
    this->aspectRatio = ((double)widthPix) / heightPix;
    this->height = height / aspectRatio;
    image = new unsigned char[widthPix * heightPix * 3];
    viewDirection.normalize();
}

Camera::~Camera() {
    //Deallocate all necessary data
    if (image != nullptr) {
        delete[] image;
    }
}

unsigned char* Camera::renderImage() {    
    // Determine the screen origin
    Vector sOrigin =  f_len * viewDirection + cameraLoc;
    //Determine screen plane
    Vector w = -1*viewDirection;
    Vector u = up.cross(w).normalize();
    Vector v = w.cross(u).normalize();
    //Determine left, right, top, bottom edges of the screen
    Vector sLeft = sOrigin - u * (width / 2);
    Vector sRight = sOrigin + u * (width / 2);
    Vector sTop = sOrigin + v * (height / 2);
    Vector sBottom = sOrigin - v * (height / 2);

    //Choose scene
    Scene scene = scene1;
    
    Ray r = Ray(w,u); //Initialize ray with garbage data. Reused in double for loop though

    for (int i = 0; i < heightPix; i++)
    {
        for (int j = 0; j < widthPix; j++)
        {

            int idx = (i * widthPix + j) * 3;
            
            //Location on screen
            Vector screenLoc =  (sOrigin +
                u * (width * ((j - widthPix) / (double)widthPix) + width / 2) +
                v * (height * ((i - heightPix) / (double)heightPix) + height / 2));

            if (mode == MODE::ORTHOGRAPHIC) {
                //Generate a ray facing normal to camera screen at pixel Vector
                r = Ray(screenLoc,viewDirection);
            }

            else if (mode == MODE::PERSPECTIVE) {

                //Generate a ray from cam location toward camera screen pixel (not normal)
                r = Ray(cameraLoc, screenLoc);

            }

            // Render the ray and set image array pixels
            Pixel pixel = scene.render(r);
            image[idx] = pixel.r;
            image[idx + 1] = pixel.g;
            image[idx + 2] = pixel.b;
        }
    }

    return image;
}

void Camera::changePerspective() {
    if (mode == MODE::ORTHOGRAPHIC) {
        mode = MODE::PERSPECTIVE;
        width /= 5;
        height = width / aspectRatio;
    }
    else {
        mode = MODE::ORTHOGRAPHIC;
        width *= 5;
        height = width / aspectRatio;
    }
}
