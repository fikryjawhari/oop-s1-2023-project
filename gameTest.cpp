#include "Chess.h"

using namespace std;

int main() {
    bool gameRunning = true;
    while (gameRunning == true) {
        gameRunning = Chess::run();
    }
    return 0;
}