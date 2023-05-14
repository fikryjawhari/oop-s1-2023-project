#include "Board.h"

Board::Board() {
    rowArray = new Row[8];
    for (int i = 0; i < 8; i++) {
        rowArray[i].setRow(i + 1); // I think this is the right
        // way to implement the 2D array, need to test
    }
}
