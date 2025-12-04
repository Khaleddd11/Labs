#ifndef POINT_H
#define POINT_H

#include "shape.h"

// Point class - represents x,y coordinate
class Point : public Shape {
private:
    int x;
    int y;
    
public:
    // constructors
    Point();
    Point(int xVal, int yVal);
    
    // getters
    int getX() const;
    int getY() const;
    
    // setters
    void setX(int xVal);
    void setY(int yVal);
    
    // draw method - draws a single pixel
    void draw(SDL_Renderer* renderer) const override;
};

#endif