#include "TwodimensionalShape.h"
#include <iostream>
using namespace std;

TwodimensionalShape::TwodimensionalShape(float x_val, float y_val)
{
    x = x_val;
    y = y_val;
}

float TwodimensionalShape::get_x()
{
    return x;
}

float TwodimensionalShape::get_y()
{
    return y;
}

void TwodimensionalShape::set_x(float x_val)
{
    x = x_val;
}

void TwodimensionalShape::set_y(float y_val)
{
    y = y_val;
}