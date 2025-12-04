#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
#include "point.h"

// Rectangle class - defined by top-left corner, width, and height
class Rectangle : public Shape {
private:
    Point topLeft;    // top-left corner position
    int width;        // width in pixels
    int height;       // height in pixels
    
public:
    // constructors
    Rectangle();
    Rectangle(const Point& topLeftPoint, int w, int h);
    
    // getters
    const Point& getTopLeft() const;
    int getWidth() const;
    int getHeight() const;
    
    // setters
    void setTopLeft(const Point& topLeftPoint);
    void setWidth(int w);
    void setHeight(int h);
    
    // draw method
    void draw(SDL_Renderer* renderer) const override;
};

#endif