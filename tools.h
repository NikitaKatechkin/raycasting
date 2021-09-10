#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <cassert>
#include <math.h>
#include <stdlib.h>

struct View
{
    float angle;
    float field_of_view;
};

View view(float angle, float field_of_view);
#endif // TOOLS_H_INCLUDED
