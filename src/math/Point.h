#pragma once
#include <iostream>

class Point {
public:
	double x, y, z;
	Point(double x, double y, double z);
	Point(const Point &old);
	void print();
};

