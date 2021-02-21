#include <iostream>

class Animal {
public:
    void MakeSound() {
        std::cout << "\t\t .=> Animal Sound\n";
    }
    virtual void PrintName() {
        std::cout << "\t\t .=> Name = Animal\n";
    }
};

class Dog : public Animal {
public:
    void MakeSound() {
        std::cout << "\t\t .=> Dogs bark\n";
    }
    
    void PrintName() {
        std::cout << "\t\t .=> Name = Dog\n";
    }
};


int main() {
    std::cout << "=============================\n";
    std::cout << "Regular override:\n";
    std::cout << "=============================\n";
    Animal animal;
    Dog dog;
    Animal *pAnimal = &dog;

    std::cout << "Call Regular method from Base class object\n";
    animal.MakeSound();

    std::cout << "Call Virtual method from Base class object\n";
    animal.PrintName();

    std::cout << "Call Regular method from Derived class object\n";
    dog.MakeSound();

    std::cout << "Call Virtual method from Derived class object\n";
    dog.PrintName();

    std::cout << "Call regular method of base class pointer, pointing to derived class object\n";
    pAnimal->MakeSound();

    std::cout << "Call virtual method of base class pointer, pointing to derived class object\n";
    pAnimal->PrintName();

    return 0;
}
