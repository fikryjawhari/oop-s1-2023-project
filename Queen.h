#ifndef QUEEN_H
#define QUEEN_H

#include <iostream>

#include "Piece.h"

class Queen : public Piece {
protected:
    int maxMoveDistance;

public:
    Queen(int x, int y, char colour);
    bool validMove(int newX, int newY); // check if move is valid
};

#endif // QUEEN_H
