
#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int marks;

    // Constructor
    Student() {
        name = "Rahul";
        marks = 90;
        cout << "Constructor called!" << endl;
    }

    // Member function
    void display() {
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
    }

    // Destructor
    ~Student() {
        cout << "Destructor called!" << endl;
    }
};

int main() {
    Student s1;

    s1.display();

    return 0;
}
