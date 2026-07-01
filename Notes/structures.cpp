#include <iostream>
using std::cin, std::cout;

// Kind of like a class, holds information and can be used to make variables that hold lots of info
struct Date {
    int day;
    int month;
    int year;
};

int main() {
    Date today; // Referencing the structure to make new variable

    today.day = 1; // Assignment, just like python
    today.month = 7;
    today.year = 2026; 
    // Today now represents 07/1/2026

    // Let's make one for my birthday using a different assignment method
    Date birthday = {21, 7, 2006};
    cout << birthday.month << '/' << birthday.day << '/' << birthday.year;
}