// #include<iostream.h>
// using namespace std;


// class student{
//     private: 
//      int a;

//     public:
//     int b,c;
//     cout>>("enter a number") ;
//     cin<<(b,c);
//     void diaplay{
//         cout>>(a,b,c)
//     };

    
// }

// int main(
//     student s1 ;
//     student s2;
//     s1.
// )

#include <iostream>
using namespace std;

class Student {
private:
    int rollNo;

protected:
    int marks;

public:
    string name;

    void setData() {
        rollNo = 101;
        marks = 85;
        name = "Rahul";
    }

    void display() {
        cout << "Roll Number: " << rollNo << endl;
        cout << "Marks: " << marks << endl;
        cout << "Name: " << name << endl;
    }
};

int main() {
    Student s1;  // Object creation

    s1.setData();
    s1.name="pranay";
    s1.display();


    return 0;
}
