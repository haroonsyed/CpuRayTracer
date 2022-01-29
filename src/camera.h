#pragma once
class camera
{

private:
    const int width = 128; // keep it in powers of 2!
    const int height = 128; // keep it in powers of 2!

    unsigned char* image = nullptr;

public:
	camera();
	~camera();

	unsigned char* renderImage();


};

