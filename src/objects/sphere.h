#pragma once
#include "sceneobj.h"

class Sphere : public SceneObj {
private:
	double radius;
public:
	Sphere(Vector& p, double r):SceneObj(p) {
		radius = r;
	}
	bool doesIntersect(Ray& ray) {
		Vector d = ray.vector;
		Vector e = ray.origin;
		Vector c = position;
		double r = radius;
		double B = 2*d.dot(e - c);
		double A = d.dot(d);
		double C = (e - c).dot(e - c) - r * r;
		double discriminant = B * B - 4 * A * C;
		if (discriminant <= 0) {
			return false;
		}
		else {
			return true;
		}
	}
	void print() {
		std::cout << "Radius" << radius << std::endl;
		std::cout << "Position\n";
		position.print();
	}
};