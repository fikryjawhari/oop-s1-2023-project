#include "Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <stdlib.h>

using namespace std;

Game::Game() {
    Board emptyBoard;
    currentBoard = emptyBoard;
    turn = 0;
}

Game::Game(char file, Puzzle puzzle) {
    Board emptyBoard;
    string fileName(1, file);
    currentBoard = puzzle.readPuzzle(fileName);
    turn = puzzle.getPlayerToMove();
    correctMoveList = puzzle.getCorrectMovelist();
    boardMoves = puzzle.getBoardMoves();
    boardStates = puzzle.getBoardStates();
}

bool Game::isInCheck(Move move) {
    Board tempBoard;
    tempBoard.copySquareArray(currentBoard.getSquareArray());
    if (tempBoard.validMove(move) == true) {
        tempBoard.movePiece(move);
        int kingX = 0;
        int kingY = 0;
        int index = 0;
        bool kingFound = false;
        while (kingFound == false) {
            if (tempBoard.getSquareArray()[index].getPiece() != nullptr) {
                if (tempBoard.getSquareArray()[index].getPieceName() == 'K') {
                    if (tempBoard.getSquareArray()[index].getPiece()->getColour() == 'w' && turn == 1) {
                        kingX = tempBoard.getSquareArray()[index].getPiece()->getX();
                        kingY = tempBoard.getSquareArray()[index].getPiece()->getY();
                        kingFound = true;
                    } else if (tempBoard.getSquareArray()[index].getPiece()->getColour() == 'b' && turn == -1) {
                        kingX = tempBoard.getSquareArray()[index].getPiece()->getX();
                        kingY = tempBoard.getSquareArray()[index].getPiece()->getY();
                        kingFound = true;
                    }
                }
            }
            index++;
        }
        for (int i = 0; i < 64; i++) {
            if (tempBoard.getSquareArray()[i].getPiece() != nullptr) {
                if (tempBoard.getSquareArray()[i].getPiece()->getPieceType() != 'K') {
                    int currentX = tempBoard.getSquareArray()[i].getPiece()->getX();
                    int currentY = tempBoard.getSquareArray()[i].getPiece()->getY();
                    Move tempMove(currentX - 1, currentY - 1, kingX - 1, kingY - 1);
                    if (tempBoard.validMove(tempMove) == true) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int Game::playTurn(Move move) {
    if (isInCheck(move) == true) {
        std::cout << "In check, please try a different move\n";
        return -1; // in check
    } else {
        if (currentBoard.validMove(move) == true) {
            if (move.moveCompare(correctMoveList[0]) == true) {
                currentBoard.movePiece(move);
                correctMoveList.erase(correctMoveList.begin());
                return 1; // true/allowed move
            } else {
                std::cout << "Incorrect move, please try again\n";
                return 0; // incorrect move
            }
        } else {
            std::cout << "Invalid move, please try again\n";
            return -2; // invalid move
        }
    }
}

Board Game::getCurrentBoard() {
    return currentBoard;
}

int Game::getCorrectMovelistLength() {
    int n = correctMoveList.size();
    return n;
}

vector<Move> Game::getBoardMoves() {
    return boardMoves;
}

vector<string> Game::getBoardStates() {
    return boardStates;
}

void Game::showBoard(int *index) {
    sf::RenderWindow window(sf::VideoMode(700, 700), "Puzzle");
    sf::Texture texture;
    sf::Sprite sprite;
    if (!texture.loadFromFile(boardStates[*index])) {
        std::cout << "Could not load image" << std::endl;
        return;
    } else {
        sprite.setTexture(texture);
    }
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        window.draw(sprite);
        window.display();
        if (!texture.loadFromFile(boardStates[*index])) {
            std::cout << "Could not load image" << std::endl;
            return;
        } else {
            sprite.setTexture(texture);
        }
    }
}