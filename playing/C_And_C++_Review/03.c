#include <stdlib.h>
#include <stdio.h>

// void pointers used when we dont know the datatype of the values (data).
// also used with malloc and function calls 

int main()
{
    int num = 10;
    float pi = 3.14;

    // declare a void pointer
    // void pointer is a special pointer - used to store data of any data type
    void* vptr;

    vptr = &num;

    printf("Int Void Pointer: %d\n", *(int*)vptr);
    // void pointer could not be dereference so that's y we cast into into
    // then we can dereference the pointer

    vptr = &pi;

    printf("Float Void Pointer: %f\n", *(float*)vptr);

}