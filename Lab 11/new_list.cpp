#include "new_list.hpp"
#include <iostream>
using namespace std;

// Constructor
List::List() {
    size_ = 0;
    list_ = new double[size_];
}

// Check if number exists in the list
int List::check(double number) {
    for (int i = 0; i < size_; i++) {
        if (list_[i] == number) {
            return i;
        }
    }
    return -1;
}

// Add number to the list
void List::addNumber(double number) {
    // Check if number already exists
    if (check(number) != -1) {
        return;
    }

    // Allocate new array with one more element
    double *newArray = new double[size_ + 1];

    // Copy old elements to new array
    for (int i = 0; i < size_; i++) {
        newArray[i] = list_[i];
    }

    // Add the new number
    newArray[size_] = number;

    // Deallocate old array
    delete[] list_;

    // Update pointer to new array
    list_ = newArray;

    // Increase size
    size_++;
}

// Remove number from the list
void List::removeNumber(double number) {
    // Check if number exists
    int index = check(number);
    if (index == -1) {
        return;
    }

    // Allocate new array with one less element
    double *newArray = new double[size_ - 1];

    // Copy elements, skipping the one to remove
    int newIndex = 0;
    for (int i = 0; i < size_; i++) {
        if (list_[i] != number) {
            newArray[newIndex] = list_[i];
            newIndex++;
        }
    }

    // Deallocate old array
    delete[] list_;

    // Update pointer to new array
    list_ = newArray;

    // Decrease size
    size_--;
}

// Output the list
void List::output() {
    for (int i = 0; i < size_; i++) {
        cout << list_[i];
        if (i < size_ - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

// Copy constructor
List::List(const List& other) {
    size_ = other.size_;
    list_ = new double[size_];

    for (int i = 0; i < size_; i++) {
        list_[i] = other.list_[i];
    }
}

// Assignment operator
List& List::operator=(const List& other) {
    // Check for self-assignment
    if (this != &other) {
        // Deallocate existing memory
        delete[] list_;

        // Copy new size and allocate new memory
        size_ = other.size_;
        list_ = new double[size_];

        // Copy elements
        for (int i = 0; i < size_; i++) {
            list_[i] = other.list_[i];
        }
    }

    return *this;
}

// Destructor
List::~List() {
    delete[] list_;
}