#pragma once
#include <vector>
#include "../lights/light.h"
#include "../objects/sceneobj.h"

class Scene
{
private:
	int maxRecursions = 2;
public:
	const double ambientCoeff;
	Scene(std::vector<SceneObj*>& objects, std::vector<Light*>& lights);
	std::vector<SceneObj*> objects;
	std::vector<Light*> lights;
	Pixel render(Ray& ray, int depth); //Depth is used for limiting recursion level
};
