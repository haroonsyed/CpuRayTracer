#pragma once
#include "../math/vector.h"

class Intersection {
public:
	Vector intersectionPoint;
	Vector normal;
	bool didHit = false;
	Intersection() : intersectionPoint{ 0,0,0 }, normal{0,0,0} {};
	Intersection(Vector& intersectionPoint, Vector& normal): intersectionPoint { 0, 0, 0 }, normal{ 0,0,0 } {
		didHit = true;
		this->intersectionPoint = intersectionPoint;
		this->normal = normal;
	}
};