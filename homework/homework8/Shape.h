#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
using namespace std;

class Shape
{
    public:
        Shape();
        virtual float get_area();
        virtual float get_volumn();


};

#endif