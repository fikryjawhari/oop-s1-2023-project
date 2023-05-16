#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece {
public:
    Knight();
    Knight(int x_position, int y_position, string colour);
    bool validMove(int x_pos, int y_pos); // check if move is valid
};

#endif // KNIGHT_H
