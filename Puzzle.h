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
#include <iostream>
#include <string>

using namespace std;

class Puzzle {
private:
    string currentPieceString;
    int currentPiece;
    int currentSquare;
    vector<Move> correctMovelist;
    vector<Move> boardMoves;

public:
    Puzzle();
    Board readPuzzle(string fileName);
    vector<Move> getCorrectMovelist();
    vector<Move> getBoardMoves();
};

#endif // PUZZLE_H
