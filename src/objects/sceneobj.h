#pragma once
#include "../math/Vector.h"
#include "../ray.h"

class SceneObj {
private:

public:
	Vector position;
	SceneObj(Vector& p) : position{ 0,0,0 } {
		position = p;
	}
	virtual bool doesIntersect(Ray&) = 0;
	virtual void print() = 0;
};