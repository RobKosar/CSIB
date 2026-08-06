class MyClass {
    private:
        int *a;
        int size; 
    public: 
        MyClass(int); // C
        ~MyClass(); // D
        MyClass(const MyClass&); // CC
        void operator=(const MyClass&); // A O
}

MyClass::MyClass(const MyClass &org) {
    size = org.size;
    a = new int[size];
    for (int i=0; i < size; ++i) {
        a[i] = org.a[i];
    }
}

void MyClass::operator=(const MyClass &rhs) {
    if (this != &rhs) {
        size = rhs.size;
        delete[]a;
        a = new int[size];
        for (int i=0; i<size; ++i){
            a[i] = rhs.a[i];
        }
    }
}