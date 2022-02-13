#pragma once
#include "sceneobj.h"

class Triangle : public SceneObj {
private:

public:
	Vector p1 = Vector(0, 0, 0);
	Vector p2 = Vector(0, 0, 0);
	Vector p3 = Vector(0, 0, 0);

	Triangle(Vector& p1, Vector& p2, Vector& p3, Material& mat);
	Intersection doesIntersect(Ray& ray);
	Vector findCenter();
	void print();
};