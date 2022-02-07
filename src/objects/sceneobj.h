#pragma once
#include "../math/vector.h"
#include "../ray.h"
#include "intersection.h"
#include "material.h"

class SceneObj {
private:

public:
	Vector position;
	Material mat;
	SceneObj(Material& mat) : position{ 0,0,0 }, mat{} {
		this->mat = mat;
	}
	SceneObj(Vector& p, Material& mat) : position{ 0,0,0 }, mat{} {
		position = p;
		this->mat = mat;
	}
	virtual Intersection doesIntersect(Ray&) = 0;
	virtual void print() = 0;
};