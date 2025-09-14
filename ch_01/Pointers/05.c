#include <stdio.h>
#include <stdlib.h>

// Key Points:
// 1. Initialize pointers to NULL when they dont yet point to valid data
// 2. Check pointer for NULL before using to avoid crashes
// 3. NULL checks allow graceful handling of uninitialized or failed unintialized pointers

int main()
{
    // Initialize pointer to NULL
    int* ptr = NULL;
    printf("1. Initial Pointer value: %p\n", (void*)ptr); // Output: 0000000000000000

    // Check for NULL before using
    if (ptr == NULL)
    {
        printf("2. ptr is NULL cannot be dereferenced.\n");
    }

    // Allocate memory
    ptr = malloc(sizeof(int));
    if (ptr == NULL)
    {
        printf("3. Memory allocation failed.\n");
        return 1;
    } else {
        printf("4. Memory allocation was done.\n");
    }
}