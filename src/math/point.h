#pragma once
#include "vector.h"

// MAINLY USED FOR SEMANTICS. ACTS AS A VECTOR THOUGH
class Point : public Vector {
public:
	Point(double x, double y, double z) :Vector(x, y, z) {};
};