#include <iostream>

using namespace std;

class Student {
    public:
        string name;
        int age;

        void introduce() {
            cout << "Hi, I am " << name << " and I am " << age << " years old." << endl;
        }
};

int main()
{
    Student s1, s2;

    s1.name = "Karthi Prasad";
    s1.age = 22;

    s2.name = "Yaswath Kumar";
    s2.age = 21;

    s1.introduce();
    s2.introduce();

    return 0;
}