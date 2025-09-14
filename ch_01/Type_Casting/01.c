#include <stdio.h>

int main()
{
    // C style type casting
    float pi = 3.14;
    int i = (int) pi; // float data type converted into int (Explicit type convertion)
    printf("%d\n", i); // Output: 3

    // to char data type
    char c = (char) i; // ASCII value for value i
    printf("%c\n", c);

}