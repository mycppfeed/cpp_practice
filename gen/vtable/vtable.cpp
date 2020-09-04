// Example from https://shaharmike.com/cpp/vtable-part1/

#include <iostream>

class Parent {
 public:
  virtual void Foo() {}
  virtual void FooNotOverridden() {}
};

class Derived : public Parent {
 public:
  void Foo() override {}
};

int main() {
  Parent p1, p2;
  Derived d1, d2;

  std::cout << "done" << std::endl;
}
