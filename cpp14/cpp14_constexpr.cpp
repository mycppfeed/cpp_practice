#include <iostream>

constexpr int fibonoci(int x) {
    if (x == 0) return 0;
    else if (x == 1) return 1;
    else return x + fibonoci(x - 1);
}

int main() {
    const int random = rand() % 10;

    std::cout << "Random: " << random;
    // static_assert(fibonoci(random) == 55);

    static_assert(fibonoci(10) == 55);

    std::cout << fibonoci(10);
}