#include "point.h"

Point::Point(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Point::Point(const Point& old) {
	x = old.x;
	y = old.y;
	z = old.z;
}

void Point::print() {
	std::cout << x << " " << y << " " << z << std::endl;
}