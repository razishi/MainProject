#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <fstream>
#include <Mouse.h>
#include "Location.h" // Assuming Location is a class or struct to represent coordinates



class Game {
public:
    Game();
    /*Location calculateNewPosition(const Location& currentPos, char direction);*/
    void moveCharacter(char direction);

    void run();

private:
    sf::RenderWindow window;
    sf::Sprite emptySprite;
    std::vector<std::vector<sf::Sprite>> mapSprites;
    std::vector<sf::Texture> textures;
    const int TILE_SIZE = 32; // Adjust based on your texture size
    float scale;
    void loadTextures();
    void loadMap(const std::string& filename);
    void processEvents();
    void update(int x, int y, char c);
     void render();
    bool isValidMove(int x, int y);
    void updateMap();
    void moveCharacter(int dx, int dy);
    int characterX = 0, characterY = 0;
    //sf::Sprite emptySprite;

    Mouse mouse;
    int previousCharacterY = 0;
    int previousCharacterX = 0;

};
