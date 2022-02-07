#pragma once
#include <vector>
#include "../objects/sceneobj.h"
#include "../lights/light.h"

class Scene
{
private:

public:
	const double ambientCoeff = 0.02;
	Scene(std::vector<SceneObj*>& objects, std::vector<Light*>& lights) {
		this->objects = objects;
		this->lights = lights;
	}
	std::vector<SceneObj*> objects;
	std::vector<Light*> lights;
};
