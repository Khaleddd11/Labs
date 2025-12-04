#include "circle.h"
#include <cmath>
#include <SDL2/SDL.h>

// default constructor - creates circle at origin with radius 0
Circle::Circle() : center(Point()), radius(0.0) {}

// parameterized constructor
Circle::Circle(const Point& centerPoint, double radiusValue)
    : center(centerPoint), radius(radiusValue) {}

// getters
const Point& Circle::getCenter() const { return center; }
double Circle::getRadius() const { return radius; }

// setters
void Circle::setCenter(const Point& centerPoint) { center = centerPoint; }
void Circle::setRadius(double radiusValue) { radius = radiusValue; }

// draw the circle using Midpoint Circle Algorithm (Bresenham's)
void Circle::draw(SDL_Renderer* renderer) const {
    if (!renderer) return;
    
    // set color to yellow for circles
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    
    // convert radius to int
    const int radiusInt = static_cast<int>(std::round(radius));
    const int diameter = radiusInt * 2;
    
    // midpoint circle algorithm variables
    int x = radiusInt - 1;
    int y = 0;
    int tx = 1;
    int ty = 1;
    int error = tx - diameter;
    
    // get center coordinates
    const int cx = center.getX();
    const int cy = center.getY();
    
    // draw circle using 8-way symmetry
    while (x >= y) {
        // draw 8 symmetric points
        SDL_RenderDrawPoint(renderer, cx + x, cy - y);
        SDL_RenderDrawPoint(renderer, cx + x, cy + y);
        SDL_RenderDrawPoint(renderer, cx - x, cy - y);
        SDL_RenderDrawPoint(renderer, cx - x, cy + y);
        SDL_RenderDrawPoint(renderer, cx + y, cy - x);
        SDL_RenderDrawPoint(renderer, cx + y, cy + x);
        SDL_RenderDrawPoint(renderer, cx - y, cy - x);
        SDL_RenderDrawPoint(renderer, cx - y, cy + x);
        
        if (error <= 0) {
            ++y;
            error += ty;
            ty += 2;
        }
        
        if (error > 0) {
            --x;
            tx += 2;
            error += tx - diameter;
        }
    }
}