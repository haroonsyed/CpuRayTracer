#pragma once
#include "../math/vector.h"
#include "../ray.h"
#include "intersection.h"

class SceneObj {
private:

public:
	Vector position;
	SceneObj(Vector& p) : position{ 0,0,0 } {
		position = p;
	}
	virtual Intersection doesIntersect(Ray&) = 0;
	virtual void print() = 0;
};