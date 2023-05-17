#include <iostream>
#include <string>

std::string capitalPieceArray[10] = {"BLACK_ROOK", "WHITE_ROOK", "BLACK_KNIGHT", "WHITE_KNIGHT", "BLACK_BISHOP", "WHITE_BISHOP", "BLACK_QUEEN", "WHITE_QUEEN", "BLACK_KING", "WHITE_KING"};
std::string lowerPieceArray[10] = {"BlackRook", "WhiteRook", "BlackKnight", "WhiteKnight", "BlackBishop", "WhiteBishop", "BlackQueen", "WhiteQueen", "BlackKing", "WhiteKing"};

int main() {
    for (int i = 0; i < 10; i++) {
        std::cout << "if (board[y][x] == " << capitalPieceArray[i] << " && move == 0) {\n";
        std::cout << "noMovedPiece = " << capitalPieceArray[i] << ";\n";
        std::cout << "MoveImages = " << lowerPieceArray[i] << ";\n";
        std::cout << "board[y][x] = 0;\n} ";
    }
    return 0;
}
