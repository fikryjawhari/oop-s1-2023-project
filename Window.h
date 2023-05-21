#ifndef WINDOW_H
#define WINDOW_H

#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class Window {
private:
    sf::RenderWindow win;
    sf::RectangleShape Squares[8][8];
    sf::IntRect Holder;
    sf::Color sColors[2];
    Board cBoard;
    int selected[2];
    bool cSelect = 0;
    int sX, sY;
    void FitToHolder();
    void DrawSquares();

public:
    Window(int width, int height, const char *name);
    bool update();
};

#endif // WINDOW_H
