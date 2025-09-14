#include <stdio.h>

// examples for each conditional macro
// #if
// #ifdef
// #ifndef
// #elif
// #else
// #endif

// macro definition
#define PI 3.14
#define AREA(r) (PI * r * r)

#ifdef radius
#define radius 7
#endif

// if else elif conditional logic
// we can only use the integer constants in #if and #elif 
#if radius > 10
#define radius 10
#elif radius < 5
#define radius 5
#endif

int main()
{
    printf("Area of circle with radius %2d : %f\n", radius, AREA(radius));
}