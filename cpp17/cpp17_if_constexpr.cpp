// cpp17_if_constexpr.cpp

#include <stdio.h>
#include <string>
#include <type_traits>

template <typename T>
auto length(T const& value) {
    // Causes error without constexpr
    // if ( std::is_integral<T>::value) {
    if constexpr ( std::is_integral<T>::value) {
        printf("Type is integral\n");
        return value;
    }
    else {
        printf("Type is not integral\n");
        return value.length();
    }
}

int main() {
    int n{64};
    std::string str{"HelloWorld"};

    printf("Lenght of int: %d\n", length(n));
    printf("Lenght of str: %zu\n", length(str));

    return 0;
}