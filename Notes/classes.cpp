#include <iostream>
using std::cin, std::cout;

// Accessors - Get values
// Mutators - Change values
class Date {
    private:
        int day;
        int month;
        int year;

    public:
        int getDay(){return day;} // Accessor function, also inline definition
        int getMonth(){return month;}
        int getYear(){return year;}

        void setDate(int,int,int); // Mutator function

        Date(int, int, int); // Constructor
};

// Writing functions for our Date class
// This void is an out of line definition
void Date::setDate(int m, int d, int y){
    day = d;
    month = m;
    year = y;
}

// OOL Constructors 
Date::Date(int x, int y, int z) {
    day = x;
    month = y;
    year = z;
}

int main() {
    Date birthday(0,0,0);

    birthday.setDate(7, 21, 2006);

    cout << birthday.getMonth() << '/' << birthday.getDay() << '/' << birthday.getYear();
}