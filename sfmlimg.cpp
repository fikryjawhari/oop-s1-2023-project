#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    // creates a window that can be used
    sf::RenderWindow window;
    // window parameters are (<size, width, channels>, "name of window", <any styles eg.fullscreen>, <opengl stuff>)
    window.create(sf::VideoMode(771, 770), "window");

    // can also just use window constructor
    // eg. sf::RenderWindow window(sf::VideoMode(771,770),"window");


    // texture is just an image
    sf::Texture texture;
    // sprite is the actual object displayed
    sf::Sprite sprite;

    //error handling
    if (!texture.loadFromFile("sfmlimg.PNG"))
    {
        std::cout << "Could not load image" << std::endl;

        return 1;
    }
    else
    {
        sprite.setTexture(texture);
    }



    // main part of the code (main loop/game loop)
    // runs the program while window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        //always use these three in tandem
        window.clear();  // Clear the window before drawing
        window.draw(sprite);
        window.display();
    }

    return 0;
}   

// when compiling, must link any required libraries using -l
// eg. g++ sfmlimg.cpp -o test -lsfml-graphics -lsfml-window -lsfml-system
// sfml-graphics, sfml-window, sfml-system, sfml-network, sfml-audio
// should only need 1st 3