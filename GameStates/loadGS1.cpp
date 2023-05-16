#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

int main() {
    sf::RenderWindow Chess(sf::VideoMode(800, 800), "Chess Puzzles");

    sf::Texture texMenu;
    sf::Texture texGS1;
    sf::Texture texGS2;

    sf::Sprite spMenu;
    sf::Sprite spGS1;
    sf::Sprite spGS2;

    if (!texMenu.loadFromFile("Menu.png")) {
        std::cout << "Could not load image" << std::endl;

        return 1;
    } else {
        spMenu.setTexture(texMenu);
    }

    if (!texGS1.loadFromFile("GS1.PNG")) {
        std::cout << "Could not load image" << std::endl;

        return 1;
    } else {
        spGS1.setTexture(texGS1);
    }

    if (!texGS2.loadFromFile("GS2.PNG")) {
        std::cout << "Could not load image" << std::endl;

        return 1;
    } else {
        spGS2.setTexture(texGS2);
    }
    Chess.clear();
    Chess.draw(spMenu);
    Chess.display();

    while (Chess.isOpen()) {

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (Chess.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                Chess.close();
            }

            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode == 98) {
                    Chess.clear();
                    Chess.draw(spGS1);
                    Chess.display();
                } else if (event.text.unicode == 97) {
                    Chess.clear();
                    Chess.draw(spGS2);
                    Chess.display();
                }
            }
        }
    }

    return 0;
}
