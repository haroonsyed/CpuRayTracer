#pragma once
#include "math/vector.h"
#include "scenes/scene1.h"
#include <thread>

class Camera
{

private:

	enum class MODE {ORTHOGRAPHIC,PERSPECTIVE};

    unsigned char* image = nullptr;

    int widthPix = 256; // keep it in powers of 2!
    int heightPix = 256; // keep it in powers of 2!
	double f_len = 1; //Distance from ray origin to projection screen along looking direction
	double aspectRatio = ((double)widthPix) / heightPix; //Used for fixing scaling
	double width = 0.2; //Real world units
	double height = width / aspectRatio; //Real world units

	int threadCount = std::thread::hardware_concurrency();

	MODE mode = MODE::PERSPECTIVE;

public:
	Vector cameraLoc;
	Vector viewDirection;
	Vector up = Vector(0,0,1); //Default to 0,0,1

	Camera(Vector&, Vector&, int, int);
	~Camera();

	unsigned char* renderThreaded();
	void renderImage(int threadNumber, Vector&, Vector& , Vector& , Vector& );
	void changePerspective();

};

