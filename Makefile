makeMain:
	g++ main.cpp Bishop.cpp Board.cpp King.cpp Knight.cpp Pawn.cpp Queen.cpp Rook.cpp Square.cpp Window.cpp -o output -lsfml-graphics -lsfml-window -lsfml-system
	./output
makeSquare:
	g++ -Wall test.cpp Bishop.cpp Board.cpp King.cpp Knight.cpp Pawn.cpp Queen.cpp Rook.cpp Square.cpp Piece.cpp Move.cpp Puzzle.cpp -o test
	./test
makeGame:
	g++ -Wall gameTest.cpp Bishop.cpp Board.cpp King.cpp Knight.cpp Pawn.cpp Queen.cpp Rook.cpp Square.cpp Piece.cpp Move.cpp Puzzle.cpp Game.cpp -o game
	./game