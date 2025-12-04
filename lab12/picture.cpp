#include "picture.h"

// constructor
Picture::Picture() {}

// destructor - must free all shape pointers
Picture::~Picture() {
    clear();
}

// add a shape to the picture
void Picture::addShape(Shape* shape) {
    if (shape) {
        shapes.push_back(shape);
    }
}

// clear all shapes and free memory
void Picture::clear() {
    // delete each shape
    for (Shape* shape : shapes) {
        delete shape;
    }
    // clear the vector
    shapes.clear();
}

// draw all shapes in the picture
void Picture::draw(SDL_Renderer* renderer) const {
    if (!renderer) return;
    
    // draw each shape using polymorphism
    // each shape knows how to draw itself
    for (const Shape* shape : shapes) {
        if (shape) {
            shape->draw(renderer);
        }
    }
}

// get number of shapes
int Picture::getShapeCount() const {
    return shapes.size();
}