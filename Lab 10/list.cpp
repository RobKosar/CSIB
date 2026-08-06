#include "list.hpp"
#include <iostream>
using namespace std;

void output(double *colPtr, int size) {
    for (int i = 0; i < size; i++) {
        cout << colPtr[i];
        if (i < size - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

int check(double *colPtr, double number, int size) {
    for (int i = 0; i < size; i++) {
        if (colPtr[i] == number) {
            return i;
        }
    }
    return -1;
}

void addNumber(double *& colPtr, double number, int &size) {
    if (check(colPtr, number, size) != -1) {
        return;
    }

    double *newArray = new double[size + 1];

    // Copy old elements to new array
    for (int i = 0; i < size; i++) {
        newArray[i] = colPtr[i];
    }

    newArray[size] = number;

    // Deallocate old array
    delete[] colPtr;

    // Update pointer to new array
    colPtr = newArray;

    size++;
}

void removeNumber(double *& colPtr, double number, int &size) {
    int index = check(colPtr, number, size);
    if (index == -1) {
        return;
    }

    double *newArray = new double[size - 1];

    int newIndex = 0;
    for (int i = 0; i < size; i++) {
        if (colPtr[i] != number) {
            newArray[newIndex] = colPtr[i];
            newIndex++;
        }
    }

    delete[] colPtr;

    colPtr = newArray;
    
    size--;
}