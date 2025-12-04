#include "line.h"
#include <SDL2/SDL.h>

// default constructor - creates line from origin to origin
Line::Line() : start(Point()), end(Point()) {}

// parameterized constructor
Line::Line(const Point& startPoint, const Point& endPoint)
    : start(startPoint), end(endPoint) {}

// getters
const Point& Line::getStart() const { return start; }
const Point& Line::getEnd() const { return end; }

// setters
void Line::setStart(const Point& startPoint) { start = startPoint; }
void Line::setEnd(const Point& endPoint) { end = endPoint; }

// draw the line
void Line::draw(SDL_Renderer* renderer) const {
    if (!renderer) return;
    
    // set color to white for lines
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    
    // draw line from start to end
    SDL_RenderDrawLine(renderer, 
                       start.getX(), start.getY(), 
                       end.getX(), end.getY());
}