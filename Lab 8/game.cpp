#include "maze.hpp"
#include <iostream>
#include <limits>

using std::cout; using std::cin;

int main() {
    srand(time(nullptr));

    RoomPair myMaze[numWalls];
    build(myMaze);

    Room currentRoom = startRoom;
    bool gameWon = false;

    cout << "Starting Room: " << startRoom.x << startRoom.y << '\n';
    cout << "Find the cheese at room " << cheeseRoom.x << cheeseRoom.y << '\n';
    cout << "Use 'u', 'd', 'l', 'r' to move." << '\n';
    cout << "'q' to quit." << '\n';

    while (!gameWon) {
        cout << "\nYou are currently in room " << currentRoom.x << currentRoom.y << '\n';

        if (matchRoom(currentRoom, cheeseRoom)) {
            cout << "You found the cheese!" << '\n';
            gameWon = true;
            break;
        }

        Room nextRoom = nextMove(currentRoom);

        if (nextRoom.x == '!') {
            cout << "Thanks for playing!" << '\n';
            break;
        }

        if (nextRoom.x == '*' && nextRoom.y == -1) {
            cout << "Invalid move try again." << '\n';
            continue;
        }

        RoomPair movePair = {currentRoom, nextRoom};
        if (checkMaze(myMaze, movePair)) {
            cout << "There's a wall in the way, try different direction." << '\n';
            continue;
        }

        currentRoom = nextRoom;
    }

    cout << "\nWalls:" << '\n';
    printMaze(myMaze);
}