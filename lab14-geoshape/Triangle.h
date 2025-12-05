#include "GeoShape.h"
#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle : public GeoShape{
    public:
    Triangle(float base, float height);
    float calculateArea();

};

#endif