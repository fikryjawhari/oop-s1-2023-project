#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece {
public:
    Rook();
    Rook(int x_position, int y_position, string colour);
    bool validMove(int x_pos, int y_pos); // check if move is valid
};

#endif // ROOK_H
