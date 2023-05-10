#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece {
public:
    bool validMove(int x_pos, int y_pos); // check if move is valid
};

#endif // KNIGHT_H
