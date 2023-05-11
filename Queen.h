#ifndef QUEEN_H
#define QUEEN_H

#include <iostream>

#include "Piece.h"

class Queen : public Piece {
protected:
    int maxMoveDistance;

public:
    Queen();
    Queen(int x_position, int y_position, string colour);
    bool validMove(int x_pos, int y_pos); // check if move is valid
};

#endif // QUEEN_H
