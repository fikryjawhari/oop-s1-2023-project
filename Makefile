main:
	g++ main.cpp Bishop.cpp Board.cpp King.cpp Knight.cpp Pawn.cpp Queen.cpp Rook.cpp Square.cpp Piece.cpp Move.cpp Puzzle.cpp Game.cpp -o output -lsfml-graphics -lsfml-window -lsfml-system
	./output
	clear
square:
	g++ -Wall test.cpp Bishop.cpp Board.cpp King.cpp Knight.cpp Pawn.cpp Queen.cpp Rook.cpp Square.cpp Piece.cpp Move.cpp Puzzle.cpp -o test
	./test
	clear
gameTest:
	g++ -Wall gameTest.cpp Bishop.cpp Board.cpp King.cpp Knight.cpp Pawn.cpp Queen.cpp Rook.cpp Square.cpp Piece.cpp Move.cpp Puzzle.cpp Game.cpp -o game
	./game
windowTest:
	g++ -Wall windowTest.cpp Bishop.cpp Board.cpp King.cpp Knight.cpp Pawn.cpp Queen.cpp Rook.cpp Square.cpp Piece.cpp Move.cpp Window.cpp -o window -lsfml-graphics -lsfml-window -lsfml-system
	./window
	clear