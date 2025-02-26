// size_t = size type for memory allocation
// size_t is an unsigned integer data type used to represent the size of objects in bytes. 
// size_t -> unsigned long long int data type

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    size_t size = sizeof(arr) / sizeof(arr[0]);

    printf("Size of Array: %zu\n", size); // %zu for size_t (unsigned long long int) 

    printf("size of size_t: %zu\n", sizeof(size_t));  // Output: 8 (bytes) -> 64 bits which is memory safe
    printf("int size in bytes: %zu\n", sizeof(int));  // Output: 4 (bytes) -> 32 bits

    return 0;
}