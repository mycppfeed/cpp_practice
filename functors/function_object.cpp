#include <iostream>

class MyFunctionObjectClass {
public:
    void operator()() {
        std::cout << "From Function Object\n\n";
    }
    void operator()(std::string s) {
        std::cout << "From Function Object: " << s << " \n\n";
    }
};

int main() {
    MyFunctionObjectClass functionObject;
    functionObject();
    functionObject("Hello World!");

    return 0;
}

// Ref : CPPCon 2020 - Back To Basics: Lambda Expresions - Barbara Gellar and Ansel Sermershim
