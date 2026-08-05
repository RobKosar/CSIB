#include "maze.hpp"
#include <iostream>

using std::cout; using std::cin; using std::endl;

// Debug functions
void printRoom(const Room &rm) {
    cout  
    << "\n"
    << rm.x  
    << rm.y 
    << "\n";
}

void printPair(const RoomPair &pr) {
    cout  
    << "\n"
    << pr.one.x
    << pr.one.y 
    << "|"
    << pr.two.x
    << pr.two.y
    << "\n";
}

void printMaze(const RoomPair mz[]) {
    for (int i = 0; i < numWalls; i++) {
        printPair(mz[i]);
    }
}

// Initialization

void clearWalls(RoomPair rp[]) {
    for (int i = 0; i < numWalls; i++) {
        rp[i].one = {'*', -1};
        rp[i].two = {'*', -1};
    }
}

// Checkers
bool matchRoom(const Room &rm1, const Room &rm2) {
    if ((rm1.x == rm2.x) && (rm1.y == rm2.y)) {
        return true;
    } else {
        return false;
    }
}

bool matchPair(const RoomPair &pr1, const RoomPair &pr2) {
    if (matchRoom(pr1.one, pr2.one) && matchRoom(pr1.two, pr2.two)) {
        return true;
    } else if (matchRoom(pr1.one, pr2.two) && matchRoom(pr1.two, pr2.one)) {
        return true;
    } else {
        return false;
    }
}

bool checkMaze(const RoomPair mz[], const RoomPair &rp) {
    for (int i = 0; i < numWalls; i++) {
        if (matchPair(mz[i], rp)) {
            return true;
        }
    }
    return false;
}

bool goodDirection(const Room &rm, const char dr) {
    switch (dr) {
        case 'u':
            if ((rm.y - 1) >= 1) {
                // cout << "\n" << dr << " is a good direction";
                return true;
            } else {
                // cout << "\n" << dr << " is a bad direction";
                return false;
            }
        case 'd':
            if ((rm.y + 1) <= mazeSize) {
                // cout << "\n" << dr << " is a good direction";
                return true;
            } else {
                // cout << "\n" << dr << " is a bad direction";
                return false;
            }
        case 'l':
            if ((rm.x - 1) >= 'a') {
                // cout << "\n" << dr << " is a good direction";
                return true;
            } else {
                // cout << "\n" << dr << " is a bad direction";
                return false;
            }
        case 'r':
            if ((rm.x + 1) <= ('a' + mazeSize - 1)) {
                // cout << "\n" << dr << " is a good direction";
                return true;
            } else {
                // cout << "\n" << dr << " is a bad direction";
                return false;
            }
        default:
            // cout << "\n" << dr << " is a bad direction, defaulted";
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
            nrm = {'*', -1};
    }
    return nrm;
}

const Room pickAdjacent(const Room &rm) {
    int dir = rand()%4;
    char dr;
    Room nrm;

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

    if (goodDirection(rm, dr)) {
        nrm = createAdjacent(rm, dr);
    } else {
        nrm = {'*',-1};
    }

    return nrm;
}

const Room nextMove(const Room &currentRoom) {
    char dr;
    Room trm;
    cout << "Input next move: ";

    while (true) {
        if (!(cin >> dr)) {
            cout << "Invalid input. Please enter a valid direction ('u','d','l','r') or 'q' to quit: ";
            continue;
        }

        // Check if it's a quit command
        if (dr == 'q') {
            cout << "\nQuitting!";
            trm = {'!',-1}; // ! is quit
            return trm;
        }

        // Check if the direction is valid
        if (goodDirection(currentRoom, dr)) {
            trm = createAdjacent(currentRoom, dr);
            return trm;
        } else {
            cout << "Invalid direction. Please enter a valid direction ('u','d','l','r') or 'q' to quit: ";
        }
    }
}

const RoomPair pickPair(const Room &rm) {
    int dir = rand()%4;
    char dr;
    RoomPair npr;

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

    if (goodDirection(rm, dr)) {
        npr = {rm,createAdjacent(rm, dr)};
    } else {
        npr = {rm,{'*',-1}};
    }

    return npr;
}

void build(RoomPair rp[]) {
    int wallsPlaced = 0;

    clearWalls(rp);

    while (wallsPlaced < numWalls) {
        Room rm;
        rm.x = 'a' + rand() % mazeSize;
        rm.y = 1 + rand() % mazeSize;

        RoomPair candidate = pickPair(rm);

        if (candidate.two.y == -1) {
            continue;
        }

        if (!checkMaze(rp, candidate)) {
            rp[wallsPlaced] = candidate;
            wallsPlaced++;
        }
    }
}
