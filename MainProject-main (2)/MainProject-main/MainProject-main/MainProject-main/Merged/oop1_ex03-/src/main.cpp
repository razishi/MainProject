#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Game.h"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1300, 800), "Tom&Jerry", sf::Style::Close | sf::Style::Titlebar);

    Menu menu(window.getSize().x, window.getSize().y);

    sf::RectangleShape Pbackground;
    Pbackground.setSize(sf::Vector2f(1300, 800));
    sf::Texture back_texture;
    back_texture.loadFromFile("background.png");
    Pbackground.setTexture(&back_texture);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    int selectedMenu = menu.MenuPressed();
                    if (selectedMenu != -1) {
                        switch (selectedMenu)
                        {
                        case 0:
                        {
                            window.close();
                            Game game;
                            game.run();
                            break;
                        }
                        case 1:
                        {
                            sf::RenderWindow ABOUT(sf::VideoMode(960, 720), "ABOUT");
                            while (ABOUT.isOpen())
                            {
                                window.clear();
                                window.close();
                                sf::Event aevent;
                                while (ABOUT.pollEvent(aevent))
                                {
                                    if (aevent.type == sf::Event::Closed)
                                    {
                                        ABOUT.close();
                                    }
                                    if (aevent.type == sf::Event::KeyPressed)
                                    {
                                        if (aevent.key.code == sf::Keyboard::Escape)
                                        {
                                            ABOUT.close();
                                        }
                                    }
                                }
                                ABOUT.clear();
                                ABOUT.display();
                            }
                            break;
                        }
                        case 2:
                            window.close();
                            break;
                        }
                    }
                }
            }
        }
        sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
        menu.update(mousePos);

        window.clear();
        window.draw(Pbackground);
       menu.draw(window);
        window.display();
    }

    return 0;
}

