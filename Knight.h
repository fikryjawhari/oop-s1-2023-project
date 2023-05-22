//Defining Knight
#ifndef KNIGHT_H
#define KNIGHT_H

//Inheriting from abstract piece
#include "Piece.h"

//Declaring class, constructor, and knight's valid move
class Knight : public Piece {
public:
    Knight(int x, int y, char colour);
    bool validMove(int newX, int newY); // check if move is valid
};

#endif
