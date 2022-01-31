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

Point Point::operator+(const Point& point) {
	return Point(
		x + point.x,
		y + point.y,
		z + point.z
	);
}

Point Point::operator-(const Point& point) {
	return Point(
		x - point.x,
		y - point.y,
		z - point.z
	);
}

Point Point::operator*(double scale) {
	return Point(
		x*scale,
		y*scale,
		z*scale
	);
}

Point Point::operator/(double scale) {
	return Point(
		x/scale,
		y/scale,
		z/scale
	);
}

void Point::print() {
	std::cout << x << " " << y << " " << z << std::endl;
}