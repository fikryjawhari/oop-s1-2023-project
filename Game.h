#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Puzzle.h"
#include <string>

class Game {
private:
    Board currentBoard;
    int turn; // 1 if white, -1 if black
    vector<Move> correctMoveList;
    vector<Move> boardMoves;

public:
    Game();
    Game(int turn, std::string fileName, Puzzle puzzle);
    bool isInCheck(Move move);
    int playTurn(Move move);
    Board getCurrentBoard();
    int getCorrectMovelistLength();
    vector<Move> getBoardMoves();
};

#endif // GAME_H
