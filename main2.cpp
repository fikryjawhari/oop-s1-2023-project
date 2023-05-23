#include "Chess2.h"

using namespace Chess2;

int main() {
    bool gameRunning = true;
    while (gameRunning == true) {
        gameRunning = run();
    }
    return 0;
}