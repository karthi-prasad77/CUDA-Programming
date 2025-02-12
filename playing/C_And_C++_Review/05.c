#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4};

    int* ptr = arr; // holding the first element in the array. i.e, 1

    printf("Pointer value: %d\n", *ptr);

    for (int i = 0; i<4; i++)
    {
        printf("Value: %d\n", *ptr);
        printf("Address: %p\n", ptr);
        ptr++;
    }
}