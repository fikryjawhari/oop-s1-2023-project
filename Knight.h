#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece {
public:
    Knight();
    Knight(int x, int y, char colour);
    bool validMove(int newX, int newY); // check if move is valid
};

#endif // KNIGHT_H
