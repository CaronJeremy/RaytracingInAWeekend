#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

#include <iostream>

using color = vec3;

void write_color(unsigned char* const pixel_adr, const color& pixel_color) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // Translate the [0,1] component values to the byte range [0,255].
    int rbyte = int(255.999 * r);
    int gbyte = int(255.999 * g);
    int bbyte = int(255.999 * b);

    // Write out the pixel color components.
    //put the rbg values in the corresponding memory slot
    *pixel_adr = rbyte;
    *(pixel_adr + 1) = gbyte;
    *(pixel_adr + 2) = bbyte;
}

#endif