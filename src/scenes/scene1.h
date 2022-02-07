#include "scene.h"
#include "../objects/sphere.h"
#include "../objects/tetrahedron.h"

// I'm pretty sure this is not conventional, but I don't know a better way
// Making some sort of file parsing might work, but is unrelated to the goals of this project
Scene scene1 = Scene (
     *new std::vector<SceneObj*>{
        new Sphere(
            *new Vector(120, 0, 2),
            2,
            *new Material(0,0,255,0.9,1000)
        ),
        new Sphere(
            *new Vector(30, 2, 0),
            1,
            *new Material(0,255,0)
        ),
        new Tetrahedron(
            *new Vector(40,-2.5,-1),
            *new Material(255,0,0)
        )
    }
,
    *new std::vector<Light*>{
        new Light( // Main light
            *new Vector(0,40,0),
            0.5
        ),
        new Light( // Back light
            *new Vector(100,-20,0),
            0.5
        ),
        new Light( //Side light
            *new Vector(0,0,5),
            0.3
        )
    }
);