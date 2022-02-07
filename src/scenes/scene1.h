#include "scene.h"
#include "../objects/triangle.h"
#include "../objects/tetrahedron.h"

// I'm pretty sure this is not conventional, but I don't know a better way
// Making some sort of file parsing might work, but is unrelated to the goals of this project
Scene scene1 = Scene (
     *new std::vector<SceneObj*>{
        new Sphere(
            *new Vector(40, 1, -2.3),
            1,
            *new Material(0,0,255)
        ),
        new Sphere(
            *new Vector(30, 3, -2.3),
            1.5,
            *new Material(0,255,0)
        ),
        new Tetrahedron(
            *new Vector(13,1.5,-4),
            *new Material(255,0,0)
        )
    }
,
    *new std::vector<Light*>{
        new Light(
            *new Vector(0,0,-20),
            0.9
        )
    }
);