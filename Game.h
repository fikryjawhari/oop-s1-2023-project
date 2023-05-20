#ifndef GAME_H
#define GAME_H

#include "Board.h"

class Game {
private:
    vector<Board> boardHistory;
    Board currentBoard;
    int turn; // 1 if white, -1 if black

public:
    Game();
    Game(int turn, Board currentBoard);
    bool isInCheck(Move move);
    void playTurn(Move move);
};

#endif // GAME_H
