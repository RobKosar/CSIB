// Mikhail Nesterenko
// tests maze function implementation
// 3/25/2023

#include "maze.hpp"
#include <iostream>

using std::cout; using std::cin; using std::endl;

int main() {

    srand(time(nullptr)); // random seed
    //srand(1); // fixed seed

    Room myRoom;  // Create room using constructor
    myRoom.pick(); // initialize with random values

    // print Room
    myRoom.print();

    // make sure to implement goodDirection() and createAdjacent() first
    Room newMoveRoom = myRoom.nextMove(); // asks user for new adjacent room
    cout << "\nuser selected adjacent room: "; newMoveRoom.print();

    Room randomRoom = myRoom.pickAdjacent();
    cout << "\nrandomly selected adjacent room: "; randomRoom.print();


    if (matchRoom(randomRoom, newMoveRoom)) {
        cout << "\nrandomRoom is the same as newMoveRoom";
    }

    //
    // second part: checking wall functions
    //
    // select a fixed wall
    RoomPair myWall = RoomPair(Room('b', 2), Room('c', 2));  // Create using constructor

    // print wall
    cout << "myWall, fixed location: "; myWall.print(); cout << endl;

    // select and print a random wall
    myWall.pick();
    cout << "myWall, random location: "; myWall.print(); cout << endl;

    RoomPair myMove;
    myMove.one_ = myRoom;
    myMove.two_ = newMoveRoom;

    if (matchPair(myWall, myMove))
        cout << "there is a wall between these two rooms" << endl;
    else
       cout << "there is no wall between these two rooms" << endl;
    //
    // third part: check maze functions
    //
    Maze myMaze; // Create maze object

    myMaze.build(); // placing walls at random locations in the maze
    cout << "built maze: ";  myMaze.print(); cout << endl;

    // Test checking a specific wall
    RoomPair testPair = RoomPair(myRoom, newMoveRoom);
    if (myMaze.checkMaze(testPair))
       cout << "checkMaze returned true" << endl;
    else
       cout << "checkMaze returned false" << endl;
}