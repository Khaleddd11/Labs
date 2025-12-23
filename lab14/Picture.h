#ifndef PICTURE_H
#define PICTURE_H

#include "Shape.h" 

class Picture {
    Shape** shapes;
    int size;
    int count;

public:
    Picture(int s);
    void addShape(Shape* s);
    void draw();
};

#endif