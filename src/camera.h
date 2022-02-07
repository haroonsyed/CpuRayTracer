#pragma once
#include "math/vector.h"
#include "math/point.h"

class Camera
{

private:

	enum class MODE {ORTHOGRAPHIC,PERSPECTIVE};

    unsigned char* image = nullptr;

    int widthPix = 256; // keep it in powers of 2!
    int heightPix = 256; // keep it in powers of 2!
	double f_len = 5; //Distance from ray origin to projection screen along looking direction
	double aspectRatio = ((double)widthPix) / heightPix; //Used for fixing scaling
	double width = 20; //Real world units
	double height = width / aspectRatio; //Real world units

	MODE mode = MODE::ORTHOGRAPHIC;

	Vector cameraLoc;
	Vector viewDirection;
	Vector up = Vector(0,0,1); //Default to 0,0,1


public:
	Camera(Vector&, Vector&, int, int);
	~Camera();

	unsigned char* renderImage();


};

