
//
#ifndef CHESS2_H
#define CHESS2_H

#include "/home/fikrya/oop-s1-2023-project/Game.h"

namespace Chess2 {
    bool run() {
        string puzzle;

        cout << "Welcome to OOP Chess Puzzles, your one stop chess puzzle solving experience!\n";
        cout << "Please enter the puzzle you want to work on, from a - d (a is easiest, or -1 to exit): ";

        cin >> puzzle;
        if (puzzle.compare("-1") == 0) {
            return false;
        }

        Game g1(puzzle[0], *(new Puzzle));
        vector<Move> boardMoves = g1.getBoardMoves();
        vector<string> boardFileNames = g1.getBoardStates();

        bool input = false;
        bool puzzleSolved = false;
        int invalidInputCounter = 0;
        int boardState = 0;

        sf::RenderWindow window(sf::VideoMode(700, 700), "Puzzle");
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Event event;

        if (!texture.loadFromFile(boardFileNames[boardState])) {
            std::cout << "Could not load image" << std::endl;
            return false;
        } else {
            sprite.setTexture(texture);
        }
        window.clear();
        window.draw(sprite);
        window.display();

        while (g1.getCorrectMovelistLength() > 0) {
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                char columnLetter = '0';
                int columnNum = 0;
                int rowNum = 0;

                char newColumnLetter = '0';
                int newColumnNum = 0;
                int newRowNum = 0;

                while (input == false && invalidInputCounter < 5) {
                    std::cout << "Where is the piece you would like to move (or -1 to return to puzzle selection): ";
                    cin >> columnLetter >> rowNum;
                    if (columnLetter == '-' && rowNum == 1) {
                        return true;
                    }
                    columnNum = columnLetter - 'a';
                    rowNum--;
                    if (columnNum < 0 || columnNum > 7 || rowNum < 0 || rowNum > 7) {
                        std::cout << "Invalid input, please try again\n";
                        invalidInputCounter++;
                        input = false;
                        if (invalidInputCounter == 5) {
                            cout << "Too many invalid inputs, exiting program\n";
                            return false;
                        }
                        continue;
                    } else if (g1.getCurrentBoard().getSquareArray()[(7 - rowNum) * 8 + columnNum].getPiece() == nullptr) {
                        std::cout << "No piece on " << columnLetter << rowNum + 1;
                        std::cout << ", please try again\n";
                        input = false;
                        continue;
                    }
                    input = true;
                }
                boardState++;
                if (!texture.loadFromFile(boardFileNames[boardState])) {
                    std::cout << "Could not load image" << std::endl;
                    return false;
                } else {
                    sprite.setTexture(texture);
                }
                window.clear();
                window.draw(sprite);
                window.display();

                input = false;
                invalidInputCounter = 0;
                while (input == false && invalidInputCounter < 5) {
                    std::cout << "Where would you like to move it to (or -1 to return to puzzle selection): ";
                    cin >> newColumnLetter >> newRowNum;
                    if (newColumnLetter == '-' && newRowNum == 1) {
                        return true;
                    }
                    newColumnNum = newColumnLetter - 'a';
                    newRowNum--;
                    if (newColumnNum < 0 || newColumnNum > 7 || newRowNum < 0 || newRowNum > 7) {
                        std::cout << "Invalid input, please try again\n";
                        invalidInputCounter++;
                        input = false;
                        if (invalidInputCounter == 5) {
                            cout << "Too many invalid inputs, exiting program\n";
                            return false;
                        }
                        continue;
                    }
                    input = true;
                }
                Move newMove = {columnNum,
                                rowNum,
                                newColumnNum,
                                newRowNum};

                while (g1.playTurn(newMove) != 1) {
                    columnLetter = '0';
                    columnNum = 0;
                    rowNum = 0;

                    newColumnLetter = '0';
                    newColumnNum = 0;
                    newRowNum = 0;

                    input = false;
                    invalidInputCounter = 0;

                    while (input == false && invalidInputCounter < 5) {
                        std::cout << "Where is the piece you would like to move (or -1 to return to puzzle selection): ";
                        cin >> columnLetter >> rowNum;
                        if (columnLetter == '-' && rowNum == 1) {
                            return true;
                        }
                        columnNum = columnLetter - 'a';
                        rowNum--;
                        if (columnNum < 0 || columnNum > 7 || rowNum < 0 || rowNum > 7) {
                            std::cout << "Invalid input, please try again\n";
                            invalidInputCounter++;
                            input = false;
                            if (invalidInputCounter == 5) {
                                cout << "Too many invalid inputs, exiting program\n";
                                return false;
                            }
                            continue;
                        } else if (g1.getCurrentBoard().getSquareArray()[(7 - rowNum) * 8 + columnNum].getPiece() == nullptr) {
                            std::cout << "No piece on " << columnLetter << rowNum + 1;
                            std::cout << ", please try again\n";
                            input = false;
                            continue;
                        }
                        input = true;
                    }

                    input = false;
                    invalidInputCounter = 0;

                    while (input == false && invalidInputCounter < 5) {
                        std::cout << "Where would you like to move it to (or -1 to return to puzzle selection): ";
                        cin >> newColumnLetter >> newRowNum;
                        if (newColumnLetter == '-' && newRowNum == 1) {
                            return true;
                        }
                        newColumnNum = newColumnLetter - 'a';
                        newRowNum--;
                        if (newColumnNum < 0 || newColumnNum > 7 || newRowNum < 0 || newRowNum > 7) {
                            std::cout << "Invalid input, please try again\n";
                            invalidInputCounter++;
                            input = false;
                            if (invalidInputCounter == 5) {
                                cout << "Too many invalid inputs, exiting program\n";
                                return false;
                            }
                            continue;
                        }
                        input = true;
                    }

                    newMove = {columnNum,
                               rowNum,
                               newColumnNum,
                               newRowNum};
                }

                boardState++;
                if (!texture.loadFromFile(boardFileNames[boardState])) {
                    std::cout << "Could not load image" << std::endl;
                    return false;
                } else {
                    sprite.setTexture(texture);
                }
                window.clear();
                window.draw(sprite);
                window.display();

                std::cout << "That's the right move, good job!\n";

                input = false;
                invalidInputCounter = 0;

                if (boardMoves.size() > 0) {
                    g1.getCurrentBoard().movePiece(boardMoves[0]);
                    boardMoves.erase(boardMoves.begin());
                    if (g1.getCorrectMovelistLength() == 0) {
                        puzzleSolved = true;
                    }
                }

                boardState++;
                if (!texture.loadFromFile(boardFileNames[boardState])) {
                    std::cout << "Could not load image" << std::endl;
                    return false;
                } else {
                    sprite.setTexture(texture);
                }
                window.clear();
                window.draw(sprite);
                window.display();
            }
            if (puzzleSolved == true) {
                cout << "Well done, you solved the puzzle!\n";
            }

            if (!texture.loadFromFile(boardFileNames[boardState])) {
                std::cout << "Could not load image" << std::endl;
                return false;
            } else {
                sprite.setTexture(texture);
            }
            window.clear();
            window.draw(sprite);
            window.display();

            input = false;
            invalidInputCounter = 0;

            while (input == false && invalidInputCounter < 5) {
                cout << "Would you like to play again (y/n): ";
                char playAgain;
                cin >> playAgain;
                if (playAgain == 'y' || playAgain == 'Y') {
                    input = true;
                    return true;
                } else if (playAgain == 'n' || playAgain == 'N') {
                    input = true;
                    return false;
                } else {
                    cout << "Invalid input, please try again\n";
                    invalidInputCounter++;
                    if (invalidInputCounter == 5) {
                        cout << "Too many invalid inputs, exiting program\n";
                        return false;
                    }
                    continue;
                }
            }
        }
        return false;
    };
} // namespace runGame

#endif // CHESS2_H
