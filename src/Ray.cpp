#include "ray.h"

Ray::Ray(Point* origin, Vector* vector) {
	this->origin = origin;
	this->vector = vector;
}
