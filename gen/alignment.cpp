// https://stackoverflow.com/questions/381244/purpose-of-memory-alignment
#include <iostream>
#include <assert.h>

struct Foo {
    int   i;
    float f;
    char  c;
};
 
struct Empty {};
 
struct alignas(64) Empty64 {};
 
void printAlign()
{
    std::cout << "Alignment of"  "\n"
        "- char              : " << alignof(char)    << "\n"
        "- pointer           : " << alignof(int*)    << "\n"
        "- class Foo         : " << alignof(Foo)     << "\n"
        "- empty class       : " << alignof(Empty)   << "\n"
        "- alignas(64) Empty : " << alignof(Empty64) << "\n\n";
}

#if 0

int main() {
    printAlign();
    
    alignas(char) char c1, c2;
    alignas(int) int i1, i2;

    std::cout << "address of int c1 : " << &c1 << "\n\n";
    std::cout << "address of int c2 : " << &c2 << "\n\n";

    std::cout << "address of int i1 : " << &i1 << "\n\n";
    std::cout << "address of int i2 : " << &i2 << "\n\n";

    return 0;
}

#else

#include <stdio.h>
int main() {
    printAlign();
    
    alignas(alignof(char)) char c1, c2;
    
    // same as above alignas
    alignas(int) int i1, i2;
    
    // Note that each variable is 32 byte aligned
    alignas(32) char c3, c4;
    alignas(32) int i3, i4;
  
    printf("address of int c1 : %p \n\n", &c1);
    printf("address of int c2 : %p \n\n", &c2);
    
    printf("address of int i1 : %p \n\n", &i1);
    printf("address of int i2 : %p \n\n", &i2);

    printf("address of int c3 : %p \n\n", &c3);
    printf("address of int c4 : %p \n\n", &c4);
    
    printf("address of int i3 : %p \n\n", &i3);
    printf("address of int i4 : %p \n\n", &i4);
    return 0;
}

#endif
