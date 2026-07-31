#include "new_maze.hpp"
#include <iostream>
#include <limits>

using std::cout; using std::cin;

int main() {
    srand(time(nullptr));

    Maze myMaze;
    myMaze.build();

    Room currentRoom;
    myMaze.start();
    bool gameWon = false;

    cout << "Starting Room: " << "a1" << '\n';  // Fixed for class-based approach
    cout << "Find the cheese at room " << "e5" << '\n';  // Fixed for class-based approach
    cout << "Use 'u', 'd', 'l', 'r' to move." << '\n';
    cout << "'q' to quit." << '\n';

    while (!gameWon) {
        cout << "\nYou are currently in room ";
        currentRoom.print();  // Use class method

        // Check if player found cheese (simplified for class-based approach)
        if (currentRoom.x_ == 5 && currentRoom.y_ == 'e') {  // Simplified cheese check
            cout << "You found the cheese!" << '\n';
            gameWon = true;
            break;
        }

        Room nextRoom = currentRoom.nextMove();  // Use class method

        // Fix: Correct quit condition handling
        // According to the documentation, nextMove() should return {-1, *} when quitting
        if (nextRoom.x_ == -1 && nextRoom.y_ == '*') {
            cout << "Thanks for playing!" << '\n';
            break;
        }

        if (nextRoom.x_ == -1 && nextRoom.y_ == '*') {
            cout << "Invalid move try again." << '\n';
            continue;
        }

        if (!myMaze.move(nextRoom)) {  // Use class method
            cout << "There's a wall in the way, try different direction." << '\n';
            continue;
        }

        currentRoom = nextRoom;
    }

    cout << "\nWalls:" << '\n';
    myMaze.print();  // Use class method
}