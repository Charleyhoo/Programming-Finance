#ifndef CIRCLE_H
#define CIRCLE_H

#include "TwodimensionalShape.h"
#include <iostream>
using namespace std;

class Circle : public TwodimensionalShape
{
public:
    Circle(float x_val, float y_val, float radius_val);
    float get_radius();
    void set_radius(float radius_val);
    float get_area();

private:
    float radius;
    float pi;
};

#endif