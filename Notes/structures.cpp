#include <iostream>
using std::cin, std::cout;

// Kind of like a class, holds information and can be used to make variables that hold lots of info
struct Date {
    int day;
    int month;
    int year;
};

// A function that interacts with our struct 
Date setDate(int m, int d, int y) {
    Date tmp = {d, m, y};
    return tmp;
}

// Complex Structures
struct Time {
    int sec;
    int min;
    int hour;
};

// Date with substructure of time
struct DateTime {
    int day;
    int month;
    int year;

    Time clock;
};

int main() {
    Date today; // Referencing the structure to make new variable

    today.day = 1; // Assignment, just like python
    today.month = 7;
    today.year = 2026; 
    // Today now represents 07/1/2026

    // Let's make one for my birthday using a different assignment method
    Date birthday = {21, 7, 2006};

    // Let's make a new one using the function
    Date independence_day = setDate(7, 4, 2026);

    // Now lets look at complex structures
    Time now = {52, 10, 12};
    DateTime today_complex = {1, 7, 2026, now};
}