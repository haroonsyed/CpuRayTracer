#include "light.h"

Light::Light(Vector& position, double intensity) {
	this->position = position;
	this->intensity = intensity;
	this->lightType = LIGHT_TYPE::DIRECTIONAL;
}

Light::Light(Vector& position, double intensity, LIGHT_TYPE type) {
	this->position = position;
	this->intensity = intensity;
	this->lightType = type;
}
