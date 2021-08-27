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
