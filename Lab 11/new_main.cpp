#include "new_list.hpp"
#include <iostream>
using namespace std;

int main() {
    // Create List object
    List numbers;

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
            if (numbers.check(number) != -1) {
                cout << "duplicate!" << endl;
            } else {
                numbers.addNumber(number);
                cout << "your numbers: ";
                numbers.output();
            }
        }

        if (operation == 'r') {
            // Remove number
            if (numbers.check(number) == -1) {
                cout << "not present!" << endl;
            } else {
                numbers.removeNumber(number);
                cout << "your numbers: ";
                numbers.output();
            }
        }
    }

    return 0;
}