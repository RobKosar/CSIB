#include <iostream>
#include <vector>
#include <algorithm>
using std::cin, std::cout, std::vector, std::sort, std::find;

int main() {
    vector<int> items;
    int newSize = 10;

    // add element: 
    items.push_back(55); // Vector is now [55]
    // remove element: 
    items.pop_back(); // Pops last element 
    // check if empty: 
    items.empty();
    // access first/last element: 
    items.front();
    items.back();
    // change size: 
    items.resize(newSize);
    // emptying: 
    items.clear();


    // Iterators 
    // Iterators are the arrow that goes through the vector 
    vector<int>::iterator vi;
    vector<int> v;
    v.begin(); // puts the iterator at the start 
    v.end(); // puts the iterator one unit outside the end bound 
    v.insert(vi, 10); // Inserts 10 at position of the iterator 
    v.insert(v.begin() + 2, 10); // Inserts 10 at position 3

    vector<int> v2(10);

    for (vector<int>::iterator vi2 = v2.begin(); vi2 != v2.end(); vi++) {
        *vi2 = 0;
    } // This loop goes through all elements in v2 and sets them to 0

    sort(v.begin(), v.end()); // Sorts large to small
    auto found = find(v.begin(), v.end(), 55); // returns first element in range with value 55

    typedef vector<int> intvec;

    intvec myIntegerVector;
}

