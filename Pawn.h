//Defining pawns
#ifndef PAWN_H
#define PAWN_H

//Inheriting from abstract piece
#include "Piece.h"

//Declaring class, constructor, and pawn's valid move
class Pawn : public Piece {
public:
    Pawn(int x, int y, char colour);
    bool validMove(int newX, int newY); // check if move is valid
};

#endif
