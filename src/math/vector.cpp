#include "vector.h"
#include <math.h>
#include "mathutil.h"

Vector::Vector(Vector& p1, Vector& p2) {
	this->xCom = p2.xCom - p1.xCom;
	this->yCom = p2.yCom - p1.yCom;
	this->zCom = p2.zCom - p1.zCom;
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

Vector Vector::normalize() {
	double mag = magnitude();
	xCom /= mag;
	yCom /= mag;
	zCom /= mag;
	return *this;
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

bool Vector::operator!=(const Vector& v) {
	return !(*this==v);
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

void Vector::print() {
	std::cout << xCom << " " << yCom << " " << zCom << std::endl;
}

//FOR COMMUTATIVITY
Vector operator*(double scale, Vector& vec) {
	return vec * scale;
}
Vector operator/(double scale, Vector& vec) {
	return vec / scale;
}
