#include <stdio.h>

int main()
{
    int value = 44;

    // Storing the memory address of the value into ptr1 pointer variable
    int *ptr1 = &value;

    // Storing the ptr1 address into ptr2 pointer variable
    int **ptr2 = &ptr1;

    // Storing the ptr2 address into ptr3 pointer variable
    int ***ptr3 = &ptr2;

    printf("Value inside ptr3: %d\n", **ptr2);
}