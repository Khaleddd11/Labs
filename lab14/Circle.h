#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include "Shape.h"
#include "Point.h"

class Circle : public Shape {
    Point point1;
    int radius;
public:
    Circle(int x, int y, int z) : point1(x, y), radius(z) {
        std::cout<<"circle constructor";
    }

    void draw() {
        std::cout << "Drawing a Circle!!" << std::endl;
    }
};

#endif