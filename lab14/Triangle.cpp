#include <iostream>
#include "Shape.cpp"
#include "Point.cpp"


class Triangle : public Shape{
    Point p1;
    Point p2;
    Point p3;


    public :
    Triangle(int a, int b, int c , int d , int e , int f):p1(a,b),p2(c,d),p3(e,f){
        std::cout<<"TRinagle cnstructor";
    };
    void draw(){
        std::cout<<"Drawing a Triangle!!";
     };

};