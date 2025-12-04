#include "Circle.h"

Circle::Circle(double radius) {
    dim1 = radius;
    dim2 = radius;
}

void Circle::setRadius(double radius) {
    dim1 = radius;
    dim2 = radius;
}

double Circle::getRadius() {
    return dim1;
}

double Circle::calculateArea() {
    return 3.14 * dim1 * dim1;
}