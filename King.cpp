#include "King.h"

King::King(int x, int y, char colour) : Queen(x, y, colour) {
    pieceType = 'K';
    maxMoveDistance = 1;
}

bool King::validMove(int newX, int newY) {
    return true;
}
