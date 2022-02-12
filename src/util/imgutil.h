#pragma once
#include <iostream>
#include <string>
#include "lodepng.h"

class ImgUtil {
private:
public:
	void saveFrame(unsigned char* data, const int width, const int height, std::string name) {
        std::vector<unsigned char> img_buffer;

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                //std::cout << i << " " << j << std::endl;
                int idx = ((height - i - 1) * width + j) * 3;
                img_buffer.push_back(data[idx]);
                img_buffer.push_back(data[idx + 1]);
                img_buffer.push_back(data[idx + 2]);
                img_buffer.push_back(255);

            }
        }

        name = name + ".png";
        unsigned error = lodepng::encode(name, img_buffer, width, height);
        //if there's an error, display it
        if (error) std::cout << "encoder error " << error << ": " << lodepng_error_text(error) << std::endl;
	}
};