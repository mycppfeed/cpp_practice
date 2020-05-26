#include <iostream>
#include <tuple> // Required for std::tuple
#include <string>

using MyTuple = std::tuple<int, double, std::string>;

/*
* Returning multiple values from a function by binding them in a single
* tuple object.
*/
MyTuple GetMyTuple()
{
    // Creating a tuple of int, double and string
    MyTuple result(7, 9.8, "text");

    // Returning tuple object
    return result;
}
int main()
{
    // Get tuple object from a function
    MyTuple result = GetMyTuple();

    // Get values from tuple
    int iVal = std::get<0>(result);
    double dVal = std::get<1>(result);
    std::string strVal = std::get<2>(result);

    // Print values
    std::cout << "int value = " << iVal << std::endl;
    std::cout << "double value = " << dVal << std::endl;
    std::cout << "string value = " << strVal << std::endl;

    // Get 4th int value from tuple Will cause compile error
    // because this tuple has only 3 elements

    // int iVal2 = std::get<4>(result); // Compile error

    // Wrong cast will force compile time error
    // std::string strVal2 = std::get<0>(result); // Compile error

    int i = 1;
    const int const_i = 1;

    // Compile error because i is not compile time contant
    // double dVal2 = std::get<i>(result);


    double dVal3 = std::get<const_i>(result);
    return 0;
}