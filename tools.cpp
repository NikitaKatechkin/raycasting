#include "tools.h"

Coordinate coordinate(float x, float y)
{
    Coordinate res = {x , y};
    return res;
}

View view(float angle, float field_of_view)
{
    View res = {angle , field_of_view};
    return res;
}

Phys_size phys_size(size_t width, size_t height)
{
    Phys_size res = {width, height};
    return res;
}

uint32_t pack_color(const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a)
{
    return (a << 24) + (b << 16) + (g << 8) + r;
}

void unpack_color(const uint32_t &color, uint8_t &r, uint8_t &g, uint8_t &b, uint8_t &a)
{
    r = (color >> 0) & 255;
    g = (color >> 8) & 255;
    b = (color >> 16) & 255;
    a = (color >> 24) & 255;
}

void drop_ppm_image(const std::string filename, const std::vector<uint32_t> &image, const size_t width, const size_t height)
{
    assert(image.size() == width * height);
    std::ofstream ofs(filename);
    ofs << "P6\n" << width << " " << height << "\n255\n";
    for (size_t pxIndex = 0; pxIndex < height * width; pxIndex++)
    {
        uint8_t r, g, b, a;
        unpack_color(image[pxIndex], r, g, b, a);
        ofs << static_cast<char>(r) << static_cast<char>(g) << static_cast<char>(b);
    }
    ofs.close();
}

void draw_rectangle(std::vector<uint32_t> &image, const size_t image_width, const size_t image_height,
                    const size_t x, const size_t y, const size_t width, const size_t height, const uint32_t color)
{
    assert(image.size() == image_width * image_height);
    for (size_t rect_row = 0; rect_row < height; rect_row++)
    {
        for (size_t rect_col = 0; rect_col < width; rect_col++)
        {
            size_t current_row = y + rect_row;
            size_t current_col = x + rect_col;
            //assert(current_col < image_width && current_row < image_height);
            if (current_col >= image_width || current_row >=image_height)
            {
                continue;
            }
            image[current_col + current_row * image_width] = color;
        }
    }
}
