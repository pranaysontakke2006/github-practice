
#include <iostream>
using namespace std;

class Student {
private:
    int marks;

public:
    Student() {
        marks = 90;
    }

    friend void display(Student &s);
};

void display(Student &s) {
    cout << "Old marks: " << s.marks << endl;

    cout << "Enter new marks: ";
    cin >> s.marks;

    cout << "Updated marks: " << s.marks << endl;
}

int main() {
    Student s1;

    display(s1);

    return 0;
}
