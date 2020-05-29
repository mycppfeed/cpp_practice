// 0_non_modifying.cpp

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <random>

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> v) {
    os << " [ Size : " << v.size() << " ] [ ";
    for (auto e : v) { std::cout << e << ", "; }
    os << " ]\n\n";
    return os;
}

using PairOfConstIntVectIters = std::pair<const std::vector<int>::iterator, const std::vector<int>::iterator>;
using PairOfConstIntVectRefs = std::pair<const std::vector<int>&, const std::vector<int>&>;
auto PrintMissmatch = []( const PairOfConstIntVectIters& iterators, const PairOfConstIntVectRefs& vectors) {
    // Structure bindings
    const auto [it1, it2] = iterators;
    const auto [v1, v2] = vectors;

    if(it1 == v1.end()) std::cout << "END, ";
    else                std::cout << *it1 << ", ";

    if(it2 == v2.end()) std::cout << "END ]\n\n";
    else                std::cout << *it2 << " ]\n\n";;
};

auto PrintCppVersion = [] () {
         if (__cplusplus == 201703L) std::cout << __cplusplus << " = C++17\n";
    else if (__cplusplus == 201402L) std::cout << __cplusplus << " = C++14\n";
    else if (__cplusplus == 201103L) std::cout << __cplusplus << " = C++11\n";
    else if (__cplusplus == 199711L) std::cout << __cplusplus << " = C++98\n";
    else std::cout << __cplusplus << " = pre-standard C++\n";
};

auto print_line = [](){ std::cout << "\n===========================================================\n"; };
auto print_int = [](const int i) { std::cout << i << ", ";};
auto IsEven = [](const int i) { return !(i%2); };
auto IsOdd = [](const int i) { return (i%2); };

void test_1() {
    std::vector<int> v{1, 2, 3, 4, 5, 6, 1, 3, 5, 7};
    std::vector<int> OddVec{1, 3, 5, 1, 3, 5, 7};

    int int_taget = 3;

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
}

void test_2() {
    std::vector<int> empty;
    std::vector<int> v1(8);
    std::vector<int> v2(3);
    std::vector<int> v3(3);
    std::vector<int> v4(10);
    std::vector<int> v5(40);
    std::vector<int> v6(40);

    std::iota(v1.begin(), v1.end(), -3);
    std::iota(v2.begin(), v2.end(), 0);
    std::iota(v3.begin(), v3.end(), 10);
    std::iota(v4.begin(), v4.end(), -3);

    int n = 8;
    for (auto i = 0; i < 5; i++)
        std::iota(v5.begin() + (n*i), v5.begin() + (n*i) + n, -3);

    for (auto i = 0; i < 5; i++) {
        if (i == 1) continue;
        std::iota(v6.begin() + (n*i), v6.begin() + (n*i) + n, 0);
    }

    print_line();
    std::cout << " Vector 1: " <<  v1;
    std::cout << " Vector 2: " <<  v2;
    std::cout << " Vector 3: " <<  v3;
    std::cout << " Vector 4: " <<  v4;
    std::cout << " Vector 5: " <<  v5;
    std::cout << " Vector 6: " <<  v6;

    std::cout << "Printing using for_each : ";
    std::for_each(v1.begin(), v1.end(), print_int );
    std::cout << "\n\n";

    // Require C++ 17
#if 1
    {
        std::cout << "Printing first 3 elements using for_each_n : ";
        std::for_each_n(v1.begin(), 3, print_int);
        std::cout << "\n\n";
    }
#endif

    // find_end: ForwardIt1 find_end( ForwardIt1 first, ForwardIt1 last,
    //                                ForwardIt2 s_first, ForwardIt2 s_last );
    //
    // Searches for the last occurrence of the sequence [s_first, s_last) in the range [first, last).

    std::vector<int>::iterator it0 = find_end(v1.begin(), v1.end(), empty.begin(), empty.end());
    std::cout << "Find_end(v1, empty) returned position in v1: ";
    if(it0 == v1.end()) std::cout << "END\n\n";
    else                std::cout << std::distance( v1.begin(), it0) << "\n\n";

    auto it1 = find_end(v1.begin(), v1.end(), v2.begin(), v2.end());
    std::cout << "Find_end(v1, v2) returned position in v1: ";
    if(it1 == v1.end()) std::cout << "END\n\n";
    else                std::cout << std::distance( v1.begin(), it1) << "\n\n";

    auto it2 = find_end(v1.begin(), v1.end(), v3.begin(), v3.end());
    std::cout << "Find_end(v1, v3) returned position in v1: ";
    if(it2 == v1.end()) std::cout << "END\n\n";
    else                std::cout << std::distance( v1.begin(), it2) << "\n\n";

    auto it3 = find_end(v3.begin(), v3.end(), v1.begin(), v1.end());
    std::cout << "Find_end(v3, v1) returned position in v1: ";
    if(it3 == v3.end()) std::cout << "END\n\n";
    else                std::cout << std::distance( v3.begin(), it3) << "\n\n";

    auto it4 = find_end(v1.begin(), v1.end(), v4.begin(), v4.end());
    std::cout << "Find_end(v1, v4) returned position in v1: ";
    if(it4 == v1.end()) std::cout << "END\n\n";
    else                std::cout << std::distance( v1.begin(), it4) << "\n\n";

    auto it5 = find_end(v5.begin(), v5.end(), v2.begin(), v2.end());
    std::cout << "Find_end(v5, v2) returned position in v5: ";
    if(it5 == v5.end()) std::cout << "END\n\n";
    else                std::cout << std::distance( v5.begin(), it5) << "\n\n";

    auto it6 = search(v5.begin(), v5.end(), v2.begin(), v2.end());
    std::cout << "search(v5, v2) returned position in v5: ";
    if(it6 == v5.end()) std::cout << "END\n\n";
    else                std::cout << std::distance( v5.begin(), it6) << "\n\n";


    /**
     * ForwardIt search_n( ForwardIt first, ForwardIt last, Size count, const T& value );
     *
     *  Searches the range [first, last) for the first sequence of count identical elements,
     *  each equal to the given value value.
     *
     **/
    size_t count = 8;
    int search_val = 0;

    auto it7 = std::search_n(v6.begin(), v6.end(), count, search_val);
    std::cout << "search_n(v6, " << count << " counts of, " << search_val << ") returned position in v6: ";
    if(it7 == v6.end()) std::cout << "END\n\n";
    else                std::cout << std::distance( v6.begin(), it7) << "\n\n";

    count = 2, search_val = 0;
    auto it8 = std::search_n(v6.begin(), v6.end(), count, search_val);
    std::cout << "search_n(v6, " << count << " counts of, " << search_val << ") returned position in v6: ";
    if(it8 == v6.end()) std::cout << "END\n\n";
    else                std::cout << std::distance( v6.begin(), it8) << "\n\n";

    count = 1, search_val = 7;
    auto it9 = std::search_n(v6.begin(), v6.end(), count, search_val);
    std::cout << "search_n(v6, " << count << " counts of, " << search_val << ") returned position in v6: ";
    if(it9 == v6.end()) std::cout << "END\n\n";
    else                std::cout << std::distance( v6.begin(), it9) << "\n\n";

    count = 2, search_val = 9;
    auto it10 = std::search_n(v6.begin(), v6.end(), count, search_val);
    std::cout << "search_n(v6, " << count << " counts of, " << search_val << ") returned position in v6: ";
    if(it10 == v6.end()) std::cout << "END\n\n";
    else                std::cout << std::distance( v6.begin(), it10) << "\n\n";

    print_line();
}

void test_3() {
    // auto char_array = "Hello World";
    // char char_target = "l";
    // std::cout << "Character array : " << char_array << " [ Count = " << std::count(std::begin(char_array), std::end(char_array), char_target) << " ]\n"

    std::vector<int> v{1, 2, 3, 4, 5, 6, 1, 3, 5, 7};
    std::vector<int> OddVec{1, 3, 5, 1, 3, 5, 7};

    int int_taget = 3;

    print_line();
    std::cout << " Mixed Int Vector : " << v << " [ Count of " << int_taget << " : " << std::count(std::begin(v), std::end(v), int_taget ) << " ]\n\n\n\n";
    std::cout << " Mixed Int Vector : " << v << " [ Count of Even numbers " << " : " << std::count_if(std::begin(v), std::end(v), IsEven ) << " ]\n\n\n\n";
    std::cout << " Mixed Int Vector : " << v << " [ Count of Odd numbers " << " : " << std::count_if(std::begin(v), std::end(v), IsOdd ) << " ]\n\n\n\n";
}

void test_4() {
    std::vector <int> v1(10);
    std::vector <int> v2(10);
    std::vector <int> v3(6);
    std::vector <int> v4;
    std::vector <int> v5;

    std::iota(v1.begin(), v1.end(), 0);
    std::iota(v2.begin(), v2.end() - 5, 0);
    std::iota(v2.begin() + 5, v2.end(), 1);

    std::iota(v3.begin(), v3.end(), 0);

    print_line();
    std::cout << "Vector V1 : " << v1;
    std::cout << "Vector V2 : " << v2;
    std::cout << "Vector V3 : " << v3;
    std::cout << "Vector V4 : " << v4;
    std::cout << "Vector V5 : " << v5;

    // Version 1
    std::cout << "Mismatch(v1, v2) at Elements [ ";
    auto ret1 = std::mismatch(v1.begin(), v1.end(), v2.begin(), v2.end());
    PrintMissmatch(ret1, std::make_pair(std::ref(v1), std::ref(v2)));

    // The following will fail, since we are passing vector instead of reference to vector.
    // PrintMissmatch(ret3, std::make_pair(v1, v3));

    // Version 2 - Without v2.end()
    //    In this case, it is infered as it denotes v2.first + (v1.end() - v1.first()).
    std::cout << "Mismatch(v1, v2) at Elements [ ";
    auto ret2 = std::mismatch(v1.begin(), v1.end(), v2.begin());
    PrintMissmatch(ret2, std::make_pair(std::ref(v1), std::ref(v2)));

    // Comparing vectors of different lenghts
    // Version 1
    std::cout << "Mismatch(v1, v3) at Elements [ ";
    auto ret3 = std::mismatch(v1.begin(), v1.end(), v3.begin(), v3.end());
    PrintMissmatch(ret3, std::make_pair(std::ref(v1), std::ref(v3)));

    // The following will cause heap overflow;
    // Reason: V3 length is assumed to of same as V1, but its not.
    // auto ret4 = std::mismatch(v1.begin(), v1.end(), v3.begin());

    std::cout << "Mismatch(v1, v3) at Elements [ ";
    auto ret4 = std::mismatch(v1.begin(), v1.end(), v3.begin(), v3.end());
    PrintMissmatch(ret4, std::make_pair(std::ref(v1), std::ref(v3)));

    std::cout << "Mismatch(v3, v1) at Elements [ ";
    auto ret5 = std::mismatch(v3.begin(), v3.end(), v1.begin());
    PrintMissmatch(ret5, std::make_pair(std::ref(v3), std::ref(v1)));


    // Empty vector compared to valid vector
    std::cout << "Mismatch(v4, v1) at Elements [ ";
    auto ret6 = std::mismatch(v4.begin(), v4.end(), v1.begin());
    PrintMissmatch(ret6, std::make_pair(std::ref(v4), std::ref(v1)));


    // Empty vector compared to empty vector
    std::cout << "Mismatch(v4, v5) at Elements [ ";
    auto ret7 = std::mismatch(v4.begin(), v4.end(), v5.begin());
    PrintMissmatch(ret7, std::make_pair(std::ref(v4), std::ref(v5)));

    print_line();
}


void test_5() {
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

    std::cout << " Mixed Int Vector : " << v << " [ Target " << int_taget
              << " is present ?  : " << res_str  << " ]\n\n\n\n";

    print_line();
    res = std::find_if(std::begin(v), std::end(v), IsEven);
    res_str = (res != v.end()) ? "True" : "False";

    std::cout << " Mixed Int Vector : " << v << " [ "
              << " First Even int found using find_if ?  : " << *res  << " ]\n\n\n\n";

    print_line();
    res = std::find_if_not(std::begin(v), std::end(v), IsLessThanFive);
    res_str = (res != v.end()) ? "True" : "False";

    std::cout << " Mixed Int Vector : " << v << " [ "
              << " First int greater than 5 found using find_if_not ?  : " << *res  << " ]\n\n\n\n";

    print_line();
}

void test_6() {
    print_line();

    std::vector<int> empty;
    std::vector<int> v(10);
    std::iota(v.begin(), v.end(), 0);
    v[4] = 3;

    std::cout << " Initial Vector : " << v;
    std::cout << " Empty Vector : " << empty;

    /**
     *  ForwardIt adjacent_find( ForwardIt first, ForwardIt last );
     *
     *  finds the first two adjacent items that are equal (or satisfy a given predicate)
     **/

    auto it1 = std::adjacent_find(v.begin(), v.end());
    std::cout << " adjacent_find(v) returned position in v: ";
    if(it1 == v.end()) std::cout << "END\n\n";
    else              std::cout << std::distance( v.begin(), it1) << "\n\n";

    // std::random_device d;
    // std::mt19937 mt(std::random_device{}());
    // std::shuffle(v.begin(), v.end(), mt);

    std::shuffle(v.begin(), v.end(), std::mt19937{std::random_device{}()});
    std::cout << " Shuffled Vector : " << v;

    auto it2 = std::adjacent_find(v.begin(), v.end());
    std::cout << " adjacent_find(v) returned position in v: ";
    if(it2 == v.end()) std::cout << "END\n\n";
    else              std::cout << std::distance( v.begin(), it2) << "\n\n";

    auto it3 = std::adjacent_find(empty.begin(), empty.end());
    std::cout << " adjacent_find(empty) returned position in empty: ";
    if(it3 == empty.end()) std::cout << "END\n\n";
    else              std::cout << std::distance( empty.begin(), it3) << "\n\n";

    print_line();
}

int main() {
    PrintCppVersion();

    test_1();
    test_2();
    test_3();
    test_4();
    test_5();
    test_6();

    return 0;
}
