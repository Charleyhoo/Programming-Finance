#include "Circle.h"
#include<iostream>
using namespace std;

Circle::Circle (float x_val, float y_val, float radius_val):TwodimensionalShape(x_val,y_val){
    pi = 3.141592653589793;
    Circle::set_radius(radius_val);
}

float Circle::get_radius(){
    return radius;
}

void Circle::set_radius(float radius_val){
    if (radius_val>=0){
        radius = radius_val;
    
    }
    else{
        radius = 0;
        cout<<"Radius's value is less than 0"<<endl;
    }
}
//return the area of Circle
float Circle::get_area() {
    int area = pi * (Circle::get_radius()*Circle::get_radius());
    return area;
}