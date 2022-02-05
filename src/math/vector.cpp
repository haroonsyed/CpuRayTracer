#include "vector.h"
#include <math.h>
#include "mathutil.h"

Vector::Vector(Point& p1, Point& p2) {
	this->xCom = p2.x - p1.x;
	this->yCom = p2.y - p1.y;
	this->zCom = p2.z - p1.z;
}

Vector::Vector(double xCom, double yCom, double zCom) {
	this->xCom = xCom;
	this->yCom = yCom;
	this->zCom = zCom;
}

Vector::Vector(const Vector& old) {
	xCom = old.xCom;
	yCom = old.yCom;
	zCom = old.zCom;
}

Vector Vector::cross(const Vector& vec) {
	return Vector(
		yCom * vec.zCom - zCom * vec.yCom,
		zCom * vec.xCom - xCom * vec.zCom,
		xCom * vec.yCom - yCom * vec.xCom
	);
}

double Vector::dot(const Vector& vec) {
	return xCom * vec.xCom + yCom * vec.yCom + zCom * vec.zCom;
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

Vector Vector::getPerpendicular() {
	int minPos = xCom < yCom ? (xCom < zCom ? 0 : 2) : (yCom < zCom ? 1 : 2); //Corresponds to x,y,z as 0,1,2. Faster than floating with epsilon
	Vector t(0, 0, 0);
	if (minPos == 0) {
		 t=Vector(1,yCom,zCom);
	}
	else if (minPos == 1) {
		t = Vector(xCom, 1, zCom);
	}
	else {
		t = Vector(xCom, yCom, 1);
	}
	Vector temp = (t.cross(*this)) / t.magnitude();
	return temp / temp.magnitude();
}

//Adds the components of the vectors together.
Vector Vector::operator+(const Vector& vec) {
	return Vector(
		xCom + vec.xCom,
		yCom + vec.yCom,
		zCom + vec.zCom
	);
}

//Subtracts the components of the vectors together.
Vector Vector::operator-(const Vector& vec) {
	return Vector(
		xCom - vec.xCom,
		yCom - vec.yCom,
		zCom - vec.zCom
	);
}

bool Vector::operator==(const Vector& v) {
	return aboutEquals(xCom, v.xCom) && aboutEquals(yCom, v.yCom) && aboutEquals(zCom, v.zCom);
}

//Multiply a vector by a scaler value
Vector Vector::operator*(double scale) {
	return Vector(
		xCom * scale,
		yCom * scale,
		zCom * scale
	);
}

//Divide a vector by a scaler value
Vector Vector::operator/(double scale) {
	return Vector(
		xCom / scale,
		yCom / scale,
		zCom / scale
	);
}

Point Vector::operator*(const Point& point) {
	return Point(
		xCom*point.x,
		yCom*point.y,
		zCom*point.z
	);
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

Point Vector::operator-(const Point& point) {
	return Point(
		point.x - xCom,
		point.y - yCom,
		point.z - zCom
	);
}

//FOR COMMUTATIVITY
Vector operator*(double scale, Vector& vec) {
	return vec * scale;
}
Vector operator/(double scale, Vector& vec) {
	return vec / scale;
}
Point operator+(Point& point, Vector& vec) {
	return vec + point;
}
Point operator-(Point& point, Vector& vec) {
	return vec - point; // This is confusing, but points should only be subtracting vectors. But operator overloading got messy
}
Point operator*(Point& point, Vector& vec) {
	return vec * point;
}
