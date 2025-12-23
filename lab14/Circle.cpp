#include <iostream>
#include "Shape.cpp"
#include "Point.cpp"


class Circle: public Shape{
    Point point1;
    int radius;
    public:
     Circle(int x, int y, int z ): point1(x,y)
     {
        radius=z;
     }
     void draw(){
        std::cout<<"Drawing a Circle!!";
     };

};