#include "vector.h"
#include <iostream>

Vector::Vector(Point* p1, Point* p2) {
	this->xCom = p2->x - p1->x;
	this->yCom = p2->y - p1->y;
	this->zCom = p2->z - p1->z;
	this->origin = new Point(p1->x, p1->y, p1->z);
	std::cout << "MAKING A VECTOR" << std::endl;
	std::cout << origin->x << " " << origin->y << " " << origin->z << std::endl;
}

Vector::~Vector() {
	if (origin != nullptr) {
		std::cout << origin->x << " " << origin->y << " " << origin->z << std::endl;
		std::cout << "DELETING A VECTOR" << std::endl;
		delete origin;
	}
}