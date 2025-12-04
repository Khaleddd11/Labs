#include "Square.h"

// Pass 'side' to the Rectangle parent constructor
Square::Square(double side) : Rectangle(side, side) {}

void Square::setSquareSide(double side) {
    setDim1(side);
    setDim2(side);
}

double Square::getSquareSide() {
    return getDim1();
}

double Square::calculateArea() {
    // Call the parent Rectangle's function
    return Rectangle::calculateArea();
}