#include <stdio.h> // Standard input/output header file for printf()

// "&" address of operator
// "*" dereference operator

int main()
{
    int x = 10;
    int* ptr = &x; // & operator used to get the memory address of the variable x
    printf("Address of x: %p\n", ptr); // Output: memory address will display
    printf("Value of x: %d\n", *ptr); // Output: 10
    // * in line number 11 was used to get the value 
    // of the pointer variable (dereferencing)
}

