#pragma once
#include "math/vector.h"

class Ray
{

private:

public:
	Vector origin;
	Vector vector;
	Ray(Vector& origin, Vector& vector);
};

