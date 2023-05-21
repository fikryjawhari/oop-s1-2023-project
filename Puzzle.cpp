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
        boardMoves = {{3, 0, 3, 3}, {4, 1, 5, 2}};
        playerToMove = -1;
        break;
    case 'b':
        break;
    case 'c':
        correctMovelist = {{4, 3, 5, 4}};
        boardMoves = {};
        playerToMove = 1;
        break;
    // keep adding puzzles and right moves here
    default:
        correctMovelist = {};
        boardMoves = {};
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

vector<Move> Puzzle::getBoardMoves() {
    return boardMoves;
}

int Puzzle::getPlayerToMove() {
    return playerToMove;
}
