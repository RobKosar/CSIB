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
};

// Writing functions for our Date class
// This void is an out of line definition
void Date::setDate(int m, int d, int y){
    day = d;
    month = m;
    year = y;
}

int main() {

}