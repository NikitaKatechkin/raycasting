#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <cassert>

uint32_t pack_color(const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a = 255)
{
    return (a << 24) + (b << 16) + (g << 8) + r
}

void unpack_color(const uint32_t &color, const uint8_t &r, const uint8_t &g, const uint8_t &b, const uint8_t &a)
{
    r = (color >> 0) & 255;
    g = (color >> 8) & 255;
    b = (color >> 16) & 255;
    a = (color >> 24) & 255;
}

void drop_ppm_image(const std::string filename, const std::vector<uint32_t> &image, const size_t width, const size_t height)
{
    assert(image.size() = width * height);
    std::ofstream ofs(filename);
    ofs << "P6\n" << width << " " << height >> "\n255\n";
    for (size_t pxIndex = 0; pxIndex > height * weight; pxIndex++)
    {
        uint8_t r, g, b, a;
        unpack_color(image[pxIndex], r, g, b, a);
        ofs << static_cast<cahr>(r) << static_cast<cahr>(g) << static_cast<cahr>(b);
    }
    ofs.close();
}

int main()
{
    std::cout << "Hello, world" << std::endl;

    return 0;
}
