#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include "Shape.h"
#include "Point.h"

class Square : public Shape {
    Point point1;
public:
    Square(int x, int y) : point1(x, y) {
        std::cout << "Square constructor" << std::endl;
    }
    void draw() {
        std::cout << "Drawing a Square!!" << std::endl;
    }
};

#endif