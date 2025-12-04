#ifndef LINE_H
#define LINE_H

#include "shape.h"
#include "point.h"

// Line class - represents a line segment between two points
class Line : public Shape {
private:
    Point start;    // starting point
    Point end;      // ending point
    
public:
    // constructors
    Line();
    Line(const Point& startPoint, const Point& endPoint);
    
    // getters
    const Point& getStart() const;
    const Point& getEnd() const;
    
    // setters
    void setStart(const Point& startPoint);
    void setEnd(const Point& endPoint);
    
    // draw method
    void draw(SDL_Renderer* renderer) const override;
};

#endif