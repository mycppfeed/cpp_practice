#include <stdio.h>
#include <iostream>
#include <set>

auto PrintLine = []() { std::cout << "\n=========================================\n\n"; };

class Point {
public:
    Point() : _x(0), _y(0) {
        PrintLine();
        std::cout << "Default Constructor of Point\n";
        PrintLine();
    }

    Point(int x, int y) : _x(x), _y(y) { std::cout << "Parameterized Constructor of Point\n"; }

    Point(const Point& p) : _x(p._x), _y(p._y) { std::cout << "Copy constructor of Point\n"; }
    Point(const Point&& p) : _x(p._x), _y(p._y) { std::cout << "Move constructor of Point\n"; }

    // copy assignment operator
    Point& operator=(const Point& p) {
        Point p2;
        std::cout << "Copy Assignment operator of Point\n";
        p2._x = p._x, p2._y = p._y;
        return *this;
    }

    int _x;
    int _y;
};

class SomeClass {
public:
    SomeClass() {
        PrintLine();
        printf("SomeClass\n");
        PrintLine();
    }
    int xx;
    int yy = 11;

    Point p = Point();

    // ConstExpr can only take integral POD
    // Anything else will throw error.

    // static constexpr Point p = Point();
    // static const Point p = Point();

    static const int x = 10;
    static constexpr int y = 10;

    // Flat cant be just const. It must be constexpr

    // static const float y = 10.0;
    static constexpr float z = 10.0;
};

static Point p;
SomeClass r;
int main() {
    auto pp = r.p;
    SomeClass r1;
    PrintLine();
    printf("Main xx %d, yy %d\n", r1.xx, r1.yy);
    PrintLine();

    return 0;
}
