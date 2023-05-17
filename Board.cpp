#include "Board.h"
#include "Piece.h"

Board::Board() {
    squareArray = new Square[8 * 8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            squareArray[i * 8 + j].setXPosition(j);
            squareArray[i * 8 + j].setYPosition(i);
        }
    }
}

Square *Board::getSquareArray() {
    return squareArray;
}
