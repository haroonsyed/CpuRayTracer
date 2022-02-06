#include "ray.h"

Ray::Ray(Vector& origin, Vector& vector):origin{ 0,0,0 }, vector{1,0,0} {
	this->origin = origin;
	this->vector = vector;
}
