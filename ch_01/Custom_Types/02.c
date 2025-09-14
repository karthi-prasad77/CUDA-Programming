#include <stdio.h>

typedef struct
{
    float x; // 4 bytes
    float y; // 4 bytes
} Point;


int main()
{
    Point p = {1.1, 2.2}; 
    printf("Size of Point: %zu\n", sizeof(p));
}