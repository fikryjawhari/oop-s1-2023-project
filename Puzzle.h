#ifndef PUZZLE_H
#define PUZZLE_H

#include "Bishop.h"
#include "Board.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Piece.h"
#include "Queen.h"
#include "Rook.h"
#include "Square.h"
#include "Window.h"
#include <fstream>
#include <string>

using namespace std;

class Puzzle {
public:
    string currentPieceString;
    int currentPiece;
    int currentSquare = 0;
    Board readPuzzle(char fileName) {
        Board initialBoard;
        ifstream currentPuzzle("a.txt");
        while (getline(currentPuzzle, currentPieceString)) {
            currentPiece = stoi(currentPieceString);
            initialBoard.getSquareArray()[currentSquare].setPiece(currentPiece);
        }
        return initialBoard;
    };
};

#endif // PUZZLE_H
