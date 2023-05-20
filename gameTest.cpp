#include "Game.h"
#include <iostream>

using namespace std;

int main() {
    Game g1(-1, "a", *(new Puzzle));
    vector<Move> boardMoves = g1.getBoardMoves();
    while (g1.getCorrectMovelistLength() > 0) {
        g1.getCurrentBoard().printBoard(); // this just prints board, purely for testing
        char columnLetter = '0';
        int columnNum = 0;
        int rowNum = 0;

        char newColumnLetter = '0';
        int newColumnNum = 0;
        int newRowNum = 0;

        bool input = false;

        while (input == false) {
            std::cout << "Where is the piece you would like to move: ";
            cin >> columnLetter >> rowNum;
            columnNum = columnLetter - 'a';
            rowNum--;
            if (columnNum < 0 || columnNum > 7 || rowNum < 0 || rowNum > 7) {
                std::cout << "Invalid input, please try again\n";
                input = false;
                continue;
            }
            input = true;
        }
        input = false;
        while (input == false) {
            std::cout << "Where would you like to move it to: ";
            cin >> newColumnLetter >> newRowNum;

            newColumnNum = newColumnLetter - 'a';
            newRowNum--;
            if (newColumnNum < 0 || newColumnNum > 7 || newRowNum < 0 || newRowNum > 7) {
                std::cout << "Invalid input, please try again\n";
                input = false;
                continue;
            }
            input = true;
        }
        Move newMove = {columnNum,
                        rowNum,
                        newColumnNum,
                        newRowNum};

        while (g1.playTurn(newMove) != 1) {
            bool input = false;

            columnLetter = '0';
            columnNum = 0;
            rowNum = 0;

            newColumnLetter = '0';
            newColumnNum = 0;
            newRowNum = 0;

            while (input == false) {
                std::cout << "Where is the piece you would like to move: ";
                cin >> columnLetter >> rowNum;
                columnNum = columnLetter - 'a';
                rowNum--;
                if (columnNum < 0 || columnNum > 7 || rowNum < 0 || rowNum > 7) {
                    std::cout << "Invalid input, please try again\n";
                    input = false;
                    continue;
                }
                input = true;
            }
            input = false;
            while (input == false) {
                std::cout << "Where would you like to move it to: ";
                cin >> newColumnLetter >> newRowNum;

                newColumnNum = newColumnLetter - 'a';
                newRowNum--;
                if (newColumnNum < 0 || newColumnNum > 7 || newRowNum < 0 || newRowNum > 7) {
                    std::cout << "Invalid input, please try again\n";
                    input = false;
                    continue;
                }
                input = true;
            }

            newMove = {columnNum,
                       rowNum,
                       newColumnNum,
                       newRowNum};
        }

        std::cout << "That is the right move, good job!\n";
        if (boardMoves.size() > 0) {
            g1.getCurrentBoard().movePiece(boardMoves[0]);
            boardMoves.erase(boardMoves.begin());
        }
    }

    cout << "Well done, you solved the puzzle!\n";

    g1.getCurrentBoard().printBoard();

    return 0;
}