#pragma once
#include "../ray.h"
#include "intersection.h"

class SceneObj {
private:

public:
	Vector position;
	Material mat;
	SceneObj(Material& mat);
	SceneObj(Vector& p, Material& mat);
	virtual Intersection doesIntersect(Ray&) = 0;
	virtual void print() = 0;
};