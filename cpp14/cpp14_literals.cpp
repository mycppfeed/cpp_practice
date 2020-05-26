// cpp14_literals.cpp

#include <stdio.h>
#include <iostream>
#include <chrono>

void printMS(std::chrono::nanoseconds ns) {
    std::cout << ns.count() << " nanoseconds" << std::endl;
}

int main() {
    // Required for chrono literals
    using namespace std::chrono;

    auto ns = 1ns;
    auto us = 1us;
    auto ms = 1ms;
    auto s = 1s;

    // Required for String literals
    using namespace std::string_literals;
    auto char_array = "Hello World!";
    auto string_var = "Hello World!"s;

    printf("Char Array : %s\n", char_array);
    printf("String Var : %s\n", string_var.c_str());

    printf(" 1 nS => "); printMS(ns);
    printf(" 1 uS => "); printMS(us);
    printf(" 1 mS => "); printMS(ms);
    printf(" 1  S => "); printMS(s);

    return 0;
}