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

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& s) {
    os << "\n[ Size : " << s.size() << " ] [ ";
    for (auto e : s) os << e << ", ";
    os << " ]\n\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const std::set<Point>& p) {
    os << "\n[ Size : " << p.size() << " ] [ ";
    // for (auto& e : p) os << "{ " << e._x << ", " << e._y <<" }" << ", ";

    // Using structure bindings of C++17
    // for(auto [x, y]  : p) { std::cout << "{ " << x << ", " << y << " }"; }

    // Avoid copy construction
    for(auto const& [x, y]  : p) { std::cout << "{ " << x << ", " << y << " }"; }

    os << " ]\n\n";
    return os;
}

void test_initialization() {
    std::set<int> empty_set;
    std::cout << "Empty Set : " << empty_set;

    std::set<int> set_init_uniform{1,2,3,4};
    std::cout << "Set Initialized using uniform initializer : " << set_init_uniform;

    std::set<int> set_init_equal = {1,2,3,4};
    std::cout << "Set Initialized using Equal initializer : " << set_init_equal;
    return;
}

void test_iterators() {
    std::set<int> s{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    std::cout << "Get Iterator begin() and iterate till end() : \n [ ";
    auto s_begin = s.cbegin();
    while (s_begin != s.cend()) {
        std::cout << *s_begin << ", ";
        std::advance(s_begin, 1);
    }
    std::cout << " ]\n\n";

    std::cout << "Get Iterator rbegin() and iterate till rend() :\n [ ";
    auto s_rbegin = s.crbegin();
    while (s_rbegin != s.rend()) {
        std::cout << *s_rbegin << ", ";
        std::advance(s_rbegin, 1);
    }
    std::cout << " ]\n\n";
}

void test_capacity() {
    std::set<int> s{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    std::cout << "Initial set for capacity usage : " << s;

    std::cout << "[Empty? / Size] : " << s.empty() << "/" << s.size() << "\n\n";
}

void test_insert() {
    std::set<int> s1{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    std::cout << "Set regular insert [S1]: " << s1;

    std::set<int> s2;
    s2.insert(10);
    s2.insert(20);
    s2.insert(30);
    s2.insert(40);
    s2.insert(50);
    s2.insert(1);
    s2.insert(2);
    std::cout << "Set regular insert [S2]: " << s2;

    s1.insert(s2.begin(), s2.end());
    std::cout << "S1 after inserting S2: " << s1;
}

void test_custom_object() {
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
    test_initialization();
    test_iterators();
    test_capacity();
    test_insert();
    test_custom_object();

    return 0;
}
