#include <iostream>
using std::cout;

class MyClass {
    public:
        MyClass(int); // Constructor
        MyClass(const MyClass&); // copy constructor 
        void operator=(const MyClass&); // Assignment overload 
    private:
        int *a_;
        int size_;
};

// Constructor
MyClass::MyClass(int size) {
    size_ = size;
    a_ = new int[size];
}

// Copy constructor 
MyClass::MyClass(const MyClass& org) {
    size_ = org.size_;
    a_ = new int[size_];
    for( int i = 0; i < size_; ++i) { 
        a_[i] = org.a_[i];
    }
}

// Assignment overload
void MyClass::operator=(const MyClass& rhs) {
    if (this != &rhs) {
        size_ = rhs.size_;
        delete [] a_;
        a_ = new int[size_];  // Deletes pointer and then does copy constructor stuff
        for (int i=0; i < size_; i++) {
            a_[i] = rhs.a_[i];
        }
    }
}

// Destructor 
MyClass::~MyClass(){
    delete [] a_;
}