#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <cassert>
#include <math.h>

struct Coordinate
{
    float x_coordinate;
    float y_coordinate;
};

struct View
{
    float angle;
    float field_of_view;
};

struct Phys_size
{
    size_t width;
    size_t height;
};

Coordinate coordinate(float x, float y);

View view(float angle, float field_of_view);

Phys_size phys_size(size_t width, size_t height);

uint32_t pack_color(const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a = 255);

void unpack_color(const uint32_t &color, uint8_t &r, uint8_t &g, uint8_t &b, uint8_t &a);

void drop_ppm_image(const std::string filename, const std::vector<uint32_t> *image, const size_t width, const size_t height);

void draw_rectangle(std::vector<uint32_t> *image, const size_t image_width, const size_t image_height,
                    const size_t x, const size_t y, const size_t width, const size_t height, const uint32_t color);
#endif // TOOLS_H_INCLUDED
