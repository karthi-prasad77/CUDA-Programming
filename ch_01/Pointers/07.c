#include <stdio.h>

int main()
{
    int arr_01[4] = {1, 2, 3, 4};
    int arr_02[4] = {5, 6, 7, 8};
    int* ptr1 = arr_01;
    int* ptr2 = arr_02;
    int* matrix[] = {ptr1, ptr2};

    for (int i = 0; i<2; i++) // row
    {
        for (int j = 0; j<4; j++) // column
        {
            printf("%d ", *matrix[i]++);
        }
        printf("\n");
    }
}