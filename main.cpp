#include "Chess.h"

using namespace Chess;

int main() {
    bool gameRunning = true;
    while (gameRunning == true) {
        gameRunning = run();
    }
    return 0;
}