#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include "Shape.h"
#include "Point.h"

class Triangle : public Shape {
    Point p1;
    Point p2;
    Point p3;
public:
    Triangle(int a, int b, int c, int d, int e, int f) 
        : p1(a, b), p2(c, d), p3(e, f) {
        std::cout << "Triangle constructor" << std::endl;
    }
    void draw() {
        std::cout << "Drawing a Triangle!!" << std::endl;
    }
};

#endif