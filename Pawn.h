#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

using namespace std;

class Pawn : public Piece {
public:
    bool validMove(int x_pos, int y_pos);   // check if move is valid
    string movePiece(int x_pos, int y_pos); // move piece and return new location, should implement as a x,y instead of string
    int number = 1;
};

#endif // PAWN_H
