    #include "GeoShape.h"

    GeoShape::GeoShape(): dim1(0), dim2(0) {}
    GeoShape::GeoShape(float d1, float d2): dim1(d1), dim2(d2) {}
    GeoShape::GeoShape(float d): dim1(d), dim2(d) {}

    void GeoShape::setDim1(float d1) {
        dim1 = d1;
    }
    void GeoShape::setDim2(float d2) {
        dim2 = d2;
    }
    float GeoShape::getDim1() {
        return dim1;
    }
    float GeoShape::getDim2() {
        return dim2;
    }
    float GeoShape::calculateArea() {
        return 0.0;
    }