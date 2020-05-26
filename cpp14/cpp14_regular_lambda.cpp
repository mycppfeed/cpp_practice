// cpp14_regular_lambda.cpp

#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

void print_line() { printf("----------------------------------------------------------\n"); return; }

// Using Regular lambda at sort
class Students {
public:
    Students() {
        add("one1111111"); add("two22222"); add("three3");
        print_line();       print();      print_line();
        sort();
        print_line();       print();      print_line();
    }
private:
    std::vector<std::string> _s_list;
    void add(std::string name) { _s_list.push_back(name); }
    void print() { for ( auto n : _s_list) printf("%s\n", n.c_str()); }

    void sort() {
        std::sort(_s_list.begin(), _s_list.end(),
            [](std::string const& a, std::string const& b){
                return a.length() < b.length();
            }
        );
    }

};

// Using Generic lambda at sort - C++14
class Names {
public:
    Names() {
        add("one1111111"); add("two22222"); add("three3");
        print_line();       print();      print_line();
        sort();
        print_line();       print();      print_line();
    }
private:
    std::vector<std::string> _s_list;
    void add(std::string name) { _s_list.push_back(name); }
    void print() { for ( auto n : _s_list) printf("%s\n", n.c_str()); }

    void sort() {
        std::sort(_s_list.begin(), _s_list.end(),
            [](auto a, auto b){
                return a.length() < b.length();
            }
        );
    }

};

void test_1() {
    std::vector<std::string> names { "jknjkdn", "njkfvjknh", "jknbhvfjksb", "regbh"};
    auto srt = [names]() mutable {
        std::sort(names.begin(), names.end());
    };
    auto print = [names]() {
        for ( auto n : names) printf("%s\n", n.c_str());
    };

    print_line();       print();      print_line();
    srt();
    print_line();       print();      print_line();
}

void test_2() {
    auto p = std::make_unique<int>(10);

    // The following line will cause error . But subsequent line works with 'init-capture' feature of C++14 lambda
    // auto lambda = []() {
    auto lambda = [p = std::move(p)]() {
        printf("Value inside lambda => %d\n", *p);
    };

    lambda();
}

int main() {
    Students s1;
    Names n1;
    test_1();
    test_2();
    return 0;
}