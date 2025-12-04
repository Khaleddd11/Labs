#include <iostream>
#include "Triangle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Circle.h"

using namespace std;

int main() {
    Triangle myTriangle(10, 5);
    cout << "Triangle Area: " << myTriangle.calculateArea() << endl;

    Rectangle myRect(10, 20);
    cout << "Rectangle Area: " << myRect.calculateArea() << endl;

    Square mySquare(4);
    cout << "Square Area: " << mySquare.calculateArea() << endl;

    Circle myCircle(5);
    cout << "Circle Area: " << myCircle.calculateArea() << endl;

    return 0;
}