#include "Piece.h"

Piece::Piece(int x, int y, char colour) {
    this->x = x;
    this->y = y;
    this->colour = colour;
}

int Piece::getX() {
    return x;
}

int Piece::getY() {
    return y;
}