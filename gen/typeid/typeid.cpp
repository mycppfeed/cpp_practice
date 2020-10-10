#include <iostream>
#include <typeinfo>
struct Base1 {
    // polymorphic type: declares a virtual member
    virtual ~Base1() {}
};
struct Derived1 : Base1 {
     // polymorphic type: inherits a virtual member
};

struct Base2 {
     // non-polymorphic type
};
struct Derived2 : Base2 {
     // non-polymorphic type
};

int main()
{
    Derived1 obj1; // object1 created with type Derived1
    Derived2 obj2; // object2 created with type Derived2

    Base1& b1 = obj1; // b1 refers to the object obj1
    Base2& b2 = obj2; // b2 refers to the object obj2

    auto id_obj1 = typeid(obj1).name();
    auto id_obj2 = typeid(obj2).name();
    
    auto id_b1 = typeid(b1).name();
    
    std::cout << "Expression type of b1: " << typeid(decltype(b1)).name() << '\n'
              << "Expression type of b2: " << typeid(decltype(b2)).name() << '\n'
              << "Object type of b1: " << typeid(b1).name() << '\n'
              << "Object type of b2: " << typeid(b2).name() << '\n'
              << "Size of b1: " << sizeof b1 << '\n'
              << "Size of b2: " << sizeof b2 << '\n';
}
