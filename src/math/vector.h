#pragma once
#include <iostream>
#include "point.h"

class Vector
{
private:

public:
	double xCom, yCom, zCom;

	Vector(Point* p1, Point* p2);
	Vector(double xCom, double yCom, double zCom);
	Vector(const Vector& old);
	Vector cross(const Vector&);
	double dot(const Vector&);
	double magnitude();
	void normalize();
	Vector getPerpendicular();
	Vector operator+(const Vector&);
	Vector operator-(const Vector&);
	Vector operator*(double);
	Vector operator/(double);
	Point operator+(const Point&);
	void print();
};

Vector operator*(double scale, Vector& vec);
Vector operator/(double scale, Vector& vec);
Point operator+(Point& point, Vector& vec);

