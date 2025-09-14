// size_t = size type for memory allocation
// size_t is an unsigned integer data type used to represent the size of objects in bytes.
// It is guranteed to be big enough to contain the size of the biggest object the host system can handle.

// In VS code, ctrl + right click or F12 to see the definition of a function or a type
// nothing special about size_t, it's just a typedef for unsigned data

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    // size_t
    size_t size = sizeof(arr) / sizeof(arr[0]);  // sizeof(arr) -> 20 (4 bytes for integer total five elements. so 4x5 = 20) & // sizeof(arr[0]) -> 4 size of the integer data type
    printf("Size of Array: %zu\n", size); // Output: 5
    printf("Size of size_t: %zu\n", sizeof(size_t)); // Output: 8

    // z -> size_t
    // u -> unsigned int
    // %zu -> size_t

    return 0; // without any error or issue in the code
}