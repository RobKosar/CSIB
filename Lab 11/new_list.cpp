#include "new_list.hpp"
#include <iostream>
using namespace std;

// Constructor
List::List() {
    size_ = 0;
    list_ = new double[size_];
}

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
    if (check(number) != -1) {
        return;
    }

    double *newArray = new double[size_ + 1];

    for (int i = 0; i < size_; i++) {
        newArray[i] = list_[i];
    }

    newArray[size_] = number;

    delete[] list_;

    list_ = newArray;

    size_++;
}

void List::removeNumber(double number) {
    int index = check(number);
    if (index == -1) {
        return;
    }

    double *newArray = new double[size_ - 1];

    int newIndex = 0;
    for (int i = 0; i < size_; i++) {
        if (list_[i] != number) {
            newArray[newIndex] = list_[i];
            newIndex++;
        }
    }

    delete[] list_;

    // Update pointer to new array
    list_ = newArray;

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

List::List(const List& other) {
    size_ = other.size_;
    list_ = new double[size_];

    for (int i = 0; i < size_; i++) {
        list_[i] = other.list_[i];
    }
}

List& List::operator=(const List& other) {
    if (this != &other) {
        delete[] list_;

        size_ = other.size_;
        list_ = new double[size_];

        for (int i = 0; i < size_; i++) {
            list_[i] = other.list_[i];
        }
    }

    return *this;
}

List::~List() {
    delete[] list_;
}