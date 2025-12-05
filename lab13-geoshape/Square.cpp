#include "Square.h"


Square::Square(float r): Rectangle(r,r){}

void Square::setSquareDim( float r) {
    dim1=r;
    dim2=r;
}
float Square::getSquareDim(){
    return dim1;
}

float Square::calculateArea(){
    return Rectangle::calculateArea();

}

