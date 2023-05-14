#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece {
public:
    Bishop();
    Bishop(int x_position, int y_position, string colour);
    bool validMove(int x_pos, int y_pos); // check if move is valid
};

#endif // BISHOP_H
