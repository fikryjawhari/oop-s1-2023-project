#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece {
public:
    bool validMove(int x_pos, int y_pos); // check if move is valid
};

#endif // ROOK_H
