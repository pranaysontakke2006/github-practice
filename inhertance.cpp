
#include <iostream>
using namespace std;

class muu {
private:
    int a = 35;

public:
    int b, c, d;

    void display() {
        cout << "Enter two numbers: ";
        cin >> b >> c;
    }
};

class chiu : public muu {
public:
    void add() {
        display();
        d = b + c;
        cout << "Value of addition: " << d << endl;
    }
};

int main() {
    chiu s1;
    s1.add();

    return 0;
}
