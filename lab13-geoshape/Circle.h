#include "GeoShape.h"

#ifndef CIRCLE_H
#define CIRCLE_H

// what i was thinking about is that i want circle to inherate privatly from geopshape
// because in main method i dont want to say cicle.set1 or circle.setdim2
// becuase circle only has one dimension which is radius, so i want to hide the dim1 and dim2
// and only show radius method to set and get radius
class Circle : private GeoShape {
public:
    Circle(float radius);
    float calculateArea();
    void setRadius(float radius);
    float getRadius();
};
#endif 