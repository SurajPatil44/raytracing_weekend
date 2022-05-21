#include "color.h"
#include "vec3.h"

#include<iostream>


int main() {

    const int im_width = 256;
    const int im_height = 256;

    std::cout << "P3\n" << im_width << ' ' << im_height << "\n255\n";

    for(int j=im_height-1;j >=0;--j) {
        std::cerr << "\rScanline remaining: " << j << ' ' << std::flush;
        for (int i = 0;i < im_width;++i) {
            color pixel_color(double(i * 0.5)/(im_width-1),double(j)/(im_height-1),0.50);
            write_color(std::cout,pixel_color);

        }
    }

    std::cout << "\nDone.\n";
}

