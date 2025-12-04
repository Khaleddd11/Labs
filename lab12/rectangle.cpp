#include "rectangle.h"
#include <SDL2/SDL.h>

// default constructor - creates 0x0 rectangle at origin
Rectangle::Rectangle() : topLeft(Point()), width(0), height(0) {}

// parameterized constructor
Rectangle::Rectangle(const Point& topLeftPoint, int w, int h)
    : topLeft(topLeftPoint), width(w), height(h) {}

// getters
const Point& Rectangle::getTopLeft() const { return topLeft; }
int Rectangle::getWidth() const { return width; }
int Rectangle::getHeight() const { return height; }

// setters
void Rectangle::setTopLeft(const Point& topLeftPoint) { topLeft = topLeftPoint; }
void Rectangle::setWidth(int w) { width = w; }
void Rectangle::setHeight(int h) { height = h; }

// draw the rectangle
void Rectangle::draw(SDL_Renderer* renderer) const {
    if (!renderer) return;
    
    // set color to green for rectangles
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    
    // create SDL_Rect structure
    SDL_Rect rect;
    rect.x = topLeft.getX();
    rect.y = topLeft.getY();
    rect.w = width;
    rect.h = height;
    
    // draw rectangle outline
    SDL_RenderDrawRect(renderer, &rect);
    
    // if you want filled rectangle, use:
    // SDL_RenderFillRect(renderer, &rect);
}