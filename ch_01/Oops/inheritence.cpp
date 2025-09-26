// inheritence - reusing properties
#include <iostream>

using namespace std;

class Animal {
    public:
        void eat()
        {
            cout << "I can eat." << endl;
        }
};

class Dog : public Animal {
    public:
        void bark()
        {
            cout << "Woof Woof !" << endl;
        }
};

int main()
{
    // stack allocation object creation
    Dog rotweiler;
    rotweiler.bark();
    rotweiler.eat();
    // stack allocation object creation automatically free the memory

    // heap allocation object creation
    Dog* lab = new Dog();
    lab->bark();
    lab->eat();

    delete lab; // heap allocation object creation need to free memory manually
    // by using delete keyword

    return 0;
}