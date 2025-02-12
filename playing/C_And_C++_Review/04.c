#include <stdio.h>
#include <stdlib.h>

void check_null_pointer()
{
    int* ptr = NULL;

    if (ptr == NULL)
    {
        printf("It is a Null Pointer. 🤗\n");
    }else{
        printf("It is not a Null Pointer. 😅\n");
    }
}

void dangling_memory_check()
{
    int *ptr = malloc(sizeof(int));
    
    // check dynamic memory allocation done success.
    if (ptr == NULL)
    {
        printf("Memory allocation failed.");
        //return 1;
    }

    printf("After memory allocation pointer value : %p\n", (void*)ptr);

    // safe to use the pointer after null check
    *ptr = 44;
    printf("1. Value at ptr: %d\n", *ptr);

    // clean up the memory
    free(ptr);
    ptr = NULL;

    printf("2. After free, ptr value: %p\n", (void*)ptr);

    // Demonstrate safety of NULL check after free
    if (ptr == NULL) {
        printf("7. ptr is NULL, safely avoided use after free\n");
    }

    //return 0;

}

int main()
{
    // Null pointer points to empty pointer or unintialized

    // check for null pointer check functionality
    check_null_pointer();

    // A dangling pointer occurs when a pointer still holds an address after the memory is deallocated.
    dangling_memory_check();
}