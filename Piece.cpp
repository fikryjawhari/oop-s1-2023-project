#include "Piece.h"

Piece::Piece(int x, int y, char colour) {
    this->x = x;
    this->y = y;
    this->colour = colour;
    pieceType = 0;
}

int Piece::getX() {
    return x;
}

int Piece::getY() {
    return y;
}

char Piece::getPieceType() {
    return pieceType;
}