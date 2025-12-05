#include "Rectangle.h"
#include "GeoShape.h"
Rectangle::Rectangle(float length, float width): GeoShape(length,width){}
float Rectangle::calculateArea() {
    return dim1 * dim2;
}