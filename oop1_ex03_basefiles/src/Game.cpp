#include<Game.h>

Game::Game() : window(sf::VideoMode(800, 600), "Cat & Mouse Game") {
    loadTextures();
    loadMap("Level1.txt");
}

void Game::loadTextures() {
    // Load textures for wall, mouse, gift, cheese, key, door
    // Add each texture to the 'textures' vector in the same order as your symbols
    sf::Texture texture;
    texture.loadFromFile("wall.png");
    scale = static_cast<float>(TILE_SIZE) / texture.getSize().x;
    texture.setRepeated(true);
    textures.push_back(texture);

    texture.loadFromFile("cat.png");
     scale = static_cast<float>(TILE_SIZE) / texture.getSize().x;
    texture.setRepeated(true);
    textures.push_back(texture);

    texture.loadFromFile("cheese.png");
    scale = static_cast<float>(TILE_SIZE) / texture.getSize().x;
    texture.setRepeated(true);
    textures.push_back(texture);

    texture.loadFromFile("gift.png");
    scale = static_cast<float>(TILE_SIZE) / texture.getSize().x;
    texture.setRepeated(true);
    textures.push_back(texture);

    texture.loadFromFile("key.png");
    scale = static_cast<float>(TILE_SIZE) / texture.getSize().x;
    texture.setRepeated(true);
    textures.push_back(texture);

    texture.loadFromFile("door.png");
    scale = static_cast<float>(TILE_SIZE) / texture.getSize().x;
    texture.setRepeated(true);
    textures.push_back(texture);

    texture.loadFromFile("mouse.png");
    scale = static_cast<float>(TILE_SIZE) / texture.getSize().x;
    texture.setRepeated(true);
    textures.push_back(texture);
}

void Game::loadMap(const std::string& filename) {

    std::ifstream file(filename);
    std::string line;
    std::vector<sf::Sprite> rowSprites;

    while (std::getline(file, line)) {

        rowSprites.clear();

        for (char tile : line) {

            sf::Sprite sprite;

            switch (tile) {
            case '#': sprite.setTexture(textures[0]); break; // Wall
            case '^': sprite.setTexture(textures[1]); break; // Cat
            case '*': sprite.setTexture(textures[2]); break; // Cheese
            case '$': sprite.setTexture(textures[3]); break; // Gift
            case 'F': sprite.setTexture(textures[4]); break; // Key
            case 'D': sprite.setTexture(textures[5]); break; // Door
            case '%': sprite.setTexture(textures[6]); break; // Mouse
            default: continue;
            }
            sprite.setScale(scale, scale); // Apply the scale factor
            rowSprites.push_back(sprite);
        }
        mapSprites.push_back(rowSprites);
    }
}
void Game::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void Game::update() {
    // Update game state 
}

void Game::render() {
    window.clear();
    for (int y = 0; y < mapSprites.size(); ++y) {
        for (int x = 0; x < mapSprites[y].size(); ++x) {
            mapSprites[y][x].setPosition(x * TILE_SIZE, y * TILE_SIZE);
            window.draw(mapSprites[y][x]);
        }
    }
    window.display();
}
