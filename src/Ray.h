#pragma once
#include "math/vector.h"

class Ray
{

private:

public:
	Point* origin;
	Vector* vector;
	Ray(Point* origin, Vector* vector);
};

