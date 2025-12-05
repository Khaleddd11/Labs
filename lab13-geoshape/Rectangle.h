#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "GeoShape.h"

class Rectangle: public GeoShape{
    public:
    Rectangle(float length, float width);
    float calculateArea();
};

#endif