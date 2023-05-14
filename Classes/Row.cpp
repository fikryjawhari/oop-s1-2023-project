#include "Row.h"

Row::Row() {
    squareArray = new Square[8];
    for (int i = 0; i < 8; i++) {
        squareArray[i].setXPosition(i + 1);
    }
}

Square *Row::getRow() {
    return squareArray;
}

void Row::setRow(int yPosition) {
    // i think this is the right way to implement the 2D array,
    // need to test to make sure, but board calls this function
    // when its constructed, cause row doesnt know what row it
    // is until it is made in board
    for (int i = 0; i < 8; i++) {
        squareArray[i].setYPosition(yPosition);
    }
}

Row::~Row() {
    delete[] squareArray;
}
