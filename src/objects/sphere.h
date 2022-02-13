#pragma once
#include <math.h>
#include "sceneobj.h"

class Sphere : public SceneObj {
private:
	double radius;
public:
	Sphere(Vector& p, double r, Material& mat);
	Intersection doesIntersect(Ray& ray);
	void print();
};