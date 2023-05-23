// Function definitions
#include "Bishop.h"

// Constructor
Bishop::Bishop(int x, int y, char colour) : Piece(x, y, colour) {
    pieceType = 'B';
}

// Bishop's variation of valid move
bool Bishop::validMove(int newX, int newY) // y increase = x increse/x decrease
{
    if (newX > 0 && newX < 9 && newY > 0 && newY < 9) {
        if ((y - newY) == (x - newX) || (y - newY) == (newX - x)) { // if absolute x movement is same as y movement
            return true;
        }
    }
    return false;
}
