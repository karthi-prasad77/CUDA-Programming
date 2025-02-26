// Similar to 08.c program

#include <iostream>

using namespace std;

typedef struct {
    float a;
    float b;
} Point;

int main()
{
    Point p = {1.1, 4.4};

    printf("Size of Point: %zu\n", sizeof(p));
}