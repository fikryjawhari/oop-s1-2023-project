#include "Square.h"

Square::Square() {
}

Square::Square(Piece *newPiece) {
    currentPiece = newPiece;
    xPosition = 0;
    yPosition = 0;
}

Piece *Square::getPiece() {
    return currentPiece;
}

int Square::getXPosition() {
    return xPosition;
}

int Square::getYPosition() {
    return yPosition;
}

void Square::setPiece(Piece *newPiece) {
    currentPiece = newPiece;
}

void Square::setXPosition(int xPosition) {
    this->xPosition = xPosition;
}

void Square::setYPosition(int yPosition) {
    this->yPosition = yPosition;
}
