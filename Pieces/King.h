#ifndef KING_H
#define KING_H

#include "Queen.h"

class King : public Queen {
public:
    King(int x_position, int y_position, string colour);
    bool validMove(int x_pos, int y_pos); // check if move is valid
};

#endif // KING_H
