#include "scene.h"
#include "../objects/sphere.h"
#include "../objects/tetrahedron.h"

// I'm pretty sure this is not conventional, but I don't know a better way
// Making some sort of file parsing might work, but is unrelated to the goals of this project
Scene scene1 = Scene (
     *new std::vector<SceneObj*>{
        new Sphere(
            *new Vector(20, -3, -1),
            1,
            *new Material(0,0,255,1, 300, 0)
        ),
        new Sphere(
            *new Vector(20, 0, 2),
            1,
            *new Material(0,0,0,0.1, 1000, 0.6)
        ),
        new Sphere(
            *new Vector(20, 0, -1),
            1,
            *new Material(0,255,0)
        ),
        new Tetrahedron(
            *new Vector(20,3,-1.2),
            *new Material(255,0,0, 1, 100, 0)
        ),
        // Reflective floor
        new Triangle(
            *new Vector(1000,0,-2),
            *new Vector(-1000,-100,-2),
            *new Vector(-1000,100,-2),
            *new Material(200,200,200,0.3,0,0.2)
        ),
    }
,
    *new std::vector<Light*>{
        new Light( 
            //Being far away simulates directional light
            *new Vector(-3000,2000,4000),
            1
        ),
    }
);