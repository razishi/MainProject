#include "Menu.h"
#include <iostream>

Menu::Menu(float width, float height)
{
    if (!font.loadFromFile("C:/Windows/Fonts/BRUSHSCI.ttf")) {
        std::cout << "No font is here" << std::endl;
    }

    for (int i = 0; i < Max_main_menu; ++i)
    {
        menu[i].setFont(font);
        menu[i].setFillColor(sf::Color::Black);
        menu[i].setCharacterSize(70);

        switch (i)
        {
        case 0:
            menu[i].setString("Play");
            menu[i].setPosition(575, 200);
            break;
        case 1:
            menu[i].setString("ABOUT");
            menu[i].setPosition(575, 400);
            break;
        case 2:
            menu[i].setString("EXIT");
            menu[i].setPosition(575, 600);
            break;
        }
    }
    MenuSelected = -1;
}

Menu::~Menu()
{
    // Destructor
}

void Menu::draw(sf::RenderWindow& window)
{
    for (size_t i = 0; i < Max_main_menu; ++i)
    {
        window.draw(menu[i]);
    }
}

void Menu::update(sf::Vector2f mousePos)
{
    bool itemSelected = false;
    for (int i = 0; i < Max_main_menu; ++i)
    {
        if (menu[i].getGlobalBounds().contains(mousePos))
        {
            menu[i].setFillColor(sf::Color::Blue);
            MenuSelected = i;
            itemSelected = true;
        }
        else
        {
            menu[i].setFillColor(sf::Color::Black);
        }
    }
    if (!itemSelected)
    {
        MenuSelected = -1;
    }
}

int Menu::MenuPressed() const
{
    return MenuSelected;
}

