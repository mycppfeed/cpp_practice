#include <iostream>

auto PrintLine = []() { std::cout << "\n=========================================\n"; };

class Number{
public:
    int n;
    Number(int a):n(a){}

    friend Number& operator++(Number& source, int i){
        ++source.n;
        return source;
    }
};

class MyInt {
    int n;
public:
    void Print(std::string varName) { std::cout << varName << " = " << n << "\n"; }
    MyInt()        : n(0)   {std::cout << __PRETTY_FUNCTION__ << "\n";}
    MyInt(int x)   : n(x)   {std::cout << __PRETTY_FUNCTION__ << "\n";}
    // MyInt(MyInt& x) : n(x.n) {std::cout << __PRETTY_FUNCTION__ << "\n";} // Error

#if 1
    // Copy Assignment Operator
    MyInt operator=(int x) { std::cout << __PRETTY_FUNCTION__ << "\n"; n = x; return *this; }
    MyInt operator=(MyInt& x) { std::cout << __PRETTY_FUNCTION__ << "\n"; n = x.n; return *this;}

    // PreFix
    MyInt operator++() { std::cout << __PRETTY_FUNCTION__ << "\n"; ++n; return *this; }
    MyInt operator--() { std::cout << __PRETTY_FUNCTION__ << "\n"; --n; return *this; }

    // PostFix
    MyInt operator++(int) { std::cout << __PRETTY_FUNCTION__ << "\n"; MyInt tmp(n); ++n; return tmp; }
    MyInt operator--(int) { std::cout << __PRETTY_FUNCTION__ << "\n"; MyInt tmp(n); --n; return tmp; }
#endif
};

int main() {

#if 0
    Number x(5);
    x++; x++; //error: no 'operator++(int)' declared for postfix '++' [-fpermissive]
    cout << x.n << "\n\n";
#endif
    PrintLine();
    std::cout << " Initial value of a\n";
    MyInt a = 10; // How does it work without a copy assignment operator?
    a.Print("a");
    PrintLine();

    PrintLine();
    std::cout << " Pre Increment of a\n";
    MyInt b = ++a;
    a.Print("a");
    b.Print("b");
    PrintLine();

    PrintLine();
    std::cout << " Post Increment of a\n";
    MyInt c = a++;
    a.Print("a");
    c.Print("c");
    PrintLine();

    PrintLine();
    MyInt d = a;
    d.Print("d");
    PrintLine();
    return 0;
}
