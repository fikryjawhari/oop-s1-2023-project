#ifndef KING_H
#define KING_H

#include "Queen.h"

class King : public Queen {
public:
    King();
    King(int x, int y, char colour);
    bool validMove(int newX, int newY); // check if move is valid
};

#endif // KING_H
