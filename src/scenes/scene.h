#pragma once
#include <vector>
#include "../lights/light.h"
#include "../objects/sphere.h"
#include "../objects/tetrahedron.h"
#include "../pixel.h"

class Scene
{
private:
	int maxRecursions = 3;
	bool enableShadows = true;

	//Background color
	Pixel back1 = Pixel(100, 171, 255);
	Pixel back2 = Pixel(255, 255, 255);

public:
	const double ambientCoeff;
	Scene(std::vector<SceneObj*>& objects, std::vector<Light*>& lights);
	std::vector<SceneObj*> objects;
	std::vector<Light*> lights;
	Pixel render(Ray& ray, int depth); //Depth is used for limiting recursion level
};
