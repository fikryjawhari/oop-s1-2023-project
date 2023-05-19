#include "Rook.h"

Rook::Rook(int x, int y, char colour) : Piece(x, y, colour) {
    pieceType = 'R';
}

// y increase -> no x increase OR x increase -> no y increase
bool Rook::validMove(int newX, int newY) {
    if (newX > 0 && newX < 9 && newY > 0 && newY < 9) { // Within board confines
        if (newY - y != 0 && newX - x == 0) {
            return true;
        } else if ((newY - y == 0) && (newX - x != 0)) {
            return true;
            /*   If time, add castle functoinality, otherwise dont have any puzzles that require castling
            } else if (colour == "w") {
                if ((x == 1 || x == 8) && )
            }
            */
        }
    }
    return false;
}
