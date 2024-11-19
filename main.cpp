#include <cassert>
#include <iostream>
#include <cmath>


class Point {

    double x,y;

public:

    Point () = default;

    Point (double X,double Y) {

        x = X;
        y = Y;
    }

    double operator- (const Point& compare) {

        return sqrt(pow((compare.x - this->x),2) + pow((compare.y - this->y),2));
    }

    bool operator== (const Point& compare) {

        if (this->x == compare.x && this->y == compare.y) return true;
        else return false;
    }

    bool operator!= (const Point& compare) {

        if (this->x != compare.x && this->y != compare.y) return true;
        if (this->y == compare.y && this->x == compare.x) return false;
        else return false;
    }

    Point operator/ (const Point& compare) {

        Point temp;
        temp.x = (this->x + compare.x)/2;
        temp.y = (this->y + compare.y)/2;

        return temp;
    }

    double getx () {return this->x;}
    double gety () {return this->y;}

};


int main () {

    Point p1(3.2,9.8);
    Point p2(5.5,-1.2);

    assert(p1.getx() == 3.2);
    assert(p2.gety() == -1.2);

    assert((p1 == p2) == false);

    Point p3(3.2,9.8);

    assert((p1 == p3) == true);
    assert((p1 != p2) == true);
    assert((p1 != p3) == false);

    std::cout << p1-p3 << std::endl;
    std::cout << p1-p2 << std::endl;

    Point obj3 = p1/p3;
    std::cout << obj3.getx() << std::endl << obj3.gety() << std::endl;

    Point obj4 = p1/p2;
    std::cout << obj4.getx() << std::endl << obj4.gety() << std::endl;
}