#pragma once
#include "math/vector.h"
class Camera
{

private:

	enum class MODE {ORTHOGRAPHIC,PERSPECTIVE};

    unsigned char* image = nullptr;

    const int width = 128; // keep it in powers of 2!
    const int height = 128; // keep it in powers of 2!
	double f_len = 1; //Distance from ray origin to projection screen along looking direction
	MODE mode = MODE::ORTHOGRAPHIC;

	Vector* vec = nullptr;



public:
	Camera(Vector* v);
	~Camera();

	unsigned char* renderImage();


};

