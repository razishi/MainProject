#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <fstream>

class Game {
public:
    Game();
    void run();

private:
    sf::RenderWindow window;
    std::vector<std::vector<sf::Sprite>> mapSprites;
    std::vector<sf::Texture> textures;
    const int TILE_SIZE = 32; // Adjust based on your texture size
    float scale;
    void loadTextures();
    void loadMap(const std::string& filename);
    void processEvents();
    void update();
    void render();
};
