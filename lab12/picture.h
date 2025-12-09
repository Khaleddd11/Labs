#ifndef PICTURE_H
#define PICTURE_H

#include "shape.h"
#include <vector>
#include <SDL2/SDL.h> 

// Picture class - holds collection of shapes
// uses polymorphism to store different shape types
class Picture {
private:

// CORE CONCEPT: Vector of Pointers
// We use std::vector<Shape*> instead of std::vector<Shape>
// because storing derived objects (Circle, Rectangle, Point)
// inside a base-class variable (Shape) causes "Object Slicing".

// Object Slicing Explanation:
// When a derived class object is assigned to a base class variable,
// the extra data/functions of the derived part are removed (sliced off).
// Example:
//     Shape s = Circle();    //  Circle-specific data is lost
//
// To avoid this, we store POINTERS instead of actual objects.
// Example:
//     Shape* s = new Circle();  //  Full Circle object is preserved
//
// Using pointers lets us keep the entire derived object intact.
// This allows polymorphism to work correctly (virtual functions).
// It also allows us to store different shapes in the same vector.
//
// Therefore, this vector can store Circle*, Rectangle*, Point*, etc.
    std::vector<Shape*> shapes;  // array of shape pointers
    
public:
    // constructor and destructor
    Picture();
    ~Picture();
    
    // add shapes to picture
    void addShape(Shape* shape);
    
    // remove all shapes
    void clear();
    
    // draw all shapes
     
    // draw:
    // Calls the draw() function of every shape in the vector.
    // Polymorphism:
    //  - If shape is a Circle → calls Circle::draw()
    //  - If shape is a Rectangle → calls Rectangle::draw()
    //  - If shape is a Point → calls Point::draw()
    // SDL_Renderer* is used to draw on the screen.
    void draw(SDL_Renderer* renderer) const;
    
    // get number of shapes
    int getShapeCount() const;
};

#endif