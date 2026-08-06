#include "vector_list.hpp"
#include <iostream>
#include <algorithm>
using namespace std;

List::List() {
    list_.clear();
}

int List::check(double number) {
    auto it = find(list_.begin(), list_.end(), number);
    if (it != list_.end()) {
        return distance(list_.begin(), it);
    }
    return -1;
}

void List::addNumber(double number) {
    if (check(number) != -1) {
        return;
    }

    list_.push_back(number);
}

void List::removeNumber(double number) {
    int index = check(number);
    if (index == -1) {
        return;
    }

    list_.erase(list_.begin() + index);
}

void List::output() {
    for (size_t i = 0; i < list_.size(); i++) {
        cout << list_[i];
        if (i < list_.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

List::List(const List& other) {
    list_ = other.list_;
}

List& List::operator=(const List& other) {
    if (this != &other) {
        list_ = other.list_;
    }

    return *this;
}

List::~List() {
    list_.clear();
}