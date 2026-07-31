#include "new_maze.hpp"
#include <iostream>
#include <limits>

using std::cout; using std::cin; using std::endl;

// Debug functions
void Room::print() const {
    cout
    << "\n"
    << y_
    << x_
    << "\n";
}

void RoomPair::print() const {
    cout
    << "\n"
    << one_.y_
    << one_.x_
    << "|"
    << two_.y_
    << two_.x_
    << "\n";
}

void Maze::print() const {
    for (int i = 0; i < numWalls_; i++) {
        walls_[i].print();
    }
}

// Room methods
Room::Room() {
    x_ = -1;
    y_ = '*';
}

void Room::pick() {
    x_ = 1 + rand() % mazeSize_;
    y_ = 'a' + rand() % mazeSize_;
}

bool Room::goodDirection(const char dr) const {
    switch (dr) {
        case 'u':
            if ((y_ - 1) >= 'a') {
                return true;
            } else {
                return false;
            }
        case 'd':
            if ((y_ + 1) <= ('a' + mazeSize_ - 1)) {
                return true;
            } else {
                return false;
            }
        case 'l':
            if ((x_ - 1) >= 1) {
                return true;
            } else {
                return false;
            }
        case 'r':
            if ((x_ + 1) <= mazeSize_) {
                return true;
            } else {
                return false;
            }
        default:
            return false;
    }
}

Room Room::createAdjacent(const char dr) const {
    Room nrm;
    nrm.x_ = x_;
    nrm.y_ = y_;
    switch (dr) {
        case 'u':
            nrm.y_ -= 1;
            break;
        case 'd':
            nrm.y_ += 1;
            break;
        case 'l':
            nrm.x_ -= 1;
            break;
        case 'r':
            nrm.x_ += 1;
            break;
        default:
            nrm.x_ = -1;
            nrm.y_ = '*';
    }
    return nrm;
}

Room Room::pickAdjacent() {
    int dir = rand() % 4;
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

    if (goodDirection(dr)) {
        nrm = createAdjacent(dr);
    } else {
        nrm.x_ = -1;
        nrm.y_ = '*';
    }

    return nrm;
}

Room Room::nextMove() const {
    char dr;
    Room trm;
    cout << "Input next move: ";

    while (true) {
        if (!(cin >> dr)) {
            cout << "Invalid input. Please enter a valid direction ('u','d','l','r') or 'q' to quit: ";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        // Check if it's a quit command
        if (dr == 'q') {
            cout << "\nQuitting!";
            trm.x_ = -1;
            trm.y_ = '*'; // Consistent with documentation: {-1, *} for quit
            return trm;
        }

        // Check if the direction is valid
        if (goodDirection(dr)) {
            trm = createAdjacent(dr);
            return trm;
        } else {
            cout << "Invalid direction. Please enter a valid direction ('u','d','l','r') or 'q' to quit: ";
        }
    }
}

// RoomPair methods
void RoomPair::pick() {
    Room rm;
    rm.pick();
    one_ = rm;
    two_ = rm.pickAdjacent();
}

// Maze methods
void Maze::build() {
    int wallsPlaced = 0;

    // Initialize all walls to invalid state
    for (int i = 0; i < numWalls_; i++) {
        walls_[i] = RoomPair(Room(), Room());
    }

    while (wallsPlaced < numWalls_) {
        Room rm;
        rm.pick();
        RoomPair candidate = RoomPair(rm, rm.pickAdjacent());

        // Fix: Check if the adjacent room is valid (not uninitialized)
        // An uninitialized room has x_ = -1 and y_ = '*'
        if (candidate.two_.x_ == -1 && candidate.two_.y_ == '*') {
            continue;
        }

        if (!checkMaze(candidate)) {
            walls_[wallsPlaced] = candidate;
            wallsPlaced++;
        }
    }
}

bool Maze::checkMaze(const RoomPair& rp) const {
    for (int i = 0; i < numWalls_; i++) {
        if (matchPair(walls_[i], rp)) {
            return true;
        }
    }
    return false;
}

bool Maze::move(const Room& nextRoom) {
    RoomPair movePair = RoomPair(currentRoom_, nextRoom);

    if (checkMaze(movePair)) {
        return false; // There's a wall in the way
    } else {
        currentRoom_ = nextRoom;
        return true; // Move successful
    }
}

// Friend functions
bool matchRoom(const Room& rm1, const Room& rm2) {
    if ((rm1.x_ == rm2.x_) && (rm1.y_ == rm2.y_)) {
        return true;
    } else {
        return false;
    }
}

bool matchPair(const RoomPair& pr1, const RoomPair& pr2) {
    if (matchRoom(pr1.one_, pr2.one_) && matchRoom(pr1.two_, pr2.two_)) {
        return true;
    } else if (matchRoom(pr1.one_, pr2.two_) && matchRoom(pr1.two_, pr1.one_)) {
        return true;
    } else {
        return false;
    }
}