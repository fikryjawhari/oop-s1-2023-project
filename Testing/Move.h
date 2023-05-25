// Defining Move
#ifndef MOVE_H
#define MOVE_H

#include <iostream>

// Declaring struct including data members and methods
// Struct was used here instead, as all data members need to be easily modified
struct Move {
    // Data members
    int x, y, newX, newY;
    // Constructors
    Move();
    Move(int x, int y, int newX, int newY);
    // Various game related functions
    bool moveCompare(Move moveComparator);
};

#endif // MOVE_H
