#include "Chess.h"

using namespace Chess; // Clean run() function, can alternatively do Chess::run()

int main() {
    // Since game runs as loop, need to define the end condition, given by run()
    bool gameRunning = true;
    while (gameRunning == true) {
        gameRunning = run();
        std::cout << "Run has ended\n";
    }
    return 0;
}