#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "Shape.h"
#include "Point.h"

class Rectangle : public Shape {
    Point width;
    Point height;
public:
    Rectangle() : width(), height() {}
    Rectangle(int x, int y, int a, int b) : width(x, y), height(a, b) {}

    void draw() {
        std::cout << "Drawing A Rectangle" << std::endl;
    }
};

#endif