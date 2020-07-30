#include <gsl/gsl>
#include <limits.h>

int Area(int height, int width)
{
    Expects(height > 0 && width > 0);

    auto ret = height * width;

    Ensures(ret > height);

    return ret;
}

int main() {
    int height = 10;
    int widht  = 20;
    auto area = Area(height, widht);

    printf("Height : %d\n", height);
    printf("Width  : %d\n", widht);
    printf("Area   : %d\n", area);

    // Fails Pre-Condition of Area. Program will terminate.
    // auto area2 = Area(0, 10);

    // Fails Post-Condition of Area. Program will terminate.
    // auto area3 = Area(INT_MAX, INT_MAX);

    return 0;
}
