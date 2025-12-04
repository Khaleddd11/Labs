#include "point.h"
#include <SDL2/SDL.h>

// default constructor - creates point at origin (0,0)
Point::Point() : x(0), y(0) {}

// parameterized constructor
Point::Point(int xVal, int yVal) : x(xVal), y(yVal) {}

// getters
int Point::getX() const { return x; }
int Point::getY() const { return y; }

// setters
void Point::setX(int xVal) { x = xVal; }
void Point::setY(int yVal) { y = yVal; }

// draw a single pixel at this point
void Point::draw(SDL_Renderer* renderer) const {
    if (!renderer) return;
    
    // set color to red for points
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    
    // draw single pixel
    SDL_RenderDrawPoint(renderer, x, y);
}