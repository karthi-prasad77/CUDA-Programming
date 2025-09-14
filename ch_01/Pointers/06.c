#include <stdio.h>

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int* ptr = arr; // ptr points to the first element in the array (default in c).

    printf("Poisition One: %d\n", *ptr);

    for (int i = 0; i<5; i++)
    {
        printf("%d ", *ptr);
        printf("%p\n", ptr);
        ptr++;
    }

    // Output:
    // Poisition One: 1
    // 1 000000df35dffbd0
    // 2 000000df35dffbd4
    // 3 000000df35dffbd8
    // 4 000000df35dffbdc
    // 5 000000df35dffbe0

    // Notice: Pointer is incremented by 4 bytes
}