#include "Window.h"
#include <SFML/Graphics.hpp>
#include <iostream>

void Window::FitToHolder() { // WORKS
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            Squares[i][j].setPosition(sf::Vector2f(Holder.left + (i * Holder.width / 8), Holder.top + (j * Holder.height / 8)));
            Squares[i][j].setSize(sf::Vector2f(Holder.width / 8, Holder.height / 8));
        }
    }
}

void Window::DrawSquares() { // WORKS
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            win.draw(Squares[i][j]);
        }
    }
}

Window::Window(int width, int height, const char *name) {
    bool sColor = 1;
    sColors[0].r = 118;
    sColors[0].g = 150;
    sColors[0].b = 86;
    sColors[1].r = 238;
    sColors[1].g = 238;
    sColors[1].b = 210;
    sX = width;
    sY = height;
    Holder.left = 0;
    Holder.top = 0;
    Holder.width = width;
    Holder.height = height;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            Squares[i][j].setFillColor(sColors[sColor]);
            sColor = !sColor;
        }
        sColor = !sColor;
    }
    std::cout << "First for loop\n";
    FitToHolder();
    sf::IntRect blank;
    win.create(sf::VideoMode(width, height), name);
}

bool Window::update() {
    sf::Event event;
    while (win.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Resized:
            sX = win.getSize().x;
            sY = win.getSize().y;
            win.setView(sf::View(sf::FloatRect(0, 0, sX, sY)));
            if (sX > sY) {
                Holder.width = sY;
                Holder.height = sY;
                Holder.left = sX / 2 - Holder.width / 2;
                Holder.top = 0;
            } else {
                Holder.width = sX;
                Holder.height = sX;
                Holder.top = sY / 2 - Holder.height / 2;
                Holder.left = 0;
            }
            FitToHolder();
            break;
        case sf::Event::MouseButtonPressed:
            if (event.mouseButton.button == sf::Mouse::Button::Left) {
                int pX, pY;
                pX = event.mouseButton.x;
                pY = event.mouseButton.y;
                int projX, projY;
                projX = ((pX - Holder.left) - ((pX - Holder.left) % (Holder.width / 8))) / (Holder.width / 8);
                projY = ((pY - Holder.top) - ((pY - Holder.top) % (Holder.height / 8))) / (Holder.height / 8);
                if (cSelect == 0) {
                    if (pX >= Holder.left && pX <= Holder.left + Holder.width && pY > Holder.top && pY < Holder.top + Holder.height) {
                        selected[0] = projX;
                        selected[1] = projY;
                        Squares[selected[0]][selected[1]].setFillColor(sf::Color(186, 202, 68));
                        cSelect = 1;
                    }
                } else {
                    if (selected[0] == projX && selected[1] == projY) {
                        Squares[selected[0]][selected[1]].setFillColor(sColors[1 - ((selected[0] + selected[1]) % 2)]);
                        cSelect = 0;
                    } else {
                        Move m(selected[0], selected[1], projX, projY);
                        // if (cBoard.validMove(m)) {
                        //     cBoard.movePiece(m);
                        // }
                        Squares[selected[0]][selected[1]].setFillColor(sColors[1 - ((selected[0] + selected[1]) % 2)]);
                        cSelect = 0;
                    }
                }
            } else if (event.mouseButton.button == sf::Mouse::Button::Right) {
                Squares[selected[0]][selected[1]].setFillColor(sColors[1 - ((selected[0] + selected[1]) % 2)]);
                cSelect = 0;
            }
            break;
        case sf::Event::Closed:
            win.close();
            return false;
            break;
        default:
            break;
        }
    }
    win.clear();
    DrawSquares();
    win.display();
    return true;
}
