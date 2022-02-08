#pragma once
#include "sceneobj.h"
#include "triangle.h"

class Tetrahedron : public SceneObj {

private:
    Vector calculatePosition() {
        Vector result = Vector(0, 0, 0);
        for (Triangle& tri : tris) {
            result = result + tri.position;
        }
        return result/4;
    }

public:

	std::vector<Triangle> tris;

    // For now will just be a non-resizable tetrahedron
    Tetrahedron(Vector position, Material& mat) : SceneObj(position, mat) {
        tris = std::vector<Triangle>{
            *new Triangle(
                *new Vector(-1,0,0),
                *new Vector(0,0,1),
                *new Vector(0,1,0),
                mat
            ),
            * new Triangle(
                *new Vector(-1,0,0),
                *new Vector(0,0,1),
                *new Vector(0,-1,0),
                mat
            ),
            * new Triangle(
                *new Vector(0,1,0),
                *new Vector(0,0,1),
                *new Vector(0,-1,0),
                mat
            ),
            * new Triangle(
                *new Vector(0,1,0),
                *new Vector(-1,0,0),
                *new Vector(0,-1,0),
                mat
            ),
        };
        setPosition(position);
    }

    void setPosition(Vector& p) {
        Vector currentPos = calculatePosition();
        Vector translation = p - currentPos;
        for (Triangle& tri : tris) {
            tri.p1 = tri.p1 + translation;
            tri.p2 = tri.p2 + translation;
            tri.p3 = tri.p3 + translation;
        }
        position = calculatePosition();
    }

    Intersection doesIntersect(Ray& ray) {
        Intersection closest;
        for (Triangle& tri : tris) {
            Intersection triHit = tri.doesIntersect(ray);
            closest = triHit.t < closest.t ? triHit : closest;
        }
        return closest;
    }

    void print() {
        std::cout << "This is a tetrahedron with triangles:" << std::endl;
        for (Triangle& tri : tris) {
            tri.print();
        }
        std::cout << "Centered at:" << std::endl;
        position.print();
    }
};