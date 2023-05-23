// Defining King
#ifndef KING_H
#define KING_H

// Inheriting from Queen
#include "Queen.h"

// Declaring class, constructor, and King's valid move
class King : public Queen {
public:
    King(int x, int y, char colour);
    bool validMove(int newX, int newY); // check if move is valid
};

#endif