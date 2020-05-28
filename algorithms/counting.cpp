// counting.cpp

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> v) {
    os << " [ Size : " << v.size() << " ] [ ";
    for (auto e : v) { std::cout << e << " ,"; }
    os << " ]\n\n";
    return os;
}


void test_count_vector() {
    // auto char_array = "Hello World";
    // char char_target = "l";
    // std::cout << "Character array : " << char_array << " [ Count = " << std::count(std::begin(char_array), std::end(char_array), char_target) << " ]\n"

    std::vector<int> v{1, 2, 3, 4, 5, 6, 1, 3, 5, 7};
    std::vector<int> OddVec{1, 3, 5, 1, 3, 5, 7};

    int int_taget = 3;
    auto print_line = [](){ std::cout << "\n===========================================================\n"; };
    auto print_int = [](const int i) { std::cout << i << ", ";};
    auto IsEven = [](const int i) { return !(i%2); };
    auto IsOdd = [](const int i) { return (i%2); };

    print_line();
    std::cout << " Mixed Int Vector : " << v << " [ Count of " << int_taget << " : " << std::count(std::begin(v), std::end(v), int_taget ) << " ]\n\n\n\n";
    std::cout << " Mixed Int Vector : " << v << " [ Count of Even numbers " << " : " << std::count_if(std::begin(v), std::end(v), IsEven ) << " ]\n\n\n\n";
    std::cout << " Mixed Int Vector : " << v << " [ Count of Odd numbers " << " : " << std::count_if(std::begin(v), std::end(v), IsOdd ) << " ]\n\n\n\n";

    print_line();
    std::cout << "Printing using for_each\n";
    std::for_each(v.begin(), v.end(), print_int );
    std::cout << "\n\n";

#if 1
    {
        std::cout << "Printing first 3 elements using for_each_n\n";
        std::for_each_n(v.begin(), 3, print_int);
        std::cout << "\n\n";
    }
#endif

#if 1
    print_line();
    std::cout << " Mixed Int Vector : " << v << " [ all_of odd" << " : " << std::all_of(std::begin(v), std::end(v), IsOdd ) << " ]\n\n\n\n";
    std::cout << " Mixed Int Vector : " << v << " [ all_of Even" << " : " << std::all_of(std::begin(v), std::end(v), IsEven ) << " ]\n\n\n\n";

    std::cout << " Mixed Int Vector : " << v << " [ none_of odd" << " : " << std::none_of(std::begin(v), std::end(v), IsOdd ) << " ]\n\n\n\n";
    std::cout << " Mixed Int Vector : " << v << " [ none_of Even" << " : " << std::none_of(std::begin(v), std::end(v), IsEven ) << " ]\n\n\n\n";

    std::cout << " Mixed Int Vector : " << v << " [ any_of odd" << " : " << std::any_of(std::begin(v), std::end(v), IsOdd ) << " ]\n\n\n\n";
    std::cout << " Mixed Int Vector : " << v << " [ any_of Even" << " : " << std::any_of(std::begin(v), std::end(v), IsEven ) << " ]\n\n\n\n";


    print_line();
    std::cout << " Odd Int Vector : " << OddVec << " [ all_of odd" << " : " << std::all_of(std::begin(OddVec), std::end(OddVec), IsOdd ) << " ]\n\n\n\n";
    std::cout << " Odd Int Vector : " << OddVec << " [ all_of Even" << " : " << std::all_of(std::begin(OddVec), std::end(OddVec), IsEven ) << " ]\n\n\n\n";

    std::cout << " Odd Int Vector : " << OddVec << " [ none_of odd" << " : " << std::none_of(std::begin(OddVec), std::end(OddVec), IsOdd ) << " ]\n\n\n\n";
    std::cout << " Odd Int Vector : " << OddVec << " [ none_of Even" << " : " << std::none_of(std::begin(OddVec), std::end(OddVec), IsEven ) << " ]\n\n\n\n";

    std::cout << " Odd Int Vector : " << OddVec << " [ any_of odd" << " : " << std::any_of(std::begin(OddVec), std::end(OddVec), IsOdd ) << " ]\n\n\n\n";
    std::cout << " Odd Int Vector : " << OddVec << " [ any_of Even" << " : " << std::any_of(std::begin(OddVec), std::end(OddVec), IsEven ) << " ]\n\n\n\n";
    print_line();
#endif
}

int main() {
    if (__cplusplus == 201703L) std::cout << __cplusplus << " = C++17\n";
    else if (__cplusplus == 201402L) std::cout << __cplusplus << " = C++14\n";
    else if (__cplusplus == 201103L) std::cout << __cplusplus << " = C++11\n";
    else if (__cplusplus == 199711L) std::cout << __cplusplus << " = C++98\n";
    else std::cout << __cplusplus << " = pre-standard C++\n";

    test_count_vector();

    return 0;
}
