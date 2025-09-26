// class is like a blueprint (design)
// it defines data (variables) and functions (methods)
// Example: Car is a blueprint -> color, model as data -> accelerator, brake as methods

// object is a real thing created from a class
// Example: Car car -> car is an object (like a kia brand car manufacturing)

// syntax for the class and object

#include <iostream>

using namespace std;

class ClassName {
    // Access specifiers: public, private and protected
    public:
        // data members (variables)
        int x;

        // member functions (methods)
        void display()
        {
            cout << "Value of x: " << x << endl;
        }
};