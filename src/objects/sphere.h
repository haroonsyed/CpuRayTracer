#pragma once
#include "sceneobj.h"

class Sphere : public SceneObj {
private:
	double radius;
public:
	Sphere(Vector& p, double r):SceneObj(p) {
		radius = r;
	}
	Intersection doesIntersect(Ray& ray) {
		Vector d = ray.vector;
		Vector e = ray.origin;
		Vector c = position;
		double r = radius;
		double B = 2*d.dot(e - c);
		double A = d.dot(d);
		double C = (e - c).dot(e - c) - r * r;
		double discriminant = B * B - 4 * A * C;
		if (discriminant <= 0) {
			return Intersection();
		}
		else {
			double t =std::min( (-0.5 * B + sqrt(discriminant)) / A, (-0.5 * B - sqrt(discriminant)) / A);
			Vector p = ray.origin + t * ray.vector;
			return Intersection(p, (p-c)/r);
		}
	}
	void print() {
		std::cout << "Radius" << radius << std::endl;
		std::cout << "Position\n";
		position.print();
	}
};