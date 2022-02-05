#pragma once
#include <iostream>

class Point {
public:
	double x, y, z;
	Point(double x, double y, double z);
	Point(const Point &old);
	Point operator+(const Point&);
	Point operator-(const Point&);
	bool operator==(const Point&);
	bool operator!=(const Point&);
	Point operator*(double scale);
	Point operator/(double scale);
	void print();
};

Point operator*(double scale, Point& p);

