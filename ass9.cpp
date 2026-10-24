#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    float price;

public:
    Book(string t, string a, float p) {
        title = t;
        author = a;
        price = p;
        cout << "Constructor: Book '" << title << "' created.\n";
    }

    ~Book() {
        cout << "Destructor: Book '" << title << "' destroyed.\n";
    }

    void display() {
        cout << "\n--- Book Details ---";
        cout << "\nTitle: " << title;
        cout << "\nAuthor: " << author;
        cout << "\nPrice: Rs. " << price << "\n";
    }
};

int main() {
    Book* b1 = new Book("OOP", "Pranay", 50000);
    Book* b2 = new Book("DBMS", "Shravani", 2000);

    b1->display();
    b2->display();

    delete b1;
    delete b2;

    return 0;
}
