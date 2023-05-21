#include "Chess.h"

using namespace Chess;

void function(int x)
{
    std::cout << x << "yay" << std::endl;
};
 
int main() {
    bool gameRunning = true;
    while (gameRunning == true) {
        gameRunning = run();
    }
    return 0;
}