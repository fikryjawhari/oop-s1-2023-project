#ifndef CHESS_WINDOW_H
#define CHESS_WINDOW_H
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

struct chessPiece {
    sf::Sprite Sprite;
    int pieceID, x, y;
    bool draw = 0;
};

class badWindow {
private:
    sf::RenderWindow win;
    sf::RectangleShape Squares[8][8];
    sf::IntRect Holder;
    sf::Color sColors[2];
    sf::Texture pieceTex[12];
    chessPiece pieces[64];
    Board cBoard;
    int selected[2];
    bool cSelect = 0;
    int sX, sY;

    void FitToHolder();
    void DrawSquares();
    void DrawPieces();
    void MapPieces();
    void MapPieces(Move curr);

public:
    badWindow(int width, int height, const char *name, const char *imgPath[12]);
    bool Update();
};
#endif