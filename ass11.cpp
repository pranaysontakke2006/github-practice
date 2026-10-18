#include <iostream>
#include <stdexcept>
#include <string>
#include <limits>

using namespace std;

class ArithmeticException : public runtime_error {
public:
    explicit ArithmeticException(const string& message) : runtime_error(message) {}
};

class ArrayIndexOutOfBoundsException : public out_of_range {
public:
    explicit ArrayIndexOutOfBoundsException(const string& message) : out_of_range(message) {}
};

int divide(int numerator, int denominator) {
    if (denominator == 0) {
        throw ArithmeticException("Division by zero is not allowed");
    }
    return numerator / denominator;
}

int getElement(const int arr[], int size, int index) {
    if (index < 0 || index >= size) {
        throw ArrayIndexOutOfBoundsException("Index " + to_string(index) + " is out of bounds for array of size " + to_string(size));
    }
    return arr[index];
}

int readInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            return value;
        }
        cout << "Invalid input. Please enter an integer." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void handleArithmetic() {
    int a = readInt("Enter numerator: ");
    int b = readInt("Enter denominator: ");
    try {
        int result = divide(a, b);
        cout << "Result: " << result << endl;
    } catch (const ArithmeticException& e) {
        cout << "Arithmetic Exception: " << e.what() << endl;
    }
}

void handleArray() {
    const int size = 5;
    int arr[size] = {10, 20, 30, 40, 50};
    int index = readInt("Enter array index (array size is 5): ");
    try {
        int value = getElement(arr, size, index);
        cout << "Element at index " << index << ": " << value << endl;
    } catch (const ArrayIndexOutOfBoundsException& e) {
        cout << "Array Index Out Of Bounds Exception: " << e.what() << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "\n1. Divide two numbers" << endl;
        cout << "2. Access array element" << endl;
        cout << "3. Exit" << endl;
        choice = readInt("Enter your choice: ");
        try {
            switch (choice) {
                case 1:
                    handleArithmetic();
                    break;
                case 2:
                    handleArray();
                    break;
                case 3:
                    cout << "Exiting program." << endl;
                    break;
                default:
                    cout << "Invalid choice. Try again." << endl;
            }
        } catch (const exception& e) {
            cout << "Unexpected error: " << e.what() << endl;
        }
    } while (choice != 3);
    return 0;
}