// hide the data from the user
#include <iostream>

using namespace std;

class Car
{
    private:
        int speed;

    public:
    // setter
        void setSpeed(int s)
        {
            speed = s;
        }

    // getter
        int getSpeed()
        {
            return speed;
        }
};

int main()
{
    Car tesla;

    // set the speed
    tesla.setSpeed(120);

    // get the value using getter
    cout << "Car speed: " << tesla.getSpeed() << endl;

    return 0;
}