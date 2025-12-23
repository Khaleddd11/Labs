#ifndef POINT_H
#define POINT_H

class Point {
    int point1;
    int point2;
public:
    Point(int x, int y) : point1(x), point2(y) {}
    Point(int x) : point1(x), point2(x) {}
    Point() : point1(0), point2(0) {}

    // Getters
    int getPoint1() const { return point1; }
    int getPoint2() const { return point2; }
};

#endif