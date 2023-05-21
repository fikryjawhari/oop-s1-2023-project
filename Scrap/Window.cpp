#include "Window.h"
#include <SFML/Graphics.hpp>
#include <iostream>

void Window::scaleWindow() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            squares[i][j].setPosition(sf::Vector2f(windowHolder.left + (i * windowHolder.width / 8), windowHolder.top + (j * windowHolder.height / 8)));
            squares[i][j].setSize(sf::Vector2f(windowHolder.width / 8, windowHolder.height / 8));
        }
    }
}

void Window::drawSquares() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            baseWindow.draw(squares[i][j]);
        }
    }
}

void Window::drawPieces() {
    for (int i = 0; i < 64; ++i) {
        if (pieces[i].draw == true) {
            baseWindow.draw(pieces[i].Sprite);
        }
    }
}

void Window::mapPieces() {
    for (int i = 0; i < 64; ++i) {
        if (pieces[i].draw == true) {
            pieces[i].Sprite.setPosition(sf::Vector2f(windowHolder.left + (pieces[i].x * windowHolder.width / 8), windowHolder.top + (pieces[i].y * windowHolder.height / 8)));
            pieces[i].Sprite.setScale(windowHolder.width / 1600.f, windowHolder.height / 1600.f);
        }
    }
}

void Window::mapPieces(Move curr) {
    renderableChessPiece *current;
    for (int i = 0; i < 64; ++i) {
        if (pieces[i].draw == true) {
            if (pieces[i].x == curr.x && pieces[i].y == curr.y) {
                current = &pieces[i];
            }
            if (pieces[i].x == curr.newX && pieces[i].y == curr.newY) {
                pieces[i].draw = false;
            }
            pieces[i].Sprite.setPosition(sf::Vector2f(windowHolder.left + (pieces[i].x * windowHolder.width / 8), windowHolder.top + (pieces[i].y * windowHolder.height / 8)));
            pieces[i].Sprite.setScale(windowHolder.width / 1600.f, windowHolder.height / 1600.f);
        }
    }
    current->x = curr.newX;
    current->y = curr.newY;
    current->Sprite.setPosition(sf::Vector2f(windowHolder.left + (current->x * windowHolder.width / 8), windowHolder.top + (current->y * windowHolder.height / 8)));
    current->Sprite.setScale(windowHolder.width / 1600.f, windowHolder.height / 1600.f);
}

void Window::mapBoard(Square *inputBoard) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board.array[i][j] = inputBoard[i * 8 + j].getPieceNumber();
        }
    }
}

Window::Window(int width, int height, const char *windowName, const char *pieceImagePath[12], Square *inputBoard) {
    bool sColor = true;
    squareColours[0].r = 118;
    squareColours[0].g = 150;
    squareColours[0].b = 86;
    squareColours[1].r = 238;
    squareColours[1].g = 238;
    squareColours[1].b = 210;
    selectedX = width;
    selectedY = height;
    windowHolder.left = 0;
    windowHolder.top = 0;
    windowHolder.width = width;
    windowHolder.height = height;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            squares[i][j].setFillColor(squareColours[sColor]);
            sColor = !sColor;
        }
        sColor = !sColor;
    }
    scaleWindow();
    sf::IntRect blank;
    for (int i = 0; i < 12; ++i) {
        pieceTextures[i].loadFromFile(pieceImagePath[i], blank);
    }
    int index = 0;
    mapBoard(inputBoard);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            pieces[index].pieceID = board.array[i][j];
            pieces[index].x = i;
            pieces[index].y = j;
            if (pieces[index].pieceID != 0) {
                pieces[index].Sprite.setTexture(pieceTextures[pieces[index].pieceID], true);
                pieces[index].draw = 1;
            }
            ++index;
        }
    }
    mapPieces();
    baseWindow.create(sf::VideoMode(width, height), windowName);
}

bool Window::update() {
    sf::Event event;
    while (baseWindow.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Resized:
            selectedX = baseWindow.getSize().x;
            selectedY = baseWindow.getSize().y;
            baseWindow.setView(sf::View(sf::FloatRect(0, 0, selectedX, selectedY)));
            if (selectedX > selectedY) {
                windowHolder.width = selectedY;
                windowHolder.height = selectedY;
                windowHolder.left = selectedX / 2 - windowHolder.width / 2;
                windowHolder.top = 0;
            } else {
                windowHolder.width = selectedX;
                windowHolder.height = selectedX;
                windowHolder.top = selectedY / 2 - windowHolder.height / 2;
                windowHolder.left = 0;
            }
            scaleWindow();
            break;
        case sf::Event::MouseButtonPressed:
            if (event.mouseButton.button == sf::Mouse::Button::Left) {
                int pX, pY;
                pX = event.mouseButton.x;
                pY = event.mouseButton.y;
                int projX, projY;
                projX = ((pX - windowHolder.left) - ((pX - windowHolder.left) % (windowHolder.width / 8))) / (windowHolder.width / 8);
                projY = ((pY - windowHolder.top) - ((pY - windowHolder.top) % (windowHolder.height / 8))) / (windowHolder.height / 8);
                if (selected == false) {
                    if (pX >= windowHolder.left && pX <= windowHolder.left + windowHolder.width && pY > windowHolder.top && pY < windowHolder.top + windowHolder.height) {
                        finalSquare[0] = projX;
                        finalSquare[1] = projY;
                        squares[finalSquare[0]][finalSquare[1]].setFillColor(sf::Color(186, 202, 68));
                        selected = true;
                    }
                } else {
                    if (finalSquare[0] == projX && finalSquare[1] == projY) {
                        squares[finalSquare[0]][finalSquare[1]].setFillColor(squareColours[1 - ((finalSquare[0] + finalSquare[1]) % 2)]);
                        selected = false;
                    } else {
                        Move m(finalSquare[0], finalSquare[1], projX, projY);
                        // if (cBoard.validMove(m)) {
                        //     cBoard.movePiece(m);
                        // }
                        squares[finalSquare[0]][finalSquare[1]].setFillColor(squareColours[1 - ((finalSquare[0] + finalSquare[1]) % 2)]);
                        selected = false;
                    }
                }
            } else if (event.mouseButton.button == sf::Mouse::Button::Right) {
                squares[finalSquare[0]][finalSquare[1]].setFillColor(squareColours[1 - ((finalSquare[0] + finalSquare[1]) % 2)]);
                selected = true;
            }
            break;
        case sf::Event::Closed:
            baseWindow.close();
            return false;
            break;
        default:
            break;
        }
    }
    baseWindow.clear();
    drawSquares();
    baseWindow.display();
    return true;
}
