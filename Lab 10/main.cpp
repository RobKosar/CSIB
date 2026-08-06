#include "list.hpp"
#include <iostream>
using namespace std;

int main() {
    int size = 0;
    double *numbers = new double[size];

    char operation;
    double number;

    while (true) {
        cout << "enter operation [a/r/q] and number: ";
        cin >> operation >> number;

        if (operation == 'q') {
            break;
        }

        if (operation == 'a') {
            // Add number
            if (check(numbers, number, size) != -1) {
                cout << "duplicate!" << endl;
            } else {
                addNumber(numbers, number, size);
                cout << "your numbers: ";
                output(numbers, size);
            }
        }

        if (operation == 'r') {
            // Remove number
            if (check(numbers, number, size) == -1) {
                cout << "not present!" << endl;
            } else {
                removeNumber(numbers, number, size);
                cout << "your numbers: ";
                output(numbers, size);
            }
        }
    }

    delete[] numbers;

    return 0;
}