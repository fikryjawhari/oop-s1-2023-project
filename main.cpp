// Chess game made by Fikry Aljawhari

#include <SFML/Graphics.hpp>

#define length 7
#define BLACK_PAWN 1
#define WHITE_PAWN -1
#define BLACK_ROOK 2
#define WHITE_ROOK -2
#define BLACK_KNIGHT 3
#define WHITE_KNIGHT -3
#define BLACK_BISHOP 4
#define WHITE_BISHOP -4
#define BLACK_QUEEN 5
#define WHITE_QUEEN -5
#define BLACK_KING 6
#define WHITE_KING -6

using namespace sf;

struct position {
    int x;
    int y;
};

position oldPosition;
position whiteKing;
position blackKing;
position transformWHITE;
position transformBLACK;

int size = 100;
int isMoving;
int board[8][8] = {
    2, 3, 4, 5, 6, 4, 3, 2,
    1, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -1, -1, -1, -1, -1, -1, -1, -1,
    -2, -3, -4, -5, -6, -4, -3, -2};

int rightWhiteRook;
int leftWhiteRook;
int whiteKingFirstMove;

int rightBlackRook;
int leftBlackRook;
int BlackKingFirstMove;

int move; // 0 -> white is moving, 1 -> black is moving

int checkWhite;
int checkBlack;

int transformationWhite;
int transformationBlack;

int main() {
    RenderWindow window(VideoMode(800, 800), "Chess made by Fikry Aljawhari");
    Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15;

    t1.loadFromFile("images/Board.png");
    t2.loadFromFile("images/BlackPawn.png");
    t3.loadFromFile("images/WhitePawn");
    t4.loadFromFile("images/BlackRook");
    t5.loadFromFile("images/WhiteRook");
    t6.loadFromFile("images/BlackKnight");
    t7.loadFromFile("images/WhiteKnight");
    t8.loadFromFile("images/BlackBishop");
    t9.loadFromFile("images/WhiteBishop");
    t10.loadFromFile("images/BlackQueen");
    t11.loadFromFile("images/WhiteQueen");
    t12.loadFromFile("images/BlackKing");
    t13.loadFromFile("images/WhiteKing");
    t14.loadFromFile("images/TransformationBlack");
    t15.loadFromFile("images/TransformationWhite");

    Sprite tabla(t1);
    Sprite BlackPawn(t2);
    Sprite WhitePawn(t3);
    Sprite BlackRook(t4);
    Sprite WhiteRook(t5);
    Sprite BlackKnight(t6);
    Sprite WhiteKnight(t7);
    Sprite BlackBishop(t8);
    Sprite WhiteBishop(t9);
    Sprite BlackQueen(t10);
    Sprite WhiteQueen(t11);
    Sprite BlackKing(t12);
    Sprite WhiteKing(t13);
    Sprite TransformationBlack(t14);
    Sprite TransformationWhite(t15);

    Sprite MoveImages;

    float dx = 0;
    float dy = 0;
    int noMovedPiece = 0;

    while (window.isOpen()) {
        Vector2i position = Mouse::getPosition(window);
        int x = position.x / size;
        int y = position.y / size;
        Event e;
        while (window.pollEvent(e)) {
            if (e.type == Event::Closed) {
                window.close();
            }
            window.clear();
            if (e.key.code == Mouse::Left) {
                // Transformation
                if (board[y][x] != 0) {
                    dx = position.x - x * size;
                    dy = position.y - y * size;
                    if (board[y][x] == BLACK_PAWN && move == 1) {
                        noMovedPiece = BLACK_PAWN;
                        MoveImages = BlackPawn;
                        board[y][x] = 0;
                    }
                    if (board[y][x] == WHITE_PAWN && move == 0) {
                        noMovedPiece = WHITE_PAWN;
                        MoveImages = WhitePawn;
                        board[y][x] = 0;
                    }
                    if (board[y][x] == BLACK_ROOK && move == 0) {
                        noMovedPiece = BLACK_ROOK;
                        MoveImages = BlackRook;
                        board[y][x] = 0;
                    }
                    if (board[y][x] == WHITE_ROOK && move == 0) {
                        noMovedPiece = WHITE_ROOK;
                        MoveImages = WhiteRook;
                        board[y][x] = 0;
                    }
                    if (board[y][x] == BLACK_KNIGHT && move == 0) {
                        noMovedPiece = BLACK_KNIGHT;
                        MoveImages = BlackKnight;
                        board[y][x] = 0;
                    }
                    if (board[y][x] == WHITE_KNIGHT && move == 0) {
                        noMovedPiece = WHITE_KNIGHT;
                        MoveImages = WhiteKnight;
                        board[y][x] = 0;
                    }
                    if (board[y][x] == BLACK_BISHOP && move == 0) {
                        noMovedPiece = BLACK_BISHOP;
                        MoveImages = BlackBishop;
                        board[y][x] = 0;
                    }
                    if (board[y][x] == WHITE_BISHOP && move == 0) {
                        noMovedPiece = WHITE_BISHOP;
                        MoveImages = WhiteBishop;
                        board[y][x] = 0;
                    }
                    if (board[y][x] == BLACK_QUEEN && move == 0) {
                        noMovedPiece = BLACK_QUEEN;
                        MoveImages = BlackQueen;
                        board[y][x] = 0;
                    }
                    if (board[y][x] == WHITE_QUEEN && move == 0) {
                        noMovedPiece = WHITE_QUEEN;
                        MoveImages = WhiteQueen;
                        board[y][x] = 0;
                    }
                    if (board[y][x] == BLACK_KING && move == 0) {
                        noMovedPiece = BLACK_KING;
                        MoveImages = BlackKing;
                        board[y][x] = 0;
                    }
                    if (board[y][x] == WHITE_KING && move == 0) {
                        noMovedPiece = WHITE_KING;
                        MoveImages = WhiteKing;
                        board[y][x] = 0;
                    }
                    if (board[y][x] == 0) {
                        isMoving = 1;
                        oldPosition.x = x;
                        oldPosition.y = y;
                    }
                }
            }
        }
        if (e.type == Event::MouseButtonReleased) {
            if (e.key.code == Mouse::Left) {
                int ok;
                // pieces movement
            }
        }
    }
    return 0;
}

// Ive just realised this shit is 2k lines, fuck that
