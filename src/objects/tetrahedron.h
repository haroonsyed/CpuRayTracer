#pragma once
#include <vector>
#include "sceneobj.h"
#include "triangle.h"

class Tetrahedron : public SceneObj {

private:
    Vector calculatePosition();

public:

	std::vector<Triangle> tris;

    // For now will just be a non-resizable tetrahedron
    Tetrahedron(Vector position, Material& mat);
    void setPosition(Vector& p);
    Intersection doesIntersect(Ray& ray);
    void print();
};