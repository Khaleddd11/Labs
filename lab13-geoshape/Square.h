#include "Rectangle.h"

#ifndef SQUARE_H
#define SQUARE_H
    class Square: private Rectangle {
        public:
        Square(float r);
        void setSquareDim( float r);
        float getSquareDim();
        float calculateArea();
    };

    #endif