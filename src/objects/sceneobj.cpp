#include "sceneobj.h"
#include "sceneobj.h"

SceneObj::SceneObj(Material& mat) : position{ 0,0,0 }, mat{} {
	this->mat = mat;
}

SceneObj::SceneObj(Vector& p, Material& mat) : position{ 0,0,0 }, mat{} {
	position = p;
	this->mat = mat;
}