#include "camera.h"

camera::camera() {
    
}

camera::~camera() {
    //Deallocate all necessary data
    if (image != nullptr) {
        delete[] image;
    }
}

unsigned char* camera::renderImage() {

    // Create the image (RGB Array) to be displayed
    image = new unsigned char[width * height * 3];
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int idx = (i * width + j) * 3;
            image[idx] = (unsigned char)(255 * i * j / height / width); //((i+j) % 2) * 255;
            image[idx + 1] = 0;
            image[idx + 2] = 0;
        }
    }

    return image;
}
