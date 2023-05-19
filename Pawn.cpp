#include "Pawn.h"
#include <iostream>

Pawn::Pawn(int x, int y, char colour) : Piece(x, y, colour) {
    pieceType = 'P';
}

bool Pawn::validMove(int newX, int newY) {
    cout << "Pawn\n";
    if (colour == 'w') {
        cout << x << " " << y << " " << colour << endl;
        if (y == 2) {
            if (newX == x && (newY == y + 1 || newY == y + 2)) { // if white pawn hasnt yet moved, can move 1 or 2 squares
                return true;
            }
        } else if (y > 2 && y < 7) {          // if on any other square and
            if (newY == y + 1 && newX == x) { // normal move
                return true;
            } else if (newY == y + 1 && (newX == x + 1 || newX == x - 1)) { // special move only applicable if diagonal has piece, need to implement that check
                                                                            // take piece function
                return true;
            }
        }
    } else if (colour == 'b') {
        cout << x << " " << y << " " << colour << endl;
        if (y == 7) {
            if (newX == x && (newY == y - 1 || newY == y - 2)) { // if black pawn hasnt yet moved, can move 1 or 2 squares
                return true;
            }
        } else if (y > 2 && y < 7) {          // if on any other square and
            if (newY == y - 1 && newX == x) { // normal move
                return true;
            } else if (newY == y - 1 && (newX == x + 1 || newX == x - 1)) { // special move only applicable if diagonal has piece, need to implement that check
                                                                            // take piece function
                return true;
            }
        }
    }
    return false;
}