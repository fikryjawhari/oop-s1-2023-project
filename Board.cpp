#include "Board.h"
#include "Piece.h"

Board::Board() {
    squareArray = new Square[8 * 8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            squareArray[i * 8 + j].setXPosition(j + 1);
            squareArray[i * 8 + j].setYPosition(8 - i);
        }
    }
}

Board::Board(char puzzle) : Board() {
    if (puzzle = 'a') {
        //
    } else if (puzzle = 'b') {
        //
    } else if (puzzle = 'c') {
        //
    } else if (puzzle = 'd') {
        // figure out how to store puzzles here
    }
}

Square *Board::getSquareArray() {
    return squareArray;
}

// bool Board::validMove(Move move) {
//     squareArray[move.oldX * 8 + move.oldY].getPiece();
// }
