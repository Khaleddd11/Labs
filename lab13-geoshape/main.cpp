#include <iostream>
#include "GeoShape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Square.h"


int main() {
    // Create instances of each shape
    Circle circle(5.0f);          // radius = 5.0
    Rectangle rectangle(4.0f, 6.0f); // length = 4.0, width = 6.0
    Triangle triangle(3.0f, 7.0f);   // base = 3.0, height = 7.0
    Square square(4.0f);           // side length = 4.0

    // Calculate and display areas
    std::cout << "Circle Area: " << circle.calculateArea() << std::endl;
    std::cout << "Rectangle Area: " << rectangle.calculateArea() << std::endl;
    std::cout << "Triangle Area: " << triangle.calculateArea() << std::endl;
    std::cout << "Square Area: " << square.calculateArea() << std::endl;

    return 0;
}