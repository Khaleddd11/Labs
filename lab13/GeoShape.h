#ifndef GEOSHAPE_H
#define GEOSHAPE_H

class GeoShape {

    
public:
    double dim1;
    double dim2;

    GeoShape() ;

    void setDim1(double d); 
    void setDim2(double d) ;

    double getDim1() ;
    double getDim2() ;

    virtual double calculateArea(); 
};
#endif