#include <stdio.h>
#include <iostream>
#include <set>

class Point {
public:
    Point() : _x(0), _y(0) { std::cout << "Default Constructor of Point\n"; }
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

// Custom overload for Point class comparision
// The comparision isnt idle, but just for demo
bool operator<(const Point& p1, const Point& p2) {
    return (p1._x < p2._x);
}

std::ostream& operator<<(std::ostream& os, const std::set<Point>& p) {
    os << "\n[ Size : " << p.size() << " ] [ ";

    // This will invoke copy constructor
    // for (auto e : p) os << "{ " << e._x << ", " << e._y <<" }" << ", ";

    for (auto& e : p) os << "{ " << e._x << ", " << e._y <<" }" << ", ";
    os << " ]\n\n";
    return os;
}


void test_constructors() {
    std::set<Point> points{ {1,2}, {2,3}, {4,5} };
    std::cout << "Set of initial points : " << points;

    printf("\n\n Insert \n\n");
    points.insert({5,1});
    std::cout << "Set After insertion : " << points;

    printf("\n\n Emplace \n\n");
    points.emplace(4,1);
    std::cout << "Set After emplace : " << points;
}

int main() {
    test_constructors();

    return 0;
}
