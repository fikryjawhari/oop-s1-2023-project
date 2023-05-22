//Defining Queen
#ifndef QUEEN_H
#define QUEEN_H

#include <iostream>

//Inheriting from abstract piece
#include "Piece.h"

//Declaring class, construtor, max move distance, and valid move
class Queen : public Piece {
protected:
    int maxMoveDistance;

public:
    Queen(int x, int y, char colour);
    bool validMove(int newX, int newY); // check if move is valid
};

#endif
