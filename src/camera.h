#pragma once
#include "math/vector.h"
class Camera
{

private:

	enum class MODE {ORTHOGRAPHIC,PERSPECTIVE};

    unsigned char* image = nullptr;

    const int widthPix = 128; // keep it in powers of 2!
    const int heightPix = 128; // keep it in powers of 2!
	double f_len = 10; //Distance from ray origin to projection screen along looking direction
	const double aspectRatio = ((double)widthPix) / heightPix; //Used for fixing scaling
	const double width = 0.2; //Real world units
	const double height = width / aspectRatio; //Real world units

	MODE mode = MODE::ORTHOGRAPHIC;

	Point cameraLoc;
	Vector viewDirection;
	Vector up = Vector(0,0,1); //Default to 0,0,1


public:
	Camera(Point&, Vector&);
	~Camera();

	unsigned char* renderImage();


};

