#include <iostream>
#include "Picture.h" 

using namespace std;

// Constructor
Picture::Picture(int s) {
    size = s;
    count = 0;
    shapes = new Shape*[size];
}

// Draw Function
void Picture::draw() {
    for (int i = 0; i < count; i++) {
        shapes[i]->draw();
    }
}

// Add Function 
void Picture::addShape(Shape* s) {
    if (count < size) {
        shapes[count] = s;
        count++;
    } 
    else {
        //  resize 
        int newsize = size * 2;
        Shape** newshapes = new Shape*[newsize];
        
        for (int i = 0; i < size; i++) {
            newshapes[i] = shapes[i];
        }
        
        delete[] shapes;
        shapes = newshapes;
        size = newsize;
        
        shapes[count] = s;
        count++;
    }
}