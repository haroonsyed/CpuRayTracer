#pragma once

class Material {
public:
	unsigned char r;
	unsigned char g;
	unsigned char b;
	// Range between 0 and 1
	double diffuse;
	// While usually above one. My program ties ks and phong exponent for one control. 
	// Disabling specular means having a specular of 0, else it should be above 1.
	double specular;
	double phongExp;
	double mirror;
	Material() {
		r = 255;
		g = 255;
		b = 255;
		diffuse = 1;
		specular = 0;
		phongExp = 1;
		mirror = 0;
	}
	Material(unsigned char r, unsigned char g, unsigned char b) {
		this->r = r;
		this->g = g;
		this->b = b;
		diffuse = 1;
		specular = 0;
		phongExp = 1;
		mirror = 0;
	}
	Material(unsigned char r, unsigned char g, unsigned char b, double diffuse, double phongExponent, double mirror) {
		this->r = r;
		this->g = g;
		this->b = b;
		this->diffuse = diffuse;
		this->specular = phongExponent <= 1 ? 0 : 1;
		this->phongExp = phongExponent;
		this->mirror = mirror;
	}
	void print() {
		std::cout << "R " << (int)r << " B " << (int)b << " G " << (int)g << std::endl;
	}
};