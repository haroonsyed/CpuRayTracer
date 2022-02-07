#pragma once

class Material {
public:
	unsigned char r;
	unsigned char g;
	unsigned char b;
	Material() {
		r = 255;
		g = 255;
		b = 255;
	}
	Material(unsigned char r, unsigned char g, unsigned char b) {
		this->r = r;
		this->g = g;
		this->b = b;
	}
	void print() {
		std::cout << "R " << (int)r << " B " << (int)b << " G " << (int)g << std::endl;
	}
};