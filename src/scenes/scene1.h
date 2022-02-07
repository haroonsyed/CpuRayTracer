#include "scene.h"
#include "../objects/triangle.h"

// I'm pretty sure this is not conventional, but I don't know a better way
// Making some sort of file parsing might work, but is unrelated to the goals of this project
Scene scene1 = Scene (
     *new std::vector<SceneObj*>{
        new Sphere(
            *new Vector(30, 1, -2.3),
            1,
            *new Material(0,0,255)
        ),
        new Sphere(
            *new Vector(20, 3, -2.3),
            1,
            *new Material(0,255,0)
        ),
        new Triangle(
            *new Vector(15,3,-1),
            *new Vector(15,2,-3),
            *new Vector(20,2.2,-3),
            *new Material(255,0,0)
        )
    }
,
    *new std::vector<Light*>{
        new Light(
            *new Vector(0,0,0),
            0.8
        )
    }
);