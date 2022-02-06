#pragma once
#include <vector>
#include "../objects/sceneobj.h"

class Scene
{
private:

public:
	Scene(std::vector<SceneObj*> objects) {
		this->objects = objects;
	}
	std::vector<SceneObj*> objects;
	std::vector<
};

