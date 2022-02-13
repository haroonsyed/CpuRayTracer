#include "camera.h"

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

unsigned char* Camera::renderThreaded() {

    // Determine the screen origin
    Vector sOrigin = f_len * viewDirection + cameraLoc;
    //Determine screen plane
    Vector w = -1 * viewDirection;
    Vector u = up.cross(w).normalize();
    Vector v = w.cross(u).normalize();

    //Create n threads
    std::vector<std::thread> threadPool;
    for (int i = 0; i < threadCount; i++) {
        threadPool.push_back(
            std::thread(
                &Camera::renderImage,
                this,
                i,
                std::ref(sOrigin),
                std::ref(u),
                std::ref(v),
                std::ref(w)
            )
        );
    }

    // Wait for threads to complete work
    for (std::thread &t : threadPool) {
        t.join();
    }

    return image;
}

// ThreadNumber starts at 0
//Todo: reduce paramater list size by moving to private property
void Camera::renderImage(int threadNumber, Vector& sOrigin,Vector& u,Vector& v,Vector& w) {    
    
    Ray r = Ray(w,u); //Initialize ray with garbage data. Reused in double for loop though
    int startHeight = (heightPix/threadCount) * threadNumber;
    int endHeight = (heightPix / threadCount) * (threadNumber+1);

    for (int i = startHeight; i < endHeight; i++)
    {
        for (int j = 0; j < widthPix; j++)
        {

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
                Vector rayVec = Vector(cameraLoc, screenLoc);
                r = Ray(cameraLoc, rayVec);

            }

            // Render the ray and set image array pixels
            Pixel pixel = scene1.render(r, 0);

            int idx = (i * widthPix + j) * 3;

            image[idx] = pixel.r;
            image[idx + 1] = pixel.g;
            image[idx + 2] = pixel.b;

        }
    }
}

void Camera::changePerspective() {
    if (mode == MODE::ORTHOGRAPHIC) {
        mode = MODE::PERSPECTIVE;
        width /= 40;
        height = width / aspectRatio;
    }
    else {
        mode = MODE::ORTHOGRAPHIC;
        width *= 40;
        height = width / aspectRatio;
    }
}
