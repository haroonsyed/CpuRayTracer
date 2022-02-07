#pragma once
#include <iostream>
#include "vector.h"

class Vector
{
private:

public:
	double xCom, yCom, zCom;

	Vector(Vector& p1, Vector& p2);
	Vector(double xCom, double yCom, double zCom);
	Vector(const Vector& old);
	Vector cross(const Vector&);
	double dot(const Vector&);
	double magnitude();
	Vector normalize();
	Vector getPerpendicular();
	Vector operator+(const Vector&);
	Vector operator-(const Vector&);
	bool operator==(const Vector&);
	bool operator!=(const Vector&);
	Vector operator*(double);
	Vector operator/(double);
	void print();
};

Vector operator*(double scale, Vector& vec);


