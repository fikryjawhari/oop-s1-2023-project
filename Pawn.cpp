#include "Pawn.h"

bool Pawn::validMove(int x_pos, int y_pos) {
    if (y_position == 2) {                                                                 // if pawn is on first rank, need to implement seperate colours, white rank 2 black rank 7
        if (x_pos == x_position && (y_pos == y_position + 1 || y_pos == y_position + 2)) { // can move 1 or 2 squares
            return true;
        }
    } else if (y_position > 2 && y_position < 7) {            // if on any other square and
        if (y_pos == y_position + 1 && x_pos == x_position) { // normal move
            return true;
        } else if (y_pos == y_position + 1 && (x_pos == x_position + 1 || x_pos == x_position - 1)) { // special move only applicable if diagonal has piece, need to implement that check
            // take piece function
            return true;
        }
    }
}

string Pawn::movePiece(int x_pos, int y_pos) { // will only run this if both piece validMove and board validMove
    x_position = x_pos;
    y_position = y_pos;
}
