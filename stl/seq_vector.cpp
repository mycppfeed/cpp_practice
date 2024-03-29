// cpp11_vectors.cpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

void test_6() {
    std::vector<int> myIntVect{0, 1, 2, 3};

    for (auto i : myIntVect) {
        printf("%d\n", i);
    }
}

class MyIntVector {
public:
    MyIntVector() {
        _instance_count++;
        _instance_id = _instance_count;
    }

    void printInfo() {
        printf("Info of MyIntVector\n");
        printf("\t Capacity / Size : [ %zu / %zu ]\n", _v.capacity(), _v.size());
        printf("\t        Elements : ");
        for (auto i : _v) printf("%2d, ", i);
        printf("\n");
    }

    //  Member functions
    void assign(size_t count, int val)       { return _v.assign(count, val); }

    //  Element access
    int at(size_t pos) { return at(pos); }
    int operator[](size_t pos) { return _v[pos]; }
    int front(size_t pos) { return _v.front(); }
    int back(size_t pos) { return _v.back(); }
    int* data(size_t pos) { return _v.data(); }

    const int at(size_t pos) const { return at(pos); }
    const int operator[](size_t pos) const { return _v[pos]; }
    const int front(size_t pos) const { return _v.front(); }
    const int back(size_t pos) const { return _v.back(); }
    const int* data(size_t pos) const { return _v.data(); }

    void push_back(int i) { return _v.push_back(i); }
    void pop_back()       { return _v.pop_back(); }
    void erase_all()      { _v.erase(_v.begin(), _v.end()); }

    size_t size()         { return _v.size(); }
    size_t capacity()     { return _v.capacity(); }

private:
    static int _instance_count;
    int _instance_id;
    std::vector<int> _v;
};
int MyIntVector::_instance_count = 0;

void test_7() {
    MyIntVector myIntVector;
    myIntVector.printInfo();

    for (auto i = 0; i < 10; i++) {
        myIntVector.push_back(10 - i);
        myIntVector.printInfo();
    }
    return;
}

void printInfo(std::vector<int> _v) {
    printf("Info of MyIntVector\n");
    printf("\t Capacity / Size : [ %zu / %zu ]\n", _v.capacity(), _v.size());
    printf("\t        Elements : ");
    for (auto i : _v) printf("%2d, ", i);
    printf("\n");
}


void test_8() {
    std::vector<int> myIntVector;
    printInfo(myIntVector);

    for (auto i = 0; i < 10; i++) {
        myIntVector.push_back(10 - i);
        printInfo(myIntVector);
    }

    myIntVector.erase(myIntVector.begin(), myIntVector.end());
    printInfo(myIntVector);
    return;
}


template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    os << "[ ";
    for (auto x : v) os << x << " ";
    os << " ]";
    return os;
}

std::vector<int> v{ 11, 22, 33, 44, 55, 66 };
void test_1() {
    std::cout << "Initial Vector: " << v << "\n\n";

    std::cout << "Inserting single element 99 at pos 1: \n";
    v.insert(std::begin(v) + 1, 99);
    std::cout << "              : " << v << "\n\n";

    std::cout << "Inserting 3 copies of 100 at pos 2: \n";
    v.insert(std::begin(v) + 2, 3, 100);
    std::cout << "              : " << v << "\n\n";

    std::vector<int> src { -10, -11, -12};
    std::cout << "Inserting { -10, -11, -12 } from source range, at pos 2: \n";
    v.insert(std::begin(v) + 2, src.begin(), src.end());
    std::cout << "              : " << v << "\n\n";

    // Doesn't work - No such overload
    // std::cout << "Inserting 2 copies { -10, -11, -12 } from source range, at pos 1: \n";
    // v.insert(std::begin(v) + 1, 2, src.begin(), src.end());
    // std::cout << "              : " << v << "\n\n";

    std::cout << "Inserting { 111, 222, 333} from Initializer list, at pos 2: \n";
    v.insert(std::begin(v) + 2, { 111, 222, 333});
    std::cout << "              : " << v << "\n\n";
}

auto isOdd = [](int i)  { return (i % 2); };
auto isEven = [](int i) { return !(i % 2); };

void test_2() {
    std::remove_if(v.begin(), v.end(), isOdd );
    std::cout << "After only removing all odd numbers: \n";
    std::cout << "              : " << v << "\n\n";
}

void test_3() {
    v.erase(
        std::remove_if(v.begin(), v.end(), isOdd ),
        v.end()
    );

    std::cout << "After removing and erasing all odd numbers: \n";
    std::cout << "              : " << v << "\n\n";
}

void test_4() {
    std::vector<std::string> sv{ " Hello", "World", "This", "is", "Is", "An", "Example" };
    std::cout << "Initial Vector: " << sv << "\n\n";

    // Regular std::find
    std::string search = "Is";
    auto it = std::find(sv.begin(), sv.end(), search);
    printf("Found (%s) ? %s\n", search.c_str(), (it == sv.end())? "False" : "True");

    // Lambda - Convert a string to lowercase and return
    auto toLower = [](std::string s) {
        std::transform(s.begin(), s.end(), s.begin(),
            [](const unsigned char c){ return std::tolower(c);}
        );
        return s;
    };

    // Lambda - Unary Predicate to check input string is "is"
    search = "is";
    auto isCaseInsensitive_Is = [toLower, search](const std::string& s) {
        return (toLower(s) == search);
    };

    // Regular std::find_if
    it = std::find_if(sv.begin(), sv.end(), isCaseInsensitive_Is);
    printf("Found (%s) ? %s\n", search.c_str(), (it == sv.end())? "False" : "True");
}

void test_5() {
    // Compare two strings, character by character using std::equal
    std::string s1 = "hello";
    std::string s2 = "world";
    auto isEqual = [s1, s2]() {
        std::equal(
            std::begin(s1), end(s1),
            std::begin(s2), end(s2),
            [](char c1, char c2) {
                printf("%c <=> %c", c1, c2);
                return c1 == c2;
            }
        );
    };
    isEqual();
}

int main() {
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();
    test_6();
    test_7();
    return 0;
}