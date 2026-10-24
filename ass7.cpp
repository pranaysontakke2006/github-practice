#include <iostream>
using namespace std;

class Shape {
protected:
    double dim1, dim2;
public:
    void get_data() {
        cout << "Enter first dimension: ";
        cin >> dim1;
        cout << "Enter second dimension: ";
        cin >> dim2;
    }
    virtual double compute_area() = 0;
    virtual void display(double area) {
        cout << "Area = " << area << endl;
    }
    virtual ~Shape() {}
};

class Triangle : public Shape {
public:
    double compute_area() override {
        return 0.5 * dim1 * dim2;
    }
    void display(double area) override {
        cout << "Area of Triangle = " << area << endl;
    }
};

class Rectangle : public Shape {
public:
    double compute_area() override {
        return dim1 * dim2;
    }
    void display(double area) override {
        cout << "Area of Rectangle = " << area << endl;
    }
};

int main() {
    Shape *s;
    int choice;

    cout << "1. Triangle\n2. Rectangle\n3. Exit\n";

    do {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                s = new Triangle();
                s->get_data();
                s->display(s->compute_area());
                delete s;
                break;
            }
            case 2: {
                s = new Rectangle();
                s->get_data();
                s->display(s->compute_area());
                delete s;
                break;
            }
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}

