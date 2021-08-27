#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED

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

#endif // TOOLS_H_INCLUDED
