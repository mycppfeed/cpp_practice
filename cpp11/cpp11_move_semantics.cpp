#include <iostream>

auto PrintLine = []() { std::cout << "\n=========================================\n\n"; };

struct Example {
public:
    // Constructor
    Example(int i = 0) { std::cout << "Constructor \t\t : " << __PRETTY_FUNCTION__ << "\n"; }

    // Destructor
    ~Example() { std::cout << "Destructor \t\t : " << __PRETTY_FUNCTION__ << "\n"; }

    // Copy Constructor
    Example(const Example& that) { std::cout << "Copy Constructor \t : " << __PRETTY_FUNCTION__ << "\n"; }

    // Move Constructor
    Example(const Example&& that) { std::cout << "Move Constructor \t : " << __PRETTY_FUNCTION__ << "\n"; }

    // Copy Assignment operator
    Example& operator=(const Example& that) { std::cout << "Copy Assignment \t : " << __PRETTY_FUNCTION__ << "\n"; }

    // Move Assignment operator
    Example operator=(const Example&& that) { std::cout << "Move Assignment \t : " << __PRETTY_FUNCTION__ << "\n"; }

};

//void FunctionTakingExample(Example e) { std::cout << __PRETTY_FUNCTION__ << "\n"; }
void FunctionTakingExample(Example& e) { std::cout << __PRETTY_FUNCTION__ << "\n"; }
void FunctionTakingExample(Example&& e) { std::cout << __PRETTY_FUNCTION__ << "\n"; }

int main() {
    PrintLine();
    {
        FunctionTakingExample(Example());
    }
    PrintLine();

    PrintLine();
    {
        Example e;
        FunctionTakingExample(e);
    }
    PrintLine();

    PrintLine();
    {
        Example e;
        FunctionTakingExample(std::move(e));
    }
    PrintLine();

    PrintLine();
    {
        FunctionTakingExample(10);
    }
    PrintLine();

    return 0;
}
