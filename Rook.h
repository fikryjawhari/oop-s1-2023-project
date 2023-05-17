#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece {
public:
    Rook();
    Rook(int x, int y, char colour);
    bool validMove(int newX, int newY); // check if move is valid
};

#endif // ROOK_H
