// Example from https://shaharmike.com/cpp/vtable-part1/
#include <iostream>

/*****************************************************************
 * Class set 1
 ****************************************************************/
class MyClass {
public:
    MyClass() { std::cout << " MyClass MyClass::CTRO\n"; }
    void NonVirtualMethod() { std::cout << "Hello from MyClass::NonVirtualMethod\n"; }
    int MyClassInt;
};

class DerivedX : MyClass {
public:
    DerivedX() { std::cout << "DerivedX DerivedX::CTRO"; }
    void NonVirtualMethod() { std::cout << "Hello from DerivedX::NonVirtualMethod class "; }
    int DerivedXInt;
};

/*****************************************************************
 * Class set 2
 ****************************************************************/
class Parent {
public:
    virtual void Foo() {}
    virtual void bar() {}
    virtual void FooNotOverridden() {}
};

class Derived : public Parent {
public:
    void Foo() override {}
};

/*****************************************************************
 * Class set 3
 ****************************************************************/
class Mother {
 public:
  virtual void MotherMethod() {}
  int mother_data;
};

class Father {
 public:
  virtual void FatherMethod() {}
  int father_data;
};

class Child : public Mother, public Father {
 public:
  virtual void ChildMethod() {}
  int child_data;
};

int main() {
    // MyClass c1;
    // DerivedX dx1;


    Parent p1;
    Derived d1;

    Mother m1;
    Father f1;
    Child ch1;

    std::cout << "done" << std::endl;

    p1.bar();
    d1.bar();

    m1.MotherMethod();
    f1.FatherMethod();
    ch1.ChildMethod();
}

/**
 * GDB Information
 *
 * set print asm-demangle on
 * set print demangle on
 *
 * break vtable.cpp:71
 * run
 *
 * gdb$ info locals
 * p1 = {_vptr.Parent = 0x555555557cf0 <vtable for Parent+16>}
 * d1 = {<Parent> = {_vptr.Parent = 0x555555557cc8 <vtable for Derived+16>}, <No data fields>}
 * m1 = {_vptr.Mother = 0x555555557cb0 <vtable for Mother+16>, mother_data = 0x55555301}
 * f1 = {_vptr.Father = 0x555555557c98 <vtable for Father+16>, father_data = 0x5555544d}
 * ch1 = {<Mother> = {_vptr.Mother = 0x555555557c60 <vtable for Child+16>, mother_data = 0x55555400}, <Father> = {_vptr.Father = 0x555555557c80 <vtable for Child+48>, father_data = 0x555550e0}, child_data = 0x5555}
 * gdb$
 *
 * gdb$ x/7ga 0x555555557c50
 * 0x555555557c50 <vtable for Child>:	0x0	0x555555557d08 <typeinfo for Child>
 * 0x555555557c60 <vtable for Child+16>:	0x555555555344 <Mother::MotherMethod()>	0x555555555364 <Child::ChildMethod()>
 * 0x555555557c70 <vtable for Child+32>:	0xfffffffffffffff0	0x555555557d08 <typeinfo for Child>
 * 0x555555557c80 <vtable for Child+48>:	0x555555555354 <Father::FatherMethod()>
 *
 * gdb$ x/3ga 0x555555557c88
 * 0x555555557c88 <vtable for Father>:	0x0	0x555555557d40 <typeinfo for Father>
 * 0x555555557c98 <vtable for Father+16>:	0x555555555354 <Father::FatherMethod()>
 *
 * gdb$ x/3ga 0x555555557ca0
 * 0x555555557ca0 <vtable for Mother>:	0x0	0x555555557d50 <typeinfo for Mother>
 * 0x555555557cb0 <vtable for Mother+16>:	0x555555555344 <Mother::MotherMethod()>
 * ==========================================================================================================================================================
 *
 * gdb$ x/5ga 0x555555557cb8
 * 0x555555557cb8 <vtable for Derived>:	0x0	0x555555557d60 <typeinfo for Derived>
 * 0x555555557cc8 <vtable for Derived+16>:	0x555555555334 <Derived::Foo()>	0x555555555314 <Parent::bar()>
 * 0x555555557cd8 <vtable for Derived+32>:	0x555555555324 <Parent::FooNotOverridden()>
 *
 * gdb$ x/5ga 0x555555557ce0
 * 0x555555557ce0 <vtable for Parent>:	0x0	0x555555557d78 <typeinfo for Parent>
 * 0x555555557cf0 <vtable for Parent+16>:	0x555555555304 <Parent::Foo()>	0x555555555314 <Parent::bar()>
 * 0x555555557d00 <vtable for Parent+32>:	0x555555555324 <Parent::FooNotOverridden()>
 * ==========================================================================================================================================================
 *
 * gdb$ x/7ga  0x555555557d08
 * 0x555555557d08 <typeinfo for Child>:	0x7ffff7fa7d58 <vtable for __cxxabiv1::__vmi_class_type_info+16>	0x55555555600a <typeinfo name for Child>
 * 0x555555557d18 <typeinfo for Child+16>:	0x200000000	0x555555557d50 <typeinfo for Mother>
 * 0x555555557d28 <typeinfo for Child+32>:	0x2	0x555555557d40 <typeinfo for Father>
 * 0x555555557d38 <typeinfo for Child+48>:	0x1002
 *
 * gdb$ x/2ga  0x555555557d40
 * 0x555555557d40 <typeinfo for Father>:	0x7ffff7fa7008 <vtable for __cxxabiv1::__class_type_info+16>	0x555555556018 <typeinfo name for Father>
 *
 * gdb$ x/2ga  0x555555557d50
 * 0x555555557d50 <typeinfo for Mother>:	0x7ffff7fa7008 <vtable for __cxxabiv1::__class_type_info+16>	0x555555556020 <typeinfo name for Mother>
 * ==========================================================================================================================================================
 *
 * gdb$ x/3ga  0x555555557d60
 * 0x555555557d60 <typeinfo for Derived>:	0x7ffff7fa7c98 <vtable for __cxxabiv1::__si_class_type_info+16>	0x555555556028 <typeinfo name for Derived>
 * 0x555555557d70 <typeinfo for Derived+16>:	0x555555557d78 <typeinfo for Parent>
 *
 * gdb$ x/3ga  0x555555557d78
 * 0x555555557d78 <typeinfo for Parent>:	0x7ffff7fa7008 <vtable for __cxxabiv1::__class_type_info+16>	0x555555556038 <typeinfo name for Parent>
 * 0x555555557d88:	0x1
 * ==========================================================================================================================================================
 */
