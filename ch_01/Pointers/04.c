#include <stdio.h>

int main()
{
    int value = 42;
    void* ptr1 = &value; // stores address of variable value
    void** ptr2 = &ptr1; // stores address of pointer variable ptr1
    void*** ptr3 = &ptr2; // stores address of pointer variable ptr2

    printf("Value at ptr3: %d", ***(int***)ptr3);
}