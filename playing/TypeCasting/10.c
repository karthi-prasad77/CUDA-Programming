#include <stdlib.h>
#include <stdio.h>

int main()
{
    // c type casting
    float f = 3.14;
    int i = (int)f;
    printf("%d\n", i); // Output -> 69 (Remove the decimal part)

    char c = (char)i;
    printf("%c\n", c); // Output -> E (ASCII value for the Integer (3))
}