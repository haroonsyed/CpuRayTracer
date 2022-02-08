#pragma once
#include <iostream>
#include "sceneobj.h"
#include "../math/mathutil.h"

// Will be used to construct larger objects later
// Starting out it will be its own object though
class Triangle : public SceneObj {
private:

public:
	Vector p1 = Vector(0, 0, 0);
	Vector p2 = Vector(0, 0, 0);
	Vector p3 = Vector(0, 0, 0);

	Triangle(Vector& p1, Vector& p2, Vector& p3, Material& mat):SceneObj(p1,mat) {
		this->p1 = p1;
		this->p2 = p2;
		this->p3 = p3;
		this->position = findCenter(); // Original p1 is just a placeholder
	}
	Intersection doesIntersect(Ray& ray) {
		// This tutorial helped me visualize what the linear algebra is doing:
		// https://www.youtube.com/watch?v=HYAgJN3x4GA

		Vector n = (p2 - p1).cross(p3 - p1).normalize();

		// Use barymetric coordinates. Solving using cramer's rule
		double a = p1.xCom - p2.xCom;
		double b = p1.yCom - p2.yCom;
		double c = p1.zCom - p2.zCom;
		double d = p1.xCom - p3.xCom;
		double e = p1.yCom - p3.yCom;
		double f = p1.zCom - p3.zCom;
		double g = ray.vector.xCom;
		double h = ray.vector.yCom;
		double i = ray.vector.zCom;
		double j = p1.xCom - ray.origin.xCom;
		double k = p1.yCom - ray.origin.yCom;
		double l = p1.zCom - ray.origin.zCom;
		double M = (a * (e * i - h * f)) + (b * (g * f - d * i)) + (c * (d * h - e * g));
		double beta = ((j * (e * i - h * f)) + (k * (g * f - d * i)) + (l * (d * h - e * g))) / M;
		double gamma = ((i * (a * k - j * b)) + (h * (j * c - a * l)) + (g * (b * l - k * c))) / M;
		double alpha = 1 - beta - gamma;
		double t = -1. * ((f * (a * k - j * b)) + (e * (j * c - a * l)) + (d * (b * l - k * c))) / M;

		//Check all are positive to be a triangle
		if (beta < 0 || gamma < 0 || alpha < 0 || t<0) {
			return Intersection();
		}

		Vector p = ray.origin + t * ray.vector;
		// Align dot product against camera ray for normal
		n = ray.vector.dot(n) < 0 ? n : -1 * n;

		return Intersection(
			t,
			p,
			n,
			mat
		);
	}
	Vector findCenter() {
		return (p1 + p2 + p3) /  3;
	}
	void print() {
		std::cout << "Triangle points: " << std::endl;
		p1.print();
		p2.print();
		p3.print();
		std::cout << "With center: " << std::endl;
		findCenter().print();
	}
};