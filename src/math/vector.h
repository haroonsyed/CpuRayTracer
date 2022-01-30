#pragma once
#include "Point.h"

class Vector
{
private:

public:
	Vector(Point* p1, Point* p2);
	~Vector();
	double xCom, yCom, zCom;
	Point* origin;
};

