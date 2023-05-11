#include "Pawn.h"

bool WhitePawn::validMove(int x_pos, int y_pos) {
    if (colour == "w") {
        if (y_position == 2) {
            if (x_pos == x_position && (y_pos == y_position + 1 || y_pos == y_position + 2)) { // if white pawn hasnt yet moved, can move 1 or 2 squares
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
    } else if (colour == "b") {
        if (y_position == 7) {
            if (x_pos == x_position && (y_pos == y_position - 1 || y_pos == y_position - 2)) { // if black pawn hasnt yet moved, can move 1 or 2 squares
                return true;
            }
        } else if (y_position > 2 && y_position < 7) {            // if on any other square and
            if (y_pos == y_position - 1 && x_pos == x_position) { // normal move
                return true;
            } else if (y_pos == y_position - 1 && (x_pos == x_position + 1 || x_pos == x_position - 1)) { // special move only applicable if diagonal has piece, need to implement that check
                                                                                                          // take piece function
                return true;
            }
        }
    }
    return false;
}
