#include "Triangle.h"

Triangle::Triangle(double base, double height) {
    dim1 = base;
    dim2 = height;
}

double Triangle::calculateArea() {
    return 0.5 * dim1 * dim2;
}