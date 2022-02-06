#pragma once
#include "math/vector.h"
#include "math/point.h"

class Camera
{

private:

	enum class MODE {ORTHOGRAPHIC,PERSPECTIVE};

    unsigned char* image = nullptr;

    int widthPix; // keep it in powers of 2!
    int heightPix; // keep it in powers of 2!
	double f_len = 1; //Distance from ray origin to projection screen along looking direction
	const double aspectRatio = ((double)widthPix) / heightPix; //Used for fixing scaling
	const double width = 0.4; //Real world units
	const double height = width / aspectRatio; //Real world units

	MODE mode = MODE::ORTHOGRAPHIC;

	Vector cameraLoc;
	Vector viewDirection;
	Vector up = Vector(0,0,1); //Default to 0,0,1


public:
	Camera(Vector&, Vector&, int, int);
	~Camera();

	unsigned char* renderImage();


};

