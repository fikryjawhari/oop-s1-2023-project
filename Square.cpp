#include "Square.h"

Square::Square() {
}

Square::Square(Piece *newPiece) {
    currentPiece = newPiece;
    x = 0;
    y = 0;
}

Piece *Square::getPiece() {
    return currentPiece;
}

int Square::getXPosition() {
    return x;
}

int Square::getYPosition() {
    return y;
}

void Square::setPiece(Piece *newPiece) {
    currentPiece = newPiece;
}

void Square::setXPosition(int x) {
    this->x = x;
}

void Square::setYPosition(int y) {
    this->y = y;
}
