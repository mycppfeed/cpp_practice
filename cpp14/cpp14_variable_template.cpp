#include <stdio.h>

template <typename T>
constexpr T pi = T(3.123456789);

void test_1() {
    int iPi = pi<int>;
    float fPi = pi<float>;
    double dPi = pi<double>;

    printf("%d\n", iPi);
    printf("%f\n", fPi);
    printf("%E\n", dPi);
}

/////////////////////////////////////////////////////////////////////////////////
// Function template using variable template -
//      From https://en.cppreference.com/w/cpp/language/variable_template
/////////////////////////////////////////////////////////////////////////////////

// Function template
template<class T>
T get2Pi(T r)
{
    return pi<T> * 2; // pi<T> is a variable template instantiation
}

void test_2() {
    int iPi;
    float fPi;
    double dPi;

    iPi = get2Pi(iPi);
    fPi = get2Pi(fPi);
    dPi = get2Pi(dPi);

    printf("%d\n", iPi);
    printf("%f\n", fPi);
    printf("%E\n", dPi);
}

/////////////////////////////////////////////////////////////////////////////////
// Additional from Pluralsight - Practical C++14/C++17 by Giovanni Dicanio
/////////////////////////////////////////////////////////////////////////////////

template <typename T>
constexpr T maxValue = T(1000);

// Template specializations
template <>
constexpr double maxValue<double> = 2000;

template <>
constexpr char maxValue<char> = 'Z';

void test_3() {
    printf(" maxValue<int> = %d\n", maxValue<int>);
    printf(" maxValue<double> = %f\n", maxValue<double>);
    printf(" maxValue<char> = %c\n", maxValue<char>);
}

int main() {
    test_1();
    test_2();
    test_3();

    return 0;
}