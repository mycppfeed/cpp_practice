#include <stdio.h>

#define PRINTF(format, ...) \
    printf(format " %s %d", __VA_ARGS__, __FILE__, __LINE__)

int main() {
#define DEFINED

#if defined (DEFINED)
    printf("%s", "Testing");
#else
    printf("Not Defined\n");
#endif
    PRINTF("%s", "world");
    return 0;
}