#ifndef SQUARE_H
#define SQUARE_H
#include "Rectangle.h"

// Inherits privately from Rectangle
class Square : private Rectangle {
public:
    Square(double side);
    void setSquareSide(double side);
    double getSquareSide();
    double calculateArea();
};

#endif