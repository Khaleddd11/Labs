#include <iostream>
#include "Shape.cpp"
#include "Point.cpp"


class Square :public Shape{
    Point point1;
    public:
    Square(int x, int y ) : point1(x,y){
        std::cout<< "Square constructor";
        
    };
     void draw(){
        std::cout<<"Drawing a Sqaure!!";
     };




};