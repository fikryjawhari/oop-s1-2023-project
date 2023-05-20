#ifndef MOVE_H
#define MOVE_H

#include <iostream>

struct Move {
    int x, y, newX, newY;
    Move(){};
    Move(int x, int y, int newX, int newY);
    bool moveCompare(Move moveComparator);
    void printMove();
};

#endif // MOVE_H
