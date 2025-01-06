#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image/stb_image_write.h"

int main() {

    // Image

    int image_width = 256;
    int image_height = 256;
    int image_channels = 3;

    // Render

    size_t image_size = image_width * image_height * image_channels;
    unsigned char* img = new unsigned char[image_size]; //allocate memory

    unsigned char* pixel = img;
    for (int j = 0; j < image_height; j++) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) {

            //rgb values from 0-1
            auto r = double(i) / (image_width - 1);
            auto g = double(j) / (image_height - 1);
            auto b = r*g;

            //rgb values from 0-255
            int ir = int(255.999 * r);
            int ig = int(255.999 * g);
            int ib = int(255.999 * b);

            //put the rbg values in the corresponding memory slot
            *pixel = ir;
            *(pixel + 1) = ig;
            *(pixel + 2) = ib;

            pixel += image_channels;
        }
    }

    stbi_write_jpg("image.jpg", image_width, image_height, 3, img, 199);
    delete[] img;
    std::clog << "\rDone.                 \n";
}