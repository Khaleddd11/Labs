#include "Triangle.h"
#include "GeoShape.h"

Triangle::Triangle(float base, float height): GeoShape(base, height) {}
float Triangle::calculateArea() {
    return 0.5 * dim1 * dim2;
}