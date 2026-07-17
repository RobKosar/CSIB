// implementation of maze navigation functions
// see maze.hpp for prototypes and documentation

#include "maze.hpp"
#include <iostream>

using std::cout; using std::cin; using std::endl;

// Debug functions
void printRoom(const Room &rm) {
    cout  
    << rm.x  
    << rm.y 
    << "\n";
}

// Checkers
bool matchRoom(const Room &rm1, const Room &rm2) {
    if ((rm1.x == rm2.x) && (rm1.y == rm2.y)) {
        return true;
    } else {
        return false;
    }
}

bool goodDirection(const Room &rm, const char dr) {
    switch (dr) {
        case 'u':
            if ((rm.y - 1) > 0) {
                cout << "\n" << dr << " is a good direction";
                return true;
            } else {
                cout << "\n" << dr << " is a bad direction";
                return false;
            }
        case 'd':
            if ((rm.y + 1) < mazeSize) {
                cout << "\n" << dr << " is a good direction";
                return true;
            } else {
                cout << "\n" << dr << " is a bad direction";
                return false;
            }
        case 'l':
            if ((rm.x - 1) != ('a' - 1)) {
                cout << "\n" << dr << " is a good direction";
                return true;
            } else {
                cout << "\n" << dr << " is a bad direction";
                return false;
            }
        case 'r':
            if ((rm.x + 1) == ('a' + mazeSize)) {
                cout << "\n" << dr << " is a bad direction";
                return false;
            } else {
                cout << "\n" << dr << " is a good direction";
                return true;
            }
        default:
            cout << "\n" << dr << " is a bad direction, defaulted";
            return false;
    }
}

// Constructors 
Room createAdjacent(const Room &rm, const char dr) {
    Room nrm = { rm.x , rm.y };
    switch (dr) {
        case 'u':
            nrm.y -= 1;
            break;
        case 'd':
            nrm.y += 1;
            break;
        case 'l':
            nrm.x -= 1;
            break;
        case 'r':
            nrm.x += 1;
            break;
        default:
            nrm = { '*', -1 };
    }
    return nrm;
}

const Room pickAdjacent(const Room &rm) {
    int dir = rand()%3;
    char dr;

    switch(dir) {
        case 0:
            dr = 'u';
            break;
        case 1:
            dr = 'd';
            break;
        case 2:
            dr = 'l';
            break;
        case 3:
            dr = 'r';
            break;
        default: 
            dr = 'N';
    }

    cout << "\nDir: " << dir << " dr: " << dr;
    return createAdjacent(rm, dr);
}

const Room nextMove(const Room &currentRoom) {
    char dr;
    Room trm;
    cout << "Input next move: ";
    cin >> dr;

    if (dr != 'q') {
        if (goodDirection(currentRoom, dr)) {
            trm = createAdjacent(currentRoom, dr);
        }
    } else {
        cout << "\nTriggered in next move";
        trm = {'*',-1};
    }
    return trm;
}

