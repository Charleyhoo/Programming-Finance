#ifndef TWODIMENTIONALSHAPE_H
#define TWODIMENTIONALSHAPE_H

#include"Shape.h"


class TwodimensionalShape : public Shape {
    public:
    TwodimensionalShape(float x_val, float y_val);
    float get_x();
    void set_x(float x_val);
    float get_y();
    void set_y(float y_val);

    private:
    float x;
    float y;

};

#endif