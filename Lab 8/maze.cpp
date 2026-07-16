// implementation of maze navigation functions
// see maze.hpp for prototypes and documentation

#include "maze.hpp"
#include <iostream>

using std::cout; using std::cin; using std::endl;

void printRoom(Room room) {
    cout  
    << room.x  
    << room.y 
    << "\n";
}

bool goodDirection(const Room &rm, const char dr) {
    switch (dr) {
        case 'u':
            if ((rm.y - 1) > 0) {
                return true;
            } else {
                return false;
            }
        case 'd':
            if ((rm.y + 1) < mazeSize) {
                return true;
            } else {
                return false;
            }
        case 'l':
            if ((rm.x - 1) == '`') {
                return false;
            } else {
                return true;
            }
        case 'r':
            if ((rm.x + 1) == 'a' + mazeSize) {
                return false;
            } else {
                return true;
            }
        default:
            break;
    }
}

Room createAdjacent(const Room &rm, const char dr) {
    
}