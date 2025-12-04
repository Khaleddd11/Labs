#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include "point.h"

// Circle class - defined by center point and radius
class Circle : public Shape {
private:
    Point center;     // center point of circle
    double radius;    // radius in pixels
    
public:
    // constructors
    Circle();
    Circle(const Point& centerPoint, double radiusValue);
    
    // getters
    const Point& getCenter() const;
    double getRadius() const;
    
    // setters
    void setCenter(const Point& centerPoint);
    void setRadius(double radiusValue);
    
    // draw method
    void draw(SDL_Renderer* renderer) const override;
};

#endif