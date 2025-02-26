#include <stdio.h>
#include <stdlib.h>

#define PI 3.14
#define AREA(r) (PI * r * r)

#ifndef radius
#define radius 7
#endif

#if radius > 10
#define radius 10
#elif radius < 5
#define radius 4
#else
#define radius 7
#endif

int main()
{
    printf("Area of circle with radius %d: %f\n", radius, AREA(radius));  // Output: Area of circle with radius 6.900000: 149.571708
}