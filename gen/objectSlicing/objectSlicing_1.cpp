#include <iostream>

void test_reassignReference_not() {
    int i = 1, j = 2;

    int &ri = i;
    std::cout << " ri [ " << &ri << "] is : " << ri << " i is : " << i << " j is : " << j <<"\n";

    i = 3;
    std::cout << " ri [ " << &ri << "] is : " << ri  << " i is : " << i << " j is : " << j << "\n";

    ri = j; // >>> Is this not reassigning the reference? <<<
    std::cout << " ri [ " << &ri << "] is : " << ri  << " i is : " << i << " j is : " << j <<"\n";

    return 0;
}


// Example from wikipedia
struct A
{
    A(int a) : a_var(a) {}
    int a_var;
};

struct B : public A
{
    B(int a, int b) : A(a), b_var(b) {}
    int b_var;
};

int main()
{
    // 0) Construct static b(1,2)
    static B b(1, 2);
    // b.a_var = 1, b-b_var = 2

    // 1) Normal assignment by value to a
    A a(3);
    // a.a_var == 3

    // 2) Assign reference to b, to a.
    a = b;
    // a.a_var == 1, b.b_var not copied to a

    // 3) construct b2(4,5)
    B b2(4, 5);
    // b2.a_var == 4 ,b2.b_var == 5

    // Create a reference to b2, but let that reference be of type A.
    A &a2 = b2;
    // a2.a_var = 4, which is copied from b2.a_var

    // Now, lets do the bad: Assign reference to b, to a2, which is referencing b2 by reference
    // Partial assignment by value to a2, which is a reference to b2
    a2 = b;
    // b2.a_var == 1, b2.b_var == 5!

    // Ideally, since we are assigning a B type value to a refernce to b, which is again B type,
    // b2.b_var = static_b.b_var, which didnt happen, since the type of reference is A.

    return 0;
}
