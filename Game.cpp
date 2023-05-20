#include "Game.h"

Game::Game() {
    Board emptyBoard;
    turn = 0;
    boardHistory.insert(boardHistory.begin(), emptyBoard);
}

Game::Game(int turn, Board currentBoard) {
    this->turn = turn;
    this->currentBoard = currentBoard;
    boardHistory.insert(boardHistory.end(), currentBoard);
}

bool Game::isInCheck(Move move) {
    Board tempBoard = currentBoard;
    tempBoard.movePiece(move);
    int kingX, kingY;
    for (int i = 0; i < 64; i++) {
        if (tempBoard.getSquareArray()[i].getPieceName() == 'K') {
            if (tempBoard.getSquareArray()[i].getPiece()->getColour() == 'w' && turn == 1) {
                kingX = tempBoard.getSquareArray()[i].getPiece()->getX();
                kingY = tempBoard.getSquareArray()[i].getPiece()->getY();
            } else if (tempBoard.getSquareArray()[i].getPiece()->getColour() == 'b' && turn == -1) {
                kingX = tempBoard.getSquareArray()[i].getPiece()->getX();
                kingY = tempBoard.getSquareArray()[i].getPiece()->getY();
            }
        }
    }
    for (int i = 0; i < 64; i++) {
        if (tempBoard.getSquareArray()[i].getPiece() != nullptr) {
            int currentX = tempBoard.getSquareArray()[i].getPiece()->getX();
            int currentY = tempBoard.getSquareArray()[i].getPiece()->getY();
            Move tempMove(currentX, currentY, kingX, kingY);
            if (tempBoard.validMove(tempMove) == true) {
                return true;
            }
        }
    }
    return false;
}

void Game::playTurn(Move move) {
}