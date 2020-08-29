#include <iostream>
#include <cassert>

/**
 * # The General Syntax of operator overloading in C++
 *      You cannot change the meaning of operators for built-in types in C++, operators can only be overloaded for user-defined types.
 *      That is, at least one of the operands has to be of a user-defined type.
 *      TODO: As with other overloaded functions, operators can be overloaded for a certain set of parameters only once.
 *
 *      Note:
 *          The term “user-defined” might be slightly misleading.
 *          C++ makes the distinction between built-in types and user-defined types.
 *          To the former belong for example int, char, and double;
 *          To the latter belong all struct, class, union, and enum types, including those from the standard library, even though they are not, as such, defined by users.
 *
 *      A) What cannot be overloaded?
 *      -----------------------------------------
 *      Not all operators can be overloaded in C++.
 *      Among the operators that cannot be overloaded are:
 *       1) .
 *       2) ::
 *       3) sizeof
 *       4) typeid
 * TODO:  5) .*
 *       6) ?: (The only ternary operator in C++)
 *
 *      B) What operators can be overloaded?
 *      ---------------------------------------------------
 *       Among the operators that can be overloaded in C++ are these:
 *          1) arithmetic operators :
 *              1.1) all binary infix :
 *                  a) +  and +=
 *                  b) -  and -=
 *                  c) *  and *=
 *                  d) /  and /=
 *                  e) %  and %=
 *              1.2) unary prefix :
 *                  a)  +
 *                  b)  -
 *              1.3) unary prefix and postfix :
 *                  a) ++
 *                  b) --
 *          2) bit manipulation:
 *              2.1) All binary Infix
 *                  a) &   and &=
 *                  b) |   and |=
 *                  c) ^   and ^=
 *                  d) <<  and <<=
 *                  e) >>  and >>=
 *              2.2) unary prefix
 *                  a) ~
 *          3) boolean algebra:
 *              3.1) All binary Infix:
 *                  a) ==
 *                  b) !=
 *                  c) < and <=
 *                  d) > and >=
 *                  e) || and &&
 *              3.2) unary prefix
 *                  a) !
 *          4) memory management:
 *              4.1) new and delete
 *              4.2) new[] and delete[]
 *          5) implicit conversion operators
 *          6) miscellany:
 *              6.1) All binary infix:
 *                  a) =
 *                  b) []
 *                  c) ->
 *                  d) ->*
 *                  e) ,
 *              6.2) all unary prefix
 *                  a) *
 *                  b) &
 *              6.3) function call, n-ary infix
 *                  a) () (The only n-ary operator, must always be implemented as a member function)
 *
 *      However, the fact that you can overload all of these does not mean you should do so.
 *      See the basic rules of operator overloading.
 *
 *      C) Syntax for overloading and invoking?
 *      ------------------------------------------------------
 *      In C++, operators are overloaded in the form of functions with special names.
 *      As with other functions, overloaded operators can generally be implemented either
 *          as a member function of their left operand's type or
 *          as non-member functions.
 *      Whether you are free to choose or bound to use either one depends on several criteria.
 *      See "The Decision between Member and Non-member"
 *
 *      In following, '@' is a placeholder for overloaded symbol.
 *      A unary operator @, applied to an object x, is invoked either
 *          as operator@(x) or
 *          as x.operator@().
 *      A binary infix operator @, applied to the objects x and y, is called either
 *          as operator@(x,y) or
 *          as x.operator@(y).
 *
 *      Operators that are implemented as non-member functions are sometimes friend of their operand’s type.
 */

/**
 * The Decision between Member and Non-member:
 *      A) Must always be implemented as member functions
 *          ( because the syntax of the language requires them to. )
 *          1) The binary operators
 *              1.1) = (assignment),
 *              1.2) [] (array subscription),
 *              1.3) -> (member access),
 *              1.4) () (the n-ary function call) operator,
 *      B) Usually have to be implemented as non-member functions
 *          (because their left operand cannot be modified by you.)
 *          The most prominent of these are the
 *              1) input and output operators << and >>,
 *                whose left operands are stream classes from the standard library, which you cannot change.
 *
 *      C) For all operators where you have to choose
 *          to either implement them either
 *              as a member function or
 *              as a non-member function,
 *          use the following rules of thumb to decide:
 *
 *          1) If it is a unary operator,
 *              implement it as a member function.
 *          2) If a binary operator treats both operands equally (it leaves them unchanged),
 *              implement this operator as a non-member function.
 *          3) If a binary operator does not treat both of its operands equally (usually it will change its left operand),
 *              it might be useful to make it a member function of its left operand’s type,
 *              if it has to access the operand's private parts.
 */

#define USE_MEMBER_FUNCTION

class MyIntNumber
{
    int _value;

public:
    MyIntNumber() { std::cout << __PRETTY_FUNCTION__ << " : " << this << std::endl; }
    ~MyIntNumber() { std::cout << __PRETTY_FUNCTION__ << " : " << this << std::endl; }
    MyIntNumber (int value) : _value(value) { std::cout << __PRETTY_FUNCTION__ << " : " << this << std::endl; }
    int GetValue() const { return _value; }
    void SetValue(int value) { _value = value; }

    // Overloading Unary Comparision operator
    bool operator!() const { return !_value; }

#ifdef USE_MEMBER_FUNCTION
    bool operator==( const MyIntNumber& rhs ){ return _value == rhs.GetValue(); }
    bool operator< ( const MyIntNumber& rhs ){ return _value < rhs.GetValue(); }
    bool operator!=( const MyIntNumber& rhs ){ return !operator==(rhs); }
    bool operator> ( const MyIntNumber& rhs ){
        return _value > rhs.GetValue();
        // return  operator< (rhs);
    }
    bool operator<=( const MyIntNumber& rhs ){ return !operator> (rhs); }
    bool operator>=( const MyIntNumber& rhs ){ return !operator< (rhs); }
#endif

    // Overloading Unary Pre - Increment operator
    MyIntNumber& operator++() { _value++; return *this; }
    MyIntNumber& operator--() { _value--; return *this; }

    // Overloading Unary Post - Increment operator
    MyIntNumber operator++(int) { MyIntNumber tmp(_value); _value++; return tmp; }
    MyIntNumber operator--(int) { MyIntNumber tmp(_value); _value--; return tmp; }

    MyIntNumber operator+(MyIntNumber& rhs) {
        MyIntNumber res(_value + rhs.GetValue());
        return res;
    }

    MyIntNumber operator-(MyIntNumber& number) {
        MyIntNumber res(_value - number.GetValue());
        return res;
    }

    MyIntNumber operator-() {
        _value = -_value;
        return *this;
    }

    MyIntNumber operator+() {
        _value = +_value;
        return *this;
    }

};

/**
 * Overloading Binary Comparision operators
 */
#ifndef USE_MEMBER_FUNCTION
inline bool operator==(const MyIntNumber& lhs, const MyIntNumber& rhs){ return lhs.GetValue() == rhs.GetValue(); }
inline bool operator< (const MyIntNumber& lhs, const MyIntNumber& rhs){ return lhs.GetValue() < rhs.GetValue(); }
inline bool operator!=(const MyIntNumber& lhs, const MyIntNumber& rhs){ return !operator==(lhs,rhs); }
inline bool operator> (const MyIntNumber& lhs, const MyIntNumber& rhs){ return  operator< (rhs,lhs); }
inline bool operator<=(const MyIntNumber& lhs, const MyIntNumber& rhs){ return !operator> (lhs,rhs); }
inline bool operator>=(const MyIntNumber& lhs, const MyIntNumber& rhs){ return !operator< (lhs,rhs); }
#endif

/**
 * Overloading bit-manipulation, shift operators
 */
std::ostream& operator<<(std::ostream& os, const MyIntNumber& obj)
{
    os << obj.GetValue();
    return os;
}

std::istream& operator>>(std::istream& is, MyIntNumber& obj)
{
    int i;
    is >> i;
    obj.SetValue(i);
//  if( /* no valid object of T found in stream */ )
//    is.setstate(std::ios::failbit);

  return is;
}
int main ( )
{
    MyIntNumber num1(1);
    MyIntNumber num2(2);
    MyIntNumber num3;
    MyIntNumber num4;

    auto ret = (num1 <= num2);
    // Test Overloading Binary Comparision operators
    assert( num1 != num2 );
    assert( num1 <  num2 );
    assert( num1 <= num2 );
    assert( num2 >  num1 );
    assert( num2 >= num1 );
    assert( num1 == num1 );

    // Test Postfix increment
    MyIntNumber num5 = num1++;
    assert( num1 == 2 );
    assert( num5 == 1 );

    // Test Prefix increment
    MyIntNumber num6 = ++num1;
    assert( num1 == 3 );
    assert( num6 == 3 );

    // Test Postfix Decrement
    MyIntNumber num7 = num1--;
    assert( num1 == 2 );
    assert( num7 == 3 );

    // Test Prefix Decrement
    MyIntNumber num8 = --num1;
    assert( num1 == 1 );
    assert( num8 == 1 );


    auto PrintLine = []() { std::cout << "=====================" << std::endl; };
    auto PrintNumbers = [&](const std::string& msg = "") {
        PrintLine();
        std::cout << msg << std::endl;
        std::cout << " Number 1 : " << num1 << std::endl;
        std::cout << " Number 2 : " << num2 << std::endl;
        std::cout << " Number 3 : " << num3 << std::endl;
        std::cout << " Number 4 : " << num4 << std::endl;
        PrintLine();
    };

    PrintNumbers("Initial Values:\n");

    // Test Overloading bit-manipulation, shift operators
    std::cout << " Enter the integer to be stored in Number 3 : ";
    std::cin >> num3;
    std::cout << "Number 3 entered : " << num3 << std::endl;

    num3 = num2 + num1;
    num4 = -num3;
    PrintNumbers();

    // std::cout << "\n original MyIntNumber value 1 : ";
    // num1.display( );

    // num2 = - num1;

    // std::cout<<"\n original MyIntNumber value 2 : ";
    // num2.display( );

    // num3 = num1 - num2;
    // std::cout<<"\n  MyIntNumber value 3 = 1 - 2 : ";
    // num3.display( );

    // num4 = - num3;
    // std::cout<<"\n  MyIntNumber value 4 = -3: ";
    // num4.display( );

    std::cout << std::endl;
    return 0;
}
