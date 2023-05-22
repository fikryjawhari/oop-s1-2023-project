//Function definitions
#include "King.h"

//Constructor
King::King(int x, int y, char colour) : Queen(x, y, colour) {
    pieceType = 'K';
    maxMoveDistance = 1;
}

//King's variation of valid move
bool King::validMove(int newX, int newY) {
    return true;
}
