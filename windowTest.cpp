#include <iostream>
#include <string>

#include "Board.h"
#include "Window.h"

using namespace std;

const char *defaultTheme[12] = {"./images/wp.png",
                                "./images/wr.png",
                                "./images/wn.png",
                                "./images/wb.png",
                                "./images/wk.png",
                                "./images/wq.png",
                                "./images/bp.png",
                                "./images/br.png",
                                "./images/bn.png",
                                "./images/bb.png",
                                "./images/bk.png",
                                "./images/bq.png"};

int main() {
    Window chessWin(800, 800, "chess", defaultTheme);
    while (chessWin.Update()) {
    }
    return 0;
}