// cpp17_vectors.cpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
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

    std::vector<int> src  { -10, -11, -12};
    std::cout << "Inserting { -10, -11, -12 } from source range, at pos 2: \n";
    v.insert(std::begin(v) + 2, src.begin(), src.end());
    std::cout << "              : " << v << "\n\n";

    // Doesnt work - No such overload
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

int main() {
    test_1();
    test_2();
    test_3();
    return 0;
}