#include "picture.h"

// constructor
Picture::Picture() {}

// destructor - must free all shape pointers
Picture::~Picture() {
    clear();
}

// add a shape to the picture

// addShape:
// Adds a new Shape pointer to the picture.
// shape can be a Circle*, Rectangle*, Point*, etc.
// Only adds if the pointer is not null.
void Picture::addShape(Shape* shape) {
    if (shape) {
        shapes.push_back(shape);
    }
}

// clear:
// Deletes ALL shapes stored in the vector.
// VERY IMPORTANT: shapes were created with 'new',
// so we must call 'delete' to free memory.
// After deleting, we empty the vector itself.
void Picture::clear() {
    // delete each shape object
    for (Shape* shape : shapes) {
        delete shape;      // frees memory for each shape
    }

    // remove all pointers from the vector
    shapes.clear();
}


// draw:
// Draws every shape in the picture onto the screen.
// Uses polymorphism:
//   shape->draw(renderer)
// calls the correct draw() function depending on the real type:
//   Circle::draw, Rectangle::draw, Point::draw, etc.
// If renderer is null, do nothing (safety check).
void Picture::draw(SDL_Renderer* renderer) const {
    if (!renderer) return;
    
    // draw each shape using polymorphism
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