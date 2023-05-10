#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class WhitePawn : public Piece {
public:
    bool validMove(int x_pos, int y_pos); // check if move is valid
};

#endif // PAWN_H
