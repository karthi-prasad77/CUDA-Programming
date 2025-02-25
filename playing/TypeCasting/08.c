#include <stdio.h>

typedef struct {
    float x;
    float y;
} Point;

int main()
{
    Point p = {1.1, 4.4};

    printf("Size of Point: %zu\n", sizeof(p)); // Output: 8 -> 4 bytes (float) + 4 bytes (float)

    return 0;
}