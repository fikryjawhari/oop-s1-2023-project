#include "King.h"

King::King(int x, int y, char colour) : Queen(x, y, colour) {
    maxMoveDistance = 1;
}

bool King::validMove(int newX, int newY) {
    return true;
}
