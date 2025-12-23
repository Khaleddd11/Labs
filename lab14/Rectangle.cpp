#include <iostream>
#include "Shape.cpp"
#include "Point.cpp"

using namespace std;

class Rectangle : public Shape {
    Point width;
    Point height;

    public:
    Rectangle():width(), height(){}
    Rectangle(int x, int y, int a , int b):width(x,y),height(a,b){}

    void draw(){
        cout<< "Drawing A Rectangle";
    };

}; 