#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece {
protected:
    int movescale;

public:
    bool validMove(int x_pos, int y_pos); // check if move is valid
};

#endif // QUEEN_H
