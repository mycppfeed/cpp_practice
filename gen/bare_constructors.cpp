#include <iostream>
#include <string>

class Test {
public:
    Test() {
        std::cout << " Default Constructor\n";
    }
    Test(std::string str) : s(str) {
        std::cout << " Constructor with initialization\n";
    }
    ~Test() {
        std::cout << " Destructor\n";
    }
    
    Test(Test& t) {
        std::cout << " Copy Constructor\n";
    }
    Test(Test&& t) {
        std::cout << " Move Constructor\n"; s = std::move(t.s);
    }
    Test& operator=(Test& t) {
        std::cout << " Copy Assignment Constructor\n"; s = t.s; return *this;
    }
    Test& operator=(Test&& t) {
        std::cout << " Move Assignment Constructor\n"; s = t.s; return *this;
    }

    void setString(std::string str) { s = str; };
    std::string getString() { return s; }
private:
    std::string s;
};

auto PrintLine = []() { std::cout << "\n=========================================\n\n"; };
int main() {

    PrintLine();
    // Default Constructor
    {
        Test t;
    }
    
    PrintLine();
    // Constructor with initialization
    {
        Test t("Hello");
    }
    
    PrintLine();
    // Constructor with initialization and Copy constructor
    {
        Test t1("Hello");
        Test t2 = t1;
    }

    PrintLine();
    // Constructor with initialization and Move constructor
    {
        Test t1("Hello");
        Test t2 = std::move(t1);

        std::cout << " t1 After Move : " << t1.getString() << "\n";
        std::cout << " t2 After Move : " << t2.getString() << "\n\n\n";
        
        t2 = std::string("World");

        std::cout << "\n\n";
        std::cout << " t1 After Move and changing t2 : " << t1.getString() << "\n";
        std::cout << " t2 After Move and changing t2 : " << t2.getString() << "\n";
    }

    PrintLine();
    // Constructor with initialization and Copy assignment constructor
    {
        Test t1("Hello");
        Test t2;
        t2 = t1;
    }
    
    PrintLine();
    // Constructor with initialization and Move assignment constructor
    {
        Test t1("Hello");
        Test t2;
        t2 = std::move(t1);
    }
    
    PrintLine();
    return 0;
}
