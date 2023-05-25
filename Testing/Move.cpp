#include "Move.h"

Move::Move() {
    x = -1;
    y = -1;
    newX = -1;
    newY = -1;
}

Move::Move(int x, int y, int newX, int newY) {
    this->x = x;
    this->y = y;
    this->newX = newX;
    this->newY = newY;
}

// This base code was repeated, made into a function for better programming practice
bool Move::moveCompare(Move moveComparator) {
    if (x == moveComparator.x && y == moveComparator.y) {
        if (newX == moveComparator.newX && newY == moveComparator.newY) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

void Move::printMove() {
    std::cout << x << ", " << y << ": " << newX << ", " << newY << "; ";
}