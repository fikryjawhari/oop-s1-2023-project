#include "Window.h"

int main() {
    Window windowTest(640, 640, "Test Window");
    while (windowTest.update()) {
    }
    return 0;
}