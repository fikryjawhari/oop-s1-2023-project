#ifndef WINDOW_H
#define WINDOW_H

#include "Board.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

struct chessPiece {
    sf::Sprite Sprite;
    int x, y, pieceID;
    bool draw = 0;
};

class Window {
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
    Window(int width, int height, const char *name, const char *imgPath[12]);
    bool Update();
};

#endif // WINDOW_H