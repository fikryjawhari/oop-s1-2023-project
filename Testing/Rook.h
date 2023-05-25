// Defining Rook
#ifndef ROOK_H
#define ROOK_H

// Inheriting from abstract piece
#include "Piece.h"

// Delcaring class, constructor, and valid move
class Rook : public Piece {
public:
    Rook(int x, int y, char colour);
    bool validMove(int newX, int newY); // check if move is valid
};

#endif
