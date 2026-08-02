#include "maze.hpp"
#include <iostream>
#include <limits>

using std::cout; using std::cin;

int main() {
    srand(time(nullptr));

    Maze myMaze;
    myMaze.build();
    myMaze.start();

    Room startRoom;
    startRoom.makeStartRoom();

    Room cheeseRoom;
    cheeseRoom.makeCheeseRoom();

    bool gameWon = false;

    cout << "Starting Room: "; startRoom.print(); cout << '\n';
    cout << "Find the cheese at room "; cheeseRoom.print(); cout << '\n';
    cout << "Use 'u', 'd', 'l', 'r' to move." << '\n';
    cout << "'q' to quit." << '\n';

    while (!gameWon) {
        Room currentRoom = myMaze.getCurrentRoom();

        cout << "\nYou are currently in room "; currentRoom.print(); cout << '\n';

        if (matchRoom(currentRoom, cheeseRoom)) {
            cout << "You found the cheese!" << '\n';
            gameWon = true;
            break;
        }

        Room nextRoom = currentRoom.nextMove();

        if (matchRoom(nextRoom, Room())) {
            cout << "Thanks for playing!" << '\n';
            break;
        }

        if (!myMaze.move(nextRoom)) {
            cout << "There's a wall in the way, try different direction." << '\n';
            continue;
        }
    }

    cout << "\n";
    myMaze.print();
}
