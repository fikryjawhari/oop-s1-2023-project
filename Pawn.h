#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece {
public:
    Pawn();
    Pawn(int x, int y, char colour);
    bool validMove(int newX, int newY); // check if move is valid
};

#endif // PAWN_H
