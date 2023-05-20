#include "Puzzle.h"

Puzzle::Puzzle() {
    currentPieceString = "";
    currentPiece = 0;
    currentSquare = 0;
}

Board Puzzle::readPuzzle(string fileName) {
    switch (fileName[0]) {
    case 'a':
        correctMovelist = {{3, 7, 3, 3}, {4, 4, 5, 2}, {5, 5, 3, 3}};
        break;
    case 'b':
        break;
    case 'c':
        break;
    // keep adding puzzles and right moves here
    default:
        std::cout << "Read puzzle incorrectly\n";
        break;
    }
    Board initialBoard;
    ifstream currentPuzzle("Puzzles/" + fileName + ".txt");
    if (currentPuzzle.is_open() == false) {
        cout << "No such puzzle file exists, displaying empty board.\n";
        return initialBoard;
    } else {
        while (getline(currentPuzzle, currentPieceString)) {
            currentPiece = stoi(currentPieceString);
            initialBoard.getSquareArray()[currentSquare].setPiece(currentPiece);
            currentSquare++;
        }
        return initialBoard;
    }
}

vector<Move> Puzzle::getCorrectMovelist() {
    return correctMovelist;
}
