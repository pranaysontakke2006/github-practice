#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
    int student_id;
    string name;
    int roll_no;
    string student_class;
    float marks;
    string address;

    void input() {
        cout << "Enter Student ID: ";
        cin >> student_id;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Roll No: ";
        cin >> roll_no;

        cout << "Enter Class: ";
        cin >> student_class;

        cout << "Enter Marks: ";
        cin >> marks;

        cout << "Enter Address: ";
        cin >> address;
    }

    void display() {
        cout << "\nStudent ID: " << student_id;
        cout << "\nName: " << name;
        cout << "\nRoll No: " << roll_no;
        cout << "\nClass: " << student_class;
        cout << "\nMarks: " << marks;
        cout << "\nAddress: " << address << endl;
    }
};

void createDatabase() {
    ofstream file("student.dat");

    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student s;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details of Student " << i + 1 << ":\n";
        s.input();

        file << s.student_id << " "
             << s.name << " "
             << s.roll_no << " "
             << s.student_class << " "
             << s.marks << " "
             << s.address << endl;
    }

    file.close();

    cout << "\nDatabase created successfully.\n";
}

void displayDatabase() {
    ifstream file("student.dat");
    Student s;

    cout << "\n--- Student Database ---\n";

    while (file >> s.student_id
                >> s.name
                >> s.roll_no
                >> s.student_class
                >> s.marks
                >> s.address) {
        s.display();
    }

    file.close();
}

void searchRecord() {
    ifstream file("student.dat");

    int id;
    bool found = false;

    cout << "Enter Student ID to search: ";
    cin >> id;

    Student s;

    while (file >> s.student_id
                >> s.name
                >> s.roll_no
                >> s.student_class
                >> s.marks
                >> s.address) {

        if (s.student_id == id) {
            cout << "\nRecord Found:\n";
            s.display();
            found = true;
            break;
        }
    }

    if (!found)
        cout << "\nRecord not found.\n";

    file.close();
}

void updateRecord() {
    ifstream file("student.dat");
    ofstream temp("temp.dat");

    int id;
    bool found = false;

    cout << "Enter Student ID to update: ";
    cin >> id;

    Student s;

    while (file >> s.student_id
                >> s.name
                >> s.roll_no
                >> s.student_class
                >> s.marks
                >> s.address) {

        if (s.student_id == id) {
            cout << "\nEnter new details:\n";
            s.input();
            found = true;
        }

        temp << s.student_id << " "
             << s.name << " "
             << s.roll_no << " "
             << s.student_class << " "
             << s.marks << " "
             << s.address << endl;
    }

    file.close();
    temp.close();

    remove("student.dat");
    rename("temp.dat", "student.dat");

    if (found)
        cout << "\nRecord updated successfully.\n";
    else
        cout << "\nRecord not found.\n";
}

void deleteRecord() {
    ifstream file("student.dat");
    ofstream temp("temp.dat");

    int id;
    bool found = false;

    cout << "Enter Student ID to delete: ";
    cin >> id;

    Student s;

    while (file >> s.student_id
                >> s.name
                >> s.roll_no
                >> s.student_class
                >> s.marks
                >> s.address) {

        if (s.student_id == id) {
            found = true;
            continue;
        }

        temp << s.student_id << " "
             << s.name << " "
             << s.roll_no << " "
             << s.student_class << " "
             << s.marks << " "
             << s.address << endl;
    }

    file.close();
    temp.close();

    remove("student.dat");
    rename("temp.dat", "student.dat");

    if (found)
        cout << "\nRecord deleted successfully.\n";
    else
        cout << "\nRecord not found.\n";
}

int main() {
    int choice;

    do {
        cout << "\n\n--- Student Database ---";
        cout << "\n1. Create Database";
        cout << "\n2. Display Database";
        cout << "\n3. Delete Record";
        cout << "\n4. Update Record";
        cout << "\n5. Search Record";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            createDatabase();
            break;

        case 2:
            displayDatabase();
            break;

        case 3:
            deleteRecord();
            break;

        case 4:
            updateRecord();
            break;

        case 5:
            searchRecord();
            break;

        case 6:
            cout << "\nProgram terminated.";
            break;

        default:
            cout << "\nInvalid choice.";
        }

    } while (choice != 6);

    return 0;
}
