#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window;
    window.create(sf::VideoMode(771, 770), "window");

    sf::Texture texture;
    sf::Sprite sprite;

    if (!texture.loadFromFile("sfmlimg.PNG"))
    {
        std::cout << "Could not load image" << std::endl;

        return 1;
    }
    else
    {
        sprite.setTexture(texture);
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            }
        }

        window.clear();  // Clear the window before drawing
        window.draw(sprite);
        window.display();
    }

    return 0;
}