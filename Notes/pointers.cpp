#include <iostream>
using std::cin, std::cout;

// Pointers can be passed as parameters to and returned by functions

// Passing pointer by value
void funcVal(int *p) { // Takes in the address of a variable, called like: funcVal(ptr), where int *ptr = &x
                       // It then creates a new pointer, so now we have two pointers in our code.
                       // One pointer is ptr, the other is p. Both point to the memory location of x

    *p = 22; // *p means go to the memory location in the pointer, and change the value to 22.
             // So whatever variable was passed into the funciton call is now 22

    p = new int(33); // New finds a free memory address, assigns it to p, then it puts int 33 in it.
                     // This line will cause a memory leak, we have given p a new memory location and stored 33,
                     // with no way to access it outside of the void function.
                     // ptr and x are unchanged by this line. 
}

// Passing pointer by reference
void funcRef(int *&p) { // Takes in the address of a variable, called like funcRef(ptr), where int *ptr = &x
                         // However, instead of making a new pointer p it references the pointer that was passed (ptr)

    *p = 44; // This goes to the object stored in the memory location, and sets it to 44
             // So if we passed ptr into the function call, x now equals 44

    p = new int(55); // Finds free memory address, assigns it to ptr, then puts 55 in it
                     // ptr, which lives outside of the function, is now pointing to a new memory location with 55 in it
                     // ptr no longer points to the memory location of x
}

// Passing pointer to pointer, superseded by above, not an often used method
void funcRefRef(int **pp) { // Creates a new pointer inside the function that points to a pointer

    **pp = 66; // Accesses the value inside. If int *ptr = &x was passed into the function call, this line makes x = 66

    *pp = new int(77); // new finds an empty memory location, assigns it to int 77.
                       // Before, pp was the memory location of the pointer passed into the function.
                       // *pp is the value of the pointer ptr, which is the memory location of the variable passed, x.
                       // Now, ptr is the memory location of the new int, and it no longer points to the memory location of x.
}

// Returning pointer 
int *funcRet() { // This will return a memory address to an integer
                 // If the function is called as int *p = funcRet(), first, a pointer p is created. p points nowhere.

    int *tmp = new int(88); // Finds an empty memory location, puts int 88 in it.
                            // Then, it assigns the memory location to a pointer, called tmp.

    return tmp; // Now we return the pointer variable, and p is now pointing to the memory location of int 88
}

int main() {
    int v = 55;
    int *x = &v; // &v is the memory location of v, not the value
                 // *x is saying x is a pointer variable 

    cout << x << " " << *x; // x will give the memory location of v
                            // *x will give the value of v

}