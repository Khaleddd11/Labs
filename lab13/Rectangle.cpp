#include "Rectangle.h"

Rectangle::Rectangle(double width, double height) {
    dim1 = width;
    dim2 = height;
}

double Rectangle::calculateArea() {
    return dim1 * dim2;
}