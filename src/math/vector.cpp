#include "vector.h"

Vector::Vector(Point* p1, Point* p2) {
	this->xCom = p2->x - p1->x;
	this->yCom = p2->y - p1->y;
	this->zCom = p2->z - p1->z;
	normalize();
}

Vector::Vector(double xCom, double yCom, double zCom) {
	this->xCom = xCom;
	this->yCom = yCom;
	this->zCom = zCom;
	normalize();
}

Vector::Vector(const Vector& old) {
	xCom = old.xCom;
	yCom = old.yCom;
	zCom = old.zCom;
}

double Vector::magnitude() {
	return std::sqrt(xCom * xCom + yCom * yCom + zCom * zCom);
}

void Vector::normalize() {
	double mag = magnitude();
	xCom /= mag;
	yCom /= mag;
	zCom /= mag;
}

//Adds the components of the vectors together.
Vector Vector::operator+(const Vector& vec) {
	this->xCom = this->xCom + vec.xCom;
	this->yCom = this->yCom + vec.yCom;
	this->zCom = this->zCom + vec.zCom;
	return *(this);
}

//Subtracts the components of the vectors together.
Vector Vector::operator-(const Vector& vec) {
	this->xCom = this->xCom - vec.xCom;
	this->yCom = this->yCom - vec.yCom;
	this->zCom = this->zCom - vec.zCom;
	return *(this);
}

//Multiply a vector by a scaler value
Vector Vector::operator*(double scale) {
	this->xCom = this->xCom * scale;
	this->yCom = this->yCom * scale;
	this->zCom = this->zCom * scale;
	return *(this);
}

//Divide a vector by a scaler value
Vector Vector::operator/(double scale) {
	this->xCom = this->xCom / scale;
	this->yCom = this->yCom / scale;
	this->zCom = this->zCom / scale;
	return *(this);
}

void Vector::print() {
	std::cout << xCom << " " << yCom << " " << zCom << std::endl;
}

Point Vector::operator+(const Point& point) {
	return Point(
		point.x + xCom, 
		point.y + yCom, 
		point.z + zCom
	);
}

//FOR COMMUTATIVITY
Vector operator*(double scale, Vector& vec) {
	return vec*scale;
}
Vector operator/(double scale, Vector& vec) {
	return vec/scale;
}
Point operator+(Point& point, Vector& vec) {
	return vec + point;
}

