#include <stdio.h>

int main()
{
    int value = 42;
    int* ptr1 = &value; // stores address of variable value
    int** ptr2 = &ptr1; // stores address of pointer variable ptr1
    int*** ptr3 = &ptr2; // stores address of pointer variable ptr2

    printf("Value at ptr3: %d", ***ptr3);
}