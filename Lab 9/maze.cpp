#include "maze.hpp"
#include <iostream>

using std::cout; using std::cin; using std::endl;

Room::Room() : x_(-1), y_('*') {}

void Room::pick() {
    x_ = 1 + rand() % mazeSize_;
    y_ = 'a' + rand() % mazeSize_;
}

bool Room::goodDirection(const char dr) const {
    switch (dr) {
        case 'u':
            return (x_ - 1) >= 1;
        case 'd':
            return (x_ + 1) <= mazeSize_;
        case 'l':
            return (y_ - 1) >= 'a';
        case 'r':
            return (y_ + 1) <= ('a' + mazeSize_ - 1);
        default:
            return false;
    }
}

const Room Room::createAdjacent(const char dr) const {
    Room nrm = *this;
    switch (dr) {
        case 'u':
            nrm.x_ -= 1;
            break;
        case 'd':
            nrm.x_ += 1;
            break;
        case 'l':
            nrm.y_ -= 1;
            break;
        case 'r':
            nrm.y_ += 1;
            break;
        default:
            nrm = Room();
    }
    return nrm;
}

const Room Room::pickAdjacent() {
    int dir = rand() % 4;
    char dr;

    switch (dir) {
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
        return createAdjacent(dr);
    } else {
        return Room();
    }
}

const Room Room::nextMove() const {
    char dr;
    cout << "Input next move: ";

    while (true) {
        if (!(cin >> dr)) {
            cout << "Invalid input. Please enter a valid direction ('u','d','l','r') or 'q' to quit: ";
            continue;
        }

        if (dr == 'q') {
            cout << "\nQuitting!";
            return Room(); // {-1,*} is quit
        }

        if (goodDirection(dr)) {
            return createAdjacent(dr);
        } else {
            cout << "Invalid direction. Please enter a valid direction ('u','d','l','r') or 'q' to quit: ";
        }
    }
}

void Room::print() const {
    cout << y_ << x_;
}

bool matchRoom(const Room &rm1, const Room &rm2) {
    if ((rm1.x_ == rm2.x_) && (rm1.y_ == rm2.y_)) {
        return true;
    } else {
        return false;
    }
}

void RoomPair::pick() {
    Room rm;
    Room adj;

    do {
        rm.pick();
        adj = rm.pickAdjacent();
    } while (matchRoom(adj, Room())); 

    one_ = rm;
    two_ = adj;
}

void RoomPair::print() const {
    one_.print();
    cout << "|";
    two_.print();
}

bool matchPair(const RoomPair &pr1, const RoomPair &pr2) {
    if (matchRoom(pr1.one_, pr2.one_) && matchRoom(pr1.two_, pr2.two_)) {
        return true;
    } else if (matchRoom(pr1.one_, pr2.two_) && matchRoom(pr1.two_, pr2.one_)) {
        return true;
    } else {
        return false;
    }
}

bool Maze::checkMaze(const RoomPair &rp) const {
    for (int i = 0; i < numWalls_; i++) {
        if (matchPair(walls_[i], rp)) {
            return true;
        }
    }
    return false;
}

void Maze::build() {
    int wallsPlaced = 0;

    while (wallsPlaced < numWalls_) {
        RoomPair candidate;
        candidate.pick();

        if (!checkMaze(candidate)) {
            walls_[wallsPlaced] = candidate;
            wallsPlaced++;
        }
    }
}

bool Maze::move(const Room &nextRoom) {
    RoomPair movePair(currentRoom_, nextRoom);

    if (checkMaze(movePair)) {
        return false; 
    }

    currentRoom_ = nextRoom;
    return true;
}

void Maze::print() const {
    cout << "Walls:\n";
    for (int i = 0; i < numWalls_; i++) {
        walls_[i].print();
        cout << "\n";
    }
    cout << "Current room: ";
    currentRoom_.print();
    cout << "\n";
}
