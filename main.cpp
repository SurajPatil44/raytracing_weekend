#include<iostream>


int main() {

    const int im_width = 256;
    const int im_height = 256;

    std::cout << "P3\n" << im_width << ' ' << im_height << "\n255\n";

    for(int j=im_height-1;j >=0;--j) {
        std::cerr << "\rScanline remaining: " << j << ' ' << std::flush;
        for (int i = 0;i < im_width;++i) {
            auto r = double(i) / (im_width-1);
            auto g = double(j) / (im_height-1);
            auto b = 0.25;

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            std::cout << ir << ' ' << ig << ' ' << ib << '\n';

        }
    }

    std::cout << "\nDone.\n";
}

