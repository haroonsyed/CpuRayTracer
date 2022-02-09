#pragma once
#include "pixel.h"
#include "math/vector.h"

class Ray
{

private:

public:
	Vector origin;
	Vector vector;
	bool didHit;
	Ray(Vector& origin, Vector& vector);
};

