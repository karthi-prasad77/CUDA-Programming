#include <stdio.h>

// Void pointer - it will store the address of the variable but in a void type
// if we need to access need to cast the required type like int, float,..
// syntax: *(data_type*)void_pointer_name

int main()
{
    int num = 10;
    float pi = 3.14;
    void* vptr;

    vptr = &num;
    printf("Void pointer integer: %d\n", *(int*)vptr);
    // the above void pointer stores the address of the 
    // variable with value of type integer

    vptr = &pi;
    printf("Void pointer float: %f\n", *(float*)vptr);
    // the above void pointer stores the address of the
    // variable with value of type float
}