#pragma once

class Pixel {
public:
	unsigned char r;
	unsigned char g;
	unsigned char b;
	Pixel(unsigned char r, unsigned char g, unsigned char b) {
		this->r = r;
		this->g = g;
		this->b = b;
	}
	Pixel(const Pixel& old) {
		r = old.r;
		g = old.g;
		b = old.b;
	}
};