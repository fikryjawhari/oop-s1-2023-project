//Defining bishop
#ifndef BISHOP_H
#define BISHOP_H

//Inheriting from abstract piece
#include "Piece.h"

//Declaring class, constructor, and bishop's valid moves
class Bishop : public Piece {
public:
    Bishop(int x, int y, char colour);
    bool validMove(int newX, int newY); // check if move is valid
};

#endif
