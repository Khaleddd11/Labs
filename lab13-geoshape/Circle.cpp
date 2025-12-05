#include "Circle.h"
#include "GeoShape.h"



Circle::Circle(float radius) : GeoShape(radius) {}
float Circle::calculateArea() {
    return 3.14159f * dim1 * dim2;
}
void Circle::setRadius(float radius) {
    dim1 = dim2 = radius;
}
float Circle::getRadius() {
    return dim1;
}