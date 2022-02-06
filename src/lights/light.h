#pragma once
#include "../math/vector.h"

enum class LIGHT_TYPE { DIRECTIONAL, POINT, AREA };
class Light {

private:
	int r = 255;
	int g = 255;
	int b = 255;

public:
	LIGHT_TYPE lightType = LIGHT_TYPE::DIRECTIONAL;
	double intensity = 1;
	Vector position = Vector(0,0,0); //Used for light direction if directional
	Light(Vector&, double);
	Light(Vector&, double, LIGHT_TYPE);

};