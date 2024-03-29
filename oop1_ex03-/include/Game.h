#pragma once
#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <fstream>
#include <Mouse.h>
#include "Location.h" // Assuming Location is a class or struct to represent coordinates
#include "Entity.h"


class Game {
public:
    Game();
    /*Location calculateNewPosition(const Location& currentPos, char direction);*/
    void moveCharacter(direction C);


    void run();

private:
    sf::Sprite sprite;
    sf::RenderWindow window;
    sf::Sprite emptySprite;
    std::vector<std::vector<sf::Sprite>> mapSprites;
    std::vector<sf::Texture> textures;
    const float scale = 0.5; // Adjust based on your texture size
    void loadTextures();
    void loadMap(const std::string& filename);
    void processEvents();
     void render();
    bool isValidMove(int x, int y);
    bool gotKey = false;
    void updateMap(direction C);
    //void moveCharacter(int dx, int dy);
    int characterX = 0, characterY = 0;
    //sf::Sprite emptySprite;

    Mouse mouse;
    int m_row;
    int m_col;
    int previousCharacterY = 0;
    int previousCharacterX = 0;

    void updateItems(int x ,int y );
    // logics suction
    // Doors & Keys  
    int key;
    bool keylogic(int x, int y);
     ///Cheese
   int CountCheese;
   Location newPos;
   bool Cathed;
};

#endif // GAME_H
