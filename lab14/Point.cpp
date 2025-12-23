class Point{
    int point1;
    int point2;
    public:
    Point(int x, int y){
        point1=x;
        point2=y;
    }
    Point (int x){
        point1=point2=x;
    }
    Point(){
        point1=point2=0;
    }
    // getters
int getPoint1() const { return point1; }
int getPoint2() const { return point2; }

// setters
void setPoint1(int point1Val)
 { point1 = point1Val; }
void setPoint2(int point2Val)
 { point2 = point2Val; }
};