#include "Puzzle.h"

Board Puzzle::readPuzzle(string fileName) {
    Board initialBoard;
    Square *initialBoardArray = initialBoard.getSquareArray();
    ifstream currentPuzzle("Puzzles/" + fileName + ".txt");
    if (currentPuzzle.is_open() == false) {
        cout << "No such puzzle file exists, displaying empty board.\n";
        return initialBoard;
    } else {
        while (getline(currentPuzzle, currentPieceString)) {
            currentPiece = stoi(currentPieceString);
            initialBoardArray[currentSquare].setPiece(currentPiece);
            currentSquare++;
        }
        return initialBoard;
    }
}

Puzzle::Puzzle() {
    currentPieceString = "";
    currentPiece = 0;
    currentSquare = 0;
}
