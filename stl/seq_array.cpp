//cpp17_array.cpp

#include <stdio.h>
#include <array>
#include <algorithm>

int main() {
    std::array<int,10> a{0, 1, 2, 3, 4, 5, 6};

    printf("Array Size: %zu\n", a.size());
    printf("Initial Array Contents:\n");

    printf("\n\n");
    for (auto i : a) printf("%2d, ", i);
    printf("\n\n");

    printf("Element at front: %d\n", a.front());
    printf("Element at back : %d\n", a.back());
    printf("Is array empty  : %s\n", a.empty()? "True" : "False" );


    auto b = a;
    printf("\n\n");
    printf("Copy of Array A [B]:\n");
    for (auto i : b) printf("%2d, ", i);
    printf("\n\n");

    b.fill(9);
    printf("\n\n");
    printf("Array B after filling with 9:\n");
    for (auto i : b) printf("%2d, ", i);
    printf("\n\n");

    // a.
    printf("Element at position 3 in array A: %d\n", a.at(3));
    printf("Element at position 5 in array A: %d\n", a[5]);

    for(auto& i : a ) i = rand() % 20;
    printf("\n\n");
    printf("Array A after filling with random values\n");
    for (auto i : a) printf("%2d, ", i);
    printf("\n\n");

    std::sort(a.begin(), a.end());
    printf("\n\n");
    printf("Array A after Sorting:\n");
    for (auto i : a) printf("%2d, ", i);
    printf("\n\n");

    return 0;
}
