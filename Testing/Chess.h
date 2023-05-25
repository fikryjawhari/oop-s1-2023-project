#ifndef CHESS_H
#define CHESS_H

#include "Game.h"
#include "thread"

using namespace std;

namespace Chess {
    bool run() {

        // Setting variables
        string puzzle = "";
        bool input = false;
        bool puzzleSolved = false;
        int invalidInputCounter = 0;
        int boardState = 0;

        // Initial message
        cout << "Welcome to OOP Chess Puzzles, your one stop chess puzzle solving experience!\n";

        // Taking user input for which puzzle they want. Additionally, if the user does 5 invalid inputs in a row, the program
        // will forcibly end, to prevent infinite looping
        while (input == false && invalidInputCounter < 5) {
            cout << "Please enter the puzzle you want to work on, from a - e (lowercase only, or -1 to exit): ";
            cin >> puzzle;
            // if -1 is inputted, exit program
            if (puzzle.compare("-1") == 0) {
                return 0;
                // if letter they entered is one of the ones specificed, can exit loop
            } else if (puzzle.compare("a") == 0 || puzzle.compare("b") == 0 || puzzle.compare("c") == 0 || puzzle.compare("d") == 0 || puzzle.compare("e") == 0) {
                input = true;
            } else { // if letter they entered is not one of the ones specified, retake input
                cout << "That's not a valid puzzle, please try again\n";
                input = false;
                invalidInputCounter++;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear buffer before taking new
                if (invalidInputCounter == 5) {
                    return false;
                }
            }
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear buffer before taking new
        // Make a game based on the puzzle we just selected
        Game g1(puzzle);
        // Get required vectors
        vector<Move> boardMoves = g1.getBoardMoves();
        vector<string> boardFileNames = g1.getBoardStates();
        // Start thread that displays board.
        // This thread takes the adress of the class function, instantiated object, and any function parameters
        thread gameWindow(&Game::showBoard, &g1, &boardState);

        // Since move list gets cut after every right move, we check to see if its empty or not
        while (g1.getCorrectMovelistLength() > 0) {
            char columnLetter = '0';
            int columnNum = 0;
            int rowNum = 0;

            char newColumnLetter = '0';
            int newColumnNum = 0;
            int newRowNum = 0;

            // Resetting input flags
            input = false;
            invalidInputCounter = 0;
            // Taking user input on which piece they want to move
            while (input == false && invalidInputCounter < 5) {
                std::cout << "Where is the piece you would like to move (or -1 to return to puzzle selection): ";
                cin >> columnLetter >> rowNum;
                if (columnLetter == '-' && rowNum == 1) {
                    cout << "Please close the window to continue\n";
                    gameWindow.join();
                    return true;
                }
                columnNum = columnLetter - 'a';
                rowNum--;
                if (columnNum < 0 || columnNum > 7 || rowNum < 0 || rowNum > 7) {
                    std::cout << "Invalid input, please try again\n";
                    invalidInputCounter++;
                    input = false;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear buffer before taking new
                    if (invalidInputCounter == 5) {
                        cout << "Too many invalid inputs, exiting program\n";
                        cout << "Please close the window to continue\n";
                        gameWindow.join();
                        return false;
                    }
                    continue;
                } else if (g1.getCurrentBoard().getSquareArray()[(7 - rowNum) * 8 + columnNum].getPiece() == nullptr) {
                    std::cout << "No piece on " << columnLetter << rowNum + 1;
                    std::cout << ", please try again\n";
                    input = false;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear buffer before taking new
                    continue;
                }
                input = true;
            }
            // Resetting input flags
            input = false;
            invalidInputCounter = 0;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear buffer before taking new
            // Asking where they want to move the piece to
            while (input == false && invalidInputCounter < 5) {
                std::cout << "Where would you like to move it to (or -1 to return to puzzle selection): ";
                cin >> newColumnLetter >> newRowNum;
                if (newColumnLetter == '-' && newRowNum == 1) {
                    cout << "Please close the window to continue\n";
                    gameWindow.join();
                    return true;
                }
                newColumnNum = newColumnLetter - 'a';
                newRowNum--;
                if (newColumnNum < 0 || newColumnNum > 7 || newRowNum < 0 || newRowNum > 7) {
                    std::cout << "Invalid input, please try again\n";
                    invalidInputCounter++;
                    input = false;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear buffer before taking new
                    if (invalidInputCounter == 5) {
                        cout << "Too many invalid inputs, exiting program\n";
                        cout << "Please close the window to continue\n";
                        gameWindow.join();
                        return 0;
                    }
                    continue;
                }
                input = true;
            }
            // Assigning move based on the user input provided
            Move newMove = {columnNum,
                            rowNum,
                            newColumnNum,
                            newRowNum};
            // play turn returns 1 if the move is actually played, as in it passes the three checks for the piece valid move,
            // board valid move, and that the player does not put themself in check by doing that move
            while (g1.playTurn(newMove) != 1) {
                // Resetting variables
                input = false;
                invalidInputCounter = 0;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear buffer before taking new
                // Retaking input
                while (input == false && invalidInputCounter < 5) {
                    std::cout << "Where is the piece you would like to move (or -1 to return to puzzle selection): ";
                    cin >> columnLetter >> rowNum;
                    if (columnLetter == '-' && rowNum == 1) {
                        cout << "Please close the window to continue\n";
                        gameWindow.join();
                        return true;
                    }
                    columnNum = columnLetter - 'a';
                    rowNum--;
                    if (columnNum < 0 || columnNum > 7 || rowNum < 0 || rowNum > 7) {
                        std::cout << "Invalid input, please try again\n";
                        invalidInputCounter++;
                        input = false;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear buffer before taking new
                        if (invalidInputCounter == 5) {
                            cout << "Too many invalid inputs, exiting program\n";
                            cout << "Please close the window to continue\n";
                            gameWindow.join();
                            return false;
                        }
                        continue;
                    } else if (g1.getCurrentBoard().getSquareArray()[(7 - rowNum) * 8 + columnNum].getPiece() == nullptr) {
                        std::cout << "No piece on " << columnLetter << rowNum + 1;
                        std::cout << ", please try again\n";
                        input = false;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear buffer before taking new
                        continue;
                    }
                    input = true;
                }
                // Resetting input flags
                input = false;
                invalidInputCounter = 0;

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear buffer before taking new
                // Asking where they want to move the piece to
                while (input == false && invalidInputCounter < 5) {
                    std::cout << "Where would you like to move it to (or -1 to return to puzzle selection): ";
                    cin >> newColumnLetter >> newRowNum;
                    if (newColumnLetter == '-' && newRowNum == 1) {
                        cout << "Please close the window to continue\n";
                        gameWindow.join();
                        return true;
                    }
                    newColumnNum = newColumnLetter - 'a';
                    newRowNum--;
                    if (newColumnNum < 0 || newColumnNum > 7 || newRowNum < 0 || newRowNum > 7) {
                        std::cout << "Invalid input, please try again\n";
                        invalidInputCounter++;
                        input = false;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear buffer before taking new
                        if (invalidInputCounter == 5) {
                            cout << "Too many invalid inputs, exiting program\n";
                            cout << "Please close the window to continue\n";
                            gameWindow.join();
                            return 0;
                        }
                        continue;
                    }
                    input = true;
                }
                // Reassigning move based on new inputs, and checking playTurn again
                newMove = {columnNum,
                           rowNum,
                           newColumnNum,
                           newRowNum};
            }
            // if while loop is finished, that means that the move is correct, so the board state is incremented to load the
            // next image
            boardState++;

            std::cout << "That's the right move, good job!\n";

            input = false;
            invalidInputCounter = 0;

            // this function actually moves the pieces and deletes the relevant element of the boardMoves vector
            if (boardMoves.size() > 0) {
                g1.getCurrentBoard().movePiece(boardMoves[0]);
                boardMoves.erase(boardMoves.begin());
                boardState++;
            }
        }
        // if puzzle was solved, display nice message and wait for graphic window to close
        cout << "Well done, you solved the puzzle!\n";
        cout << "Please close the window to continue\n";
        gameWindow.join();
        // Reset input flags
        input = false;
        invalidInputCounter = 0;
        char playAgain = '0';
        // ask if user wants to play again
        while (input == false && invalidInputCounter < 5) {
            cout << "Would you like to play again (y/n): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear buffer before taking new
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
                input = false;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear buffer before taking new
                if (invalidInputCounter == 5) {
                    cout << "Too many invalid inputs, exiting program\n";
                    return false;
                }
                continue;
            }
        }
        return 0;
    }
}; // namespace runGame

#endif // CHESS_H