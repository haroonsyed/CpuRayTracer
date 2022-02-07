#pragma once
#include <vector>
#include "../objects/sceneobj.h"
#include "../lights/light.h"

class Scene
{
private:

public:
	Scene(std::vector<SceneObj*>& objects, std::vector<Light*>& lights) {
		this->objects = objects;
		this->lights = lights;
	}
	std::vector<SceneObj*> objects;
	std::vector<Light*> lights;
};
