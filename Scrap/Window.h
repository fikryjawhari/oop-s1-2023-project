#ifndef WINDOW_H
#define WINDOW_H

#include "Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>

struct chessBoard {
    int array[8][8] = {0};
};

struct renderableChessPiece {
    sf::Sprite Sprite;
    int pieceID;
    int x;
    int y;
    bool draw = false;
};

class Window {
private:
    sf::RenderWindow baseWindow;
    sf::RectangleShape squares[8][8];
    sf::IntRect windowHolder;
    sf::Color squareColours[2];
    sf::Texture pieceTextures[12];
    chessBoard board;
    renderableChessPiece pieces[64];
    int finalSquare[2];
    bool selected = false;
    int selectedX, selectedY;

    void scaleWindow();
    void drawSquares();
    void drawPieces();
    void mapPieces();
    void mapPieces(Move curr);
    void mapBoard(Square *inputBoard);

public:
    Window(int width, int height, const char *windowName, const char *pieceImagePath[12], Square *inputBoard);
    bool update();
};

#endif // WINDOW_H
