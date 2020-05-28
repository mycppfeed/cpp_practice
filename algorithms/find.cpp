#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> v) {
    os << " [ Size : " << v.size() << " ] [ ";
    for (auto e : v) { std::cout << e << " ,"; }
    os << " ]\n\n";
    return os;
}

void test_find() {
    std::vector<int> v{1, 2, 3, 4, 5, 6, 1, 3, 5, 7};
    std::vector<int> OddVec{1, 3, 5, 1, 3, 5, 7};

    int int_taget = 3;
    auto print_line = [](){ std::cout << "\n===========================================================\n"; };
    auto print_int = [](const int i) { std::cout << i << ", ";};
    auto IsEven = [](const int i) { return !(i%2); };
    auto IsOdd = [](const int i) { return (i%2); };
    auto IsLessThanFive = [](const int i) { return (i <= 5); };

    print_line();
    auto res = std::find(std::begin(v), std::end(v), int_taget);
    auto res_str = (res != v.end()) ? "True" : "False";

    std::cout << " Mixed Int Vector : " << v << " [ " << int_taget
              << " is present ?  : " << res_str  << " ]\n\n\n\n";

    print_line();
    res = std::find_if(std::begin(v), std::end(v), IsEven);
    res_str = (res != v.end()) ? "True" : "False";

    std::cout << " Mixed Int Vector : " << v << " [ " << int_taget
              << " First Even int found using find_if ?  : " << *res  << " ]\n\n\n\n";

    print_line();
    res = std::find_if_not(std::begin(v), std::end(v), IsLessThanFive);
    res_str = (res != v.end()) ? "True" : "False";

    std::cout << " Mixed Int Vector : " << v << " [ " << int_taget
              << " First int greater than 5 found using find_if_not ?  : " << *res  << " ]\n\n\n\n";
}

int main() {
    test_find();
    return 0;
}