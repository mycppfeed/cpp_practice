#include <iostream>

/*
 When you are confused:
    Imagine inheritence from a class, will create a object of parent inside subclass.
    Access Levels of inherited object will be same as inheritance type,
    also respecting parents access levels (if parent object is accessible).

    Public( Public     ) => Public
    Public( Protected  ) => Protected
    Public( Private    ) => In-accesible

    Private( Public    ) => Private
    Private( Protected ) => Private
    Private( Private   ) => In-accesible

    Any( Private       ) => In-accesible

--------------------------------------------------------------
|Members in base    :     Private      Protected     Public  |
|-------------------------------------------------------------
|Inheritance type   :          Object inherited as           |
|-------------------------------------------------------------
|Private            :   Inaccessible   Private     Private   |
|Protected          :   Inaccessible   Protected   Protected |
|Public             :   Inaccessible   Protected   Public    |
--------------------------------------------------------------

class A {
public:
    int x;
protected:
    int y;
private:
    int z;
};

class B : public A {
    // x is public
    // y is protected
    // z is not accessible from B
};

class C : protected A {
    // x is protected
    // y is protected
    // z is not accessible from C
};

class D : private A {   // 'private' is default for classes
    // x is private
    // y is private
    // z is not accessible from D
};
 */

auto PrintLine = [](){ std::cout << "========================================\n\n"; };

class A
{
public:
    int x;
    void print_public() { std::cout << " Class A, public x: " << x << "\n\n"; }
protected:
    int y;
    void print_protected() { std::cout << " Class A, protected y: " << y << "\n\n"; }
private:
    int z;
    void print_private() { std::cout << " Class A, private z: " << z << "\n\n"; }
};

class B : public A
{
    // Inherited x is public
    void invoke_pub() { std::cout << x; }

    // Inherited y is protected
    void invoke_prot() { std::cout << y; }

    // Inherited z is not accessible from B
    // void invoke_priv() { std::cout << z; }
};

class C : protected A
{
    // Inherited x is protected
    void invoke_pub() { std::cout << x; }

    // Inherited y is protected
    void invoke_prot() { std::cout << y; }

    // Inherited z is not accessible from C
    // void invoke_priv() { std::cout << z; }
};

class D : private A
{
    // Inherited x is private
    void invoke_pub() { std::cout << x; }

    // Inherited y is private
    void invoke_prot() { std::cout << y; }

    // Inherited z is not accessible from D
    // void invoke_priv() { std::cout << z; }
};

// 'private' is default for classes
// This is same as class D : private A
class E : A
{
    // Inherited x is private
    void invoke_pub() { std::cout << x; }

    // Inherited y is private
    void invoke_prot() { std::cout << y; }

    // Inherited z is not accessible from D
    // void invoke_priv() { std::cout << z; }
};

int main() {
    A a;
    std::cout << a.x;
    // std::cout << a.y;
    // std::cout << a.z;

    B b;
    std::cout << b.x;
    // std::cout << b.y;
    // std::cout << b.z;

    C c;
    // std::cout << c.x;
    // std::cout << c.y;
    // std::cout << c.z;

    D d;
    // std::cout << d.x;
    // std::cout << d.y;
    // std::cout << d.z;

    E e;
    // std::cout << e.x;
    // std::cout << e.y;
    // std::cout << e.z;
    return 0;
}
