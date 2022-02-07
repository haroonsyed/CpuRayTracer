#pragma once
#include "../math/vector.h"
#include "material.h"

class Intersection {
public:
	Vector intersectionPoint;
	Vector normal;
	Material mat;
	bool didHit;
	double t;
	Intersection() : intersectionPoint{ 0,0,0 }, normal{0,0,0} {
		mat = Material();
		didHit = false;
		t = DBL_MAX; //MUST BE MAX FOR CLOSEST OBJECT CALCULATION
	};
	Intersection(double t, Vector& intersectionPoint, Vector& normal, Material& mat): intersectionPoint { 0, 0, 0 }, normal{ 0,0,0 } {
		didHit = true;
		this->intersectionPoint = intersectionPoint;
		this->normal = normal;
		this->mat = mat;
		this->t = t;
	}
};