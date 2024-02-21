#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>

#define Max_main_menu 3

class Menu
{
public:
    Menu(float width, float height);
    ~Menu();

    void draw(sf::RenderWindow& window);
    void update(sf::Vector2f mousePos);
    int MenuPressed() const;

private:
    int MenuSelected;
    sf::Font font;
    sf::Text menu[Max_main_menu];
};

#endif // MENU_H
