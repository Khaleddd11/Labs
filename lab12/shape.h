#ifndef SHAPE_H
#define SHAPE_H

#include <SDL2/SDL.h>

// This is an "Abstract Base Class".
// You cannot create a variable of type "Shape".
// You can only create classes that INHERIT from this (like Point, Circle).
class Shape {
public:
    virtual void draw(SDL_Renderer* renderer) const = 0;

    // "virtual destructor" is important here
    // It ensures that if we delete a "Shape*"
    // Prevents memory leaks.
    virtual ~Shape() {}              
};

#endif