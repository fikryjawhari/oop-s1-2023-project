makeMain:
	g++ main.cpp Bishop.cpp Board.cpp King.cpp Knight.cpp Pawn.cpp Queen.cpp Rook.cpp Square.cpp Window.cpp -o output -lsfml-graphics -lsfml-window -lsfml-system
	./output
makeTest:
	g++ test.cpp Board.cpp -o test
	./test