#ifndef CIRCLE_H
#define CIRCLE_H
#include "GeoShape.h"

// Inherits privately from GeoShape
class Circle : private GeoShape {
public:
    Circle(double radius);
    void setRadius(double radius);
    double getRadius();
    double calculateArea();
};

#endif