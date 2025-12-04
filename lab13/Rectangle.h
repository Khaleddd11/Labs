#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "GeoShape.h"

class Rectangle : public GeoShape {
public:
    Rectangle(double width, double height);
    double calculateArea();
};

#endif