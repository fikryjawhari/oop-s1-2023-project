#ifndef KING_H
#define KING_H

#include "Piece.h"
#include "Queen.h"

class King : public Piece, Queen {
public:
    bool validMove(int x_pos, int y_pos); // check if move is valid
};

#endif // KING_H
