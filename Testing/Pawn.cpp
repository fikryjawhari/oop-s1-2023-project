// Function definitions
#include "Pawn.h"

// Constructor
Pawn::Pawn(int x, int y, char colour) : Piece(x, y, colour) {
    pieceType = 'P';
}

// Pawn's valid move
bool Pawn::validMove(int newX, int newY) {
    if (colour == 'w') { // White pawns can move 1 or 2 forward if on their home row (2), or diagonally one square upwards
        if (y == 2) {
            if (newX == x && (newY == y + 1 || newY == y + 2)) { // if white pawn hasnt yet moved, can move 1 or 2 squares
                return true;
            }
        } else if (y > 2 && y < 7) {          // if on any other square and
            if (newY == y + 1 && newX == x) { // normal move
                return true;
            } else if (newY == y + 1 && (newX == x + 1 || newX == x - 1)) { // special move only applicable if diagonal has piece
                return true;
            }
        }
    } else if (colour == 'b') { // Black pawns can move 1 or 2 forward if on their home row (7), or diagonally one square downwards
        if (y == 7) {
            if (newX == x && (newY == y - 1 || newY == y - 2)) { // if black pawn hasnt yet moved, can move 1 or 2 squares
                return true;
            }
        } else if (y > 2 && y < 7) {          // if on any other square and
            if (newY == y - 1 && newX == x) { // normal move
                return true;
            } else if (newY == y - 1 && (newX == x + 1 || newX == x - 1)) { // special move only applicable if diagonal has piece
                return true;
            }
        }
    }
    return false;
}