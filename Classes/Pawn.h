#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece {
public:
    Pawn();
    Pawn(int x_position, int y_position, string colour);
    bool validMove(int x_pos, int y_pos); // check if move is valid
};

#endif // PAWN_H
