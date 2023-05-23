#include "Window.h"
#include "Chess.h"

const char *defaultTheme[12] = {"images/wp.png",
                                "images/wr.png",
                                "images/wn.png",
                                "images/wb.png",
                                "images/wk.png",
                                "images/wq.png",
                                "images/bp.png",
                                "images/br.png",
                                "images/bn.png",
                                "images/bb.png",
                                "images/bk.png",
                                "images/bq.png"};

int main() {
    Window windowTest(640, 640, "Test Window", defaultTheme, Chess::runWindow());
    while (windowTest.update()) {
    }
    return 0;
}