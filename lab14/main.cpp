#include <iostream>
#include "Picture.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"

using namespace std;

int main() {
    Picture myPic(5);
    
    myPic.addShape(new Circle(0, 0, 10));
    myPic.addShape(new Rectangle(10, 10, 20, 20));
    myPic.addShape(new Square(5, 5));
    
    myPic.draw();
    
    return 0;
}