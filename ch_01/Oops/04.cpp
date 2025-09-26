#include <iostream>

using namespace std;

class Book {
    public:
        string title;
        string author;

        // Constructor
        Book(string t, string a)
        {
            title = t;
            author = a;
        }

        void display()
        {
            cout << title << " by " << author << endl;
        }
};

int main()
{
    Book b1("Harry Potter", "AuthorA");
    Book b2("Ramayanam", "Valmihi");

    b1.display();
    b2.display();

    return 0;
}