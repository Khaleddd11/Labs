#include "GeoShape.h"

GeoShape::GeoShape() {
    dim1 = 0;
    dim2 = 0;
}

void GeoShape::setDim1(double d) {
    dim1 = d;
}

void GeoShape::setDim2(double d) {
    dim2 = d;
}

double GeoShape::getDim1() {
    return dim1;
}

double GeoShape::getDim2() {
    return dim2;
}

double GeoShape::calculateArea() {
    return 0;
}