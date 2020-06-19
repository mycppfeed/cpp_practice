#include <iostream>

auto PrintLine = [](){ std::cout << "========================================\n\n"; };

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

class Parent {
public:
    Parent() { std::cout << " Parent: Constructor\n\n"; }
    ~Parent() { std::cout << " Parent: Destructor\n\n"; }

    void invoke_public() { std::cout << " Parent: public method \n\n"; }
protected:
    void invoke_protected() { std::cout << " Parent: protected method \n\n"; }

private:
    void invoke_private() { std::cout << " Parent: private method \n\n"; }
};

class SubClass_Public : public Parent {
public:
    SubClass_Public() { std::cout << " SubClass_Public: Constructor\n\n"; }
    ~SubClass_Public() { std::cout << " SubClass_Public: Destructor\n\n"; }

    void invoke_parent_public() { Parent::invoke_public(); }
    void invoke_parent_protected() { Parent::invoke_protected(); }
    // void invoke_parent_private() { Parent::invoke_private(); }
};

class SubClass_Private : private Parent {
public:
    SubClass_Private() { std::cout << " SubClass_Private: Constructor\n\n"; }
    ~SubClass_Private() { std::cout << " SubClass_Private: Destructor\n\n"; }

    void invoke_parent_public() { Parent::invoke_public(); }
    void invoke_parent_protected() { Parent::invoke_protected(); }
    // void invoke_parent_private() { Parent::invoke_private(); }
};

int main() {

    PrintLine();
    {
        Parent p;
        p.invoke_public();
        // p.invoke_protected();
        // p.invoke_private();
    }
    PrintLine();

    PrintLine();
    {
        SubClass_Public spub;

        // call to non-static member function witout an object argument.
        // Parent::invoke_public();

        // alternative
        spub.Parent::invoke_public();
        // spub.Parent::invoke_protected();   // Protected member of Parent
        // spub.Parent::invoke_private();     // Private   member of Parent

        // spub.Parent::invoke_protected() // Protected member of Parent
        // spub.Parent::invoke_private();  // Private   member of Parent

        spub.invoke_parent_public();
        spub.invoke_parent_protected();
    }
    PrintLine();

    PrintLine();
    {
        SubClass_Private spriv;

        // The following are all private member of Parent.
        // spriv.Parent::invoke_public();
        // spriv.Parent::invoke_protected()
        // spriv.Parent::invoke_private();

        spriv.invoke_parent_public();
        spriv.invoke_parent_protected();
    }
    PrintLine();
    return 0;
}
