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
|Private            :   In-accessible   Private     Private   |
|Protected          :   In-accessible   Protected   Protected |
|Public             :   In-accessible   Protected   Public    |
--------------------------------------------------------------
*/

class ParentWithNestedClass {
public:
    ParentWithNestedClass() { std::cout << " ParentWithNestedClass: Constructor\n\n"; }
    ~ParentWithNestedClass() { std::cout << " ParentWithNestedClass: Destructor\n\n"; }

    class Public_NestedClass {
    public:
        Public_NestedClass() { std::cout << " Public_NestedClass: Constructor\n\n"; }
        ~Public_NestedClass() { std::cout << " Public_NestedClass: Destructor\n\n"; }
        static void invoke_public() { std::cout << " ParentWithNestedClass: public method \n\n"; }

    protected:
        static void invoke_protected() { std::cout << " ParentWithNestedClass: protected method \n\n"; }

    private:
        static void invoke_private() { std::cout << " ParentWithNestedClass: private method \n\n"; }
    };

    void invoke_NestedClass_methods() {
        Public_NestedClass::invoke_public();
        // Public_NestedClass::invoke_protected();
        // Public_NestedClass::invoke_private();
    }
};

class SubClass_Public : public ParentWithNestedClass {
public:
    SubClass_Public() { std::cout << " SubClass_Public: Constructor\n\n"; }
    ~SubClass_Public() { std::cout << " SubClass_Public: Destructor\n\n"; }

    void invoke_parents_and_parents_nested_methods() {
        ParentWithNestedClass::Public_NestedClass::invoke_public();
        Public_NestedClass::invoke_public();
        invoke_NestedClass_methods();
        // Parent::Public_NestedClass::invoke_protected();
        // Parent::Public_NestedClass::invoke_private();
    }
};

int main () { return 0; }
