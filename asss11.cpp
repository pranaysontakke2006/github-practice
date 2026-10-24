
#include <iostream>
using namespace std;

int main() {
    int a, b;
    int arr[5] = {10, 20, 30, 40, 50};
    int index;

    try {
        cout << "Enter two numbers: ";
        cin >> a >> b;

        if (b == 0) {
            throw "Arithmetic Exception: Division by zero!";
        }

        cout << "Division = " << a / b << endl;

        cout << "Enter array index (0-4): ";
        cin >> index;

        if (index < 0 || index >= 5) {
            throw index;
        }

        cout << "Array element = " << arr[index] << endl;
    }
    catch (const char* msg) {
        cout << msg << endl;
    }
    catch (int i) {
        cout << "Array Index Out of Bounds: " << i << endl;
    }

    return 0;
    
}
