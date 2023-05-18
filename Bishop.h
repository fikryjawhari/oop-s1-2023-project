#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece {
public:
    Bishop(int x, int y, char colour);
    bool validMove(int newX, int newY); // check if move is valid
};

#endif // BISHOP_H
