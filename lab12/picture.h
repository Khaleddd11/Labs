#ifndef PICTURE_H
#define PICTURE_H

#include "shape.h"
#include <vector>
#include <SDL2/SDL.h> 

// Picture class - holds collection of shapes
// uses polymorphism to store different shape types
class Picture {
private:
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
    void draw(SDL_Renderer* renderer) const;
    
    // get number of shapes
    int getShapeCount() const;
};

#endif