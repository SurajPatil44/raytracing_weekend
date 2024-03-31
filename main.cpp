#include "color.h"
#include "ray.h"
#include "vec3.h"

#include<iostream>

color ray_color(const ray& r){
    vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - a) * color(1.0,1.0,1.0) + a * color(0.5,0.7,1.0);
}

int main() {

    //const int im_width = 256;
    auto aspect_ratio = 16.0 / 9.0;
    int im_width = 400;
    int im_height = static_cast<int>(im_width / aspect_ratio); 
    im_height = (im_height < 1)? 1 :im_height;

    //Camera
    auto focal_length = 1.0;
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (static_cast<double>(im_width)/im_height);
    auto camera_center = point3(0,0,0);

    //calculate vectors across the horizontal and down the vertical
    auto viewport_u = vec3(viewport_width,0,0);
    auto viewport_v = vec3(0,-viewport_height,0);

    //pixel delta
    auto pixel_delta_u = viewport_u / im_width;
    auto pixel_delta_v = viewport_v / im_height;

    //upper left pixel
    auto viewport_upper_left = camera_center - vec3(0,0,focal_length) - viewport_u/2 - viewport_v/2;
    auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);
    
    std::cout << "P3\n" << im_width << ' ' << im_height << "\n255\n";

    for(int j=im_height-1;j >=0;--j) {
        std::cerr << "\rScanline remaining: " << j << ' ' << std::flush;
        for (int i = 0;i < im_width;++i) {
            auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            auto ray_direction = pixel_center - camera_center;
            ray r(camera_center,ray_direction);
            //color pixel_color(double(i * 0.5)/(im_width-1),double(j)/(im_height-1),0.50);
            color pixel_color = ray_color(r);
            write_color(std::cout,pixel_color);

        }
    }

    std::clog << "\nDone.\n";
}

