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

class Point0D {
public:
    Point0D() = default;
    int x;
};

class Point1D {
public:
    Point1D() = default;
    int x{};
};

class Point2D {
public:
    // Enabling below will need us to implement it
    // Point2D();

    // Point2D() {} // One of potential empty implementation
    int x;
};

class Point3D {
public:
    int x{};
};

class Point4D {
public:
    Point4D() { }
    int x;
};

class Point5D {
public:
    Point5D() { }
    int x{};
};

void test_initializations() {
    Point0D point0Dreg;
    Point0D point0Duni{};

    printf("0D Reg : X = %d\n", point0Dreg.x);
    printf("0D Uni : X = %d\n\n", point0Duni.x);

    Point1D point1Dreg;
    Point1D point1Duni{};

    printf("1D Reg : X = %d\n", point1Dreg.x);
    printf("1D Uni : X = %d\n\n", point1Duni.x);

    Point2D point2Dreg;
    Point2D point2Duni{};

    printf("2D Reg : X = %d\n", point2Dreg.x);
    printf("2D Uni : X = %d\n\n", point2Duni.x);

    Point3D point3Dreg;
    Point3D point3Duni{};

    printf("3D Reg : X = %d\n", point3Dreg.x);
    printf("3D Uni : X = %d\n\n", point3Duni.x);

    Point4D point4Dreg;
    Point4D point4Duni{};

    printf("4D Reg : X = %d\n", point4Dreg.x);
    printf("4D Uni : X = %d\n\n", point4Duni.x);

    Point5D point5Dreg;
    Point5D point5Duni{};

    printf("5D Reg : X = %d\n", point5Dreg.x);
    printf("5D Uni : X = %d\n\n", point5Duni.x);
}

int main() {
    test_constructors();
    test_initializations();

    return 0;
}
