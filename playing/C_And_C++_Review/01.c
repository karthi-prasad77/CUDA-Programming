#include <stdio.h>

// & "address of" operator
// * "dereference" operator

int main()
{
    int x = 10;

    int *y = &x; // & is used to get the memory address of the variable
    printf("Address of x:  %p\n", y);
    printf("Value of x: %d\n", *y);
}