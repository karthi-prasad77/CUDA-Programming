#include <iostream>

using namespace std;

typedef struct
{
    float x; // 4 bytes
    float y; // 4 bytes
} Point;


int main()
{
    Point p = {1.1, 2.2};
    cout << "Size of Point: " << sizeof(p) << endl; // Output: 8 bytes

    return 0;
}