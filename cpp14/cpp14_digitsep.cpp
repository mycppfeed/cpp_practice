#include <iostream>
#include <stdio.h>

int main() {
    int i = 10'000;
    float f = 10000.009;
    std::cout << "Int " << i << std::endl;
    std::cout << "Float " << f << std::endl;

    printf("Float %f\n", f);

    return 0;
}