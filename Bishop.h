#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece {
public:
    bool validMove(int x_pos, int y_pos); // check if move is valid
};

#endif // BISHOP_H
