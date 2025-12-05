#ifndef GEOSHAPE_H  
#define GEOSHAPE_H  

class GeoShape {
protected:
    float dim1, dim2;

public:
    GeoShape();
    GeoShape(float d1, float d2);
    GeoShape(float d);

    void setDim1(float d1);
    void setDim2(float d2);
    float getDim1();
    float getDim2() ;
    float calculateArea();
};

#endif  