#include <iostream>

using namespace std;

class Car {
    public:
        string brand;
        int speed;

        void drive()
        {
            cout << brand << " is driving at " << speed << " km/h" << endl;
        }
};

int main()
{
    // create a object for the class
    Car tesla;

    // assign the values for the variables in the tesla object
    tesla.brand = "tesla";
    tesla.speed = 120;

    // call the method in the class
    tesla.drive();

    return 0;
}