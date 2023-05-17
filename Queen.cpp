#include "Queen.h"
#include <cmath>

Queen::Queen() {
}

Queen::Queen(int x, int y, char colour) : Piece(x, y, colour) {
    maxMoveDistance = 7;
}

bool Queen::validMove(int newX, int newY) {             // copies valid move checks from bishop and rook
    if (newX > 0 && newX < 9 && newY > 0 && newY < 9) { // Within board confines
        if (newY - y != 0 && newX - x == 0) {
            if (abs(newY - y) <= maxMoveDistance) {
                return true;
            }
        } else if (newY - y == 0 & newX - x != 0) {
            if (abs(newY - y) <= maxMoveDistance) {
                return true;
            }
        } else if ((y - newY) == (x - newX) || (y - newY) == (newX - x)) { // if absolute x movement is same as y movement
            if (abs(newY - y) <= maxMoveDistance) {
                return true;
            }
        }
    }
    return false;
}