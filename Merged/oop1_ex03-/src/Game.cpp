#include<Game.h>

Game::Game() : window(sf::VideoMode(1360, 900), "Cat & Mouse Game") {

    loadTextures();
    loadMap("Level1.txt");
   
}

void Game::loadTextures() 
{
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

    texture.loadFromFile("empty.png");
    scale = static_cast<float>(TILE_SIZE) / texture.getSize().x;
    texture.setRepeated(true);
    textures.push_back(texture);

    texture.loadFromFile("firstBG.png");
    texture.setRepeated(true);
    textures.push_back(texture);
}

void Game::loadMap(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    std::vector<sf::Sprite> rowSprites;
    int x = 0;
    int y = 0;
    sf::Sprite sprite;
    while (std::getline(file, line))
    {
        rowSprites.clear();

        for (char tile : line)
        {
            if (tile == ' ') {
                sprite.setTexture(textures[7]);
                rowSprites.push_back(emptySprite);
                //sprite.setTexture();
            }
            else
            {

                sprite.setScale(scale, scale); // Apply the scale factor
                switch (tile) {
                case '#': sprite.setTexture(textures[0]); break; // Wall
                case '^': sprite.setTexture(textures[1]); break; // Cat
                case '*': sprite.setTexture(textures[2]); break; // Cheese
                case '$': sprite.setTexture(textures[3]); break; // Gift
                case 'F': sprite.setTexture(textures[4]); break; // Key
                case 'D': sprite.setTexture(textures[5]); break; // Door
                case '%':
                    sprite.setTexture(textures[6]); // Mouse
                    // Set the initial location of the '%' character
                    mouse.setPosition(y, x); // Assuming row and col indices

                    previousCharacterX = mouse.getPosition().col;
                    previousCharacterY = mouse.getPosition().row;
                    break;

                    /* case' ' : sprite.setTexture(textures[8]);*/
                default: continue;
                }

                rowSprites.push_back(sprite);

            }

            x++;
        }

        mapSprites.push_back(rowSprites);
        y++; // Increment the row number after reading each line
        x = 0; // Reset the column number for the next row
    }
}


void Game::run() {
    while (window.isOpen()) {
        processEvents();
       /* update();*/
        render();
        //window.clear();
        //window.display();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::KeyPressed:
            // mouse.setDirection(event.key.code)
            switch (event.key.code) {
            case sf::Keyboard::Up:
                moveCharacter('w'); // Up
                break;
            case sf::Keyboard::Down:
                moveCharacter('s');
                break;
            case sf::Keyboard::Left:
                moveCharacter('a');
                break;
            case sf::Keyboard::Right:
                moveCharacter('d');
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
}


void Game::update(int x , int y , char c ) {
     mouse.setLocation(x, y, c);
}

void Game::render() {
    window.clear();

    sf::Texture backgroundTexture;
    if (backgroundTexture.loadFromFile("firstBG.jpg")) {
        sf::Sprite backgroundSprite(backgroundTexture);
        window.draw(backgroundSprite);
    }
    // Define the size of the map to be displayed
    int mapWidth = mapSprites[0].size();
    int mapHeight = mapSprites.size();

    // Define the position of the top-left corner of the displayed map
    int startX = (window.getSize().x - TILE_SIZE * mapWidth) / 2;
    int startY = (window.getSize().y - TILE_SIZE * mapHeight) / 2;

    // Define the width and height of the displayed portion of the map (half of the window)
    int displayWidth = window.getSize().x / 2;
    int displayHeight = window.getSize().y / 2;

    // Render the portion of the map that fits within half of the window
    for (int y = 0; y < mapHeight && y * TILE_SIZE < displayHeight; ++y) {
        for (int x = 0; x < mapWidth && x * TILE_SIZE < displayWidth; ++x) {
            // Check if the indices are within bounds
            if (y < mapSprites.size() && x < mapSprites[y].size()) {
                mapSprites[y][x].setPosition(startX + x * TILE_SIZE, startY + y * TILE_SIZE);
                mapSprites[y][x].setScale(scale, scale);
                window.draw(mapSprites[y][x]);
            }
        }
    }
    window.display();
}
void Game::moveCharacter(char direction) {
    Location newPos = mouse.calculateNewPosition(mouse.getPosition(), direction);
    if (isValidMove(newPos.row, newPos.col)) {
        // Update the character's position
        //mapSprites[previousCharacterY][previousCharacterX].setTexture(textures[7]); // Assuming textures[0] represents an empty space

        //mapSprites[previousCharacterY][previousCharacterX].setTexture(textures[0]); // Assuming textures[0] represents an empty space
        mouse.setPosition(newPos.row, newPos.col);
        // Update the map after character movement
        updateMap();
    }
    
}


bool Game::isValidMove(int x, int y) {
    // Check if the new position is within bounds of the map and not a wall
    return x >= 0 && x < mapSprites[0].size() && y >= 0 && y < mapSprites.size() &&
        mapSprites[y][x].getTexture() != &textures[0]; // Assuming the first texture represents a wall
}

void Game::updateMap() {
    // Reset the previous character position in the map
    mapSprites[previousCharacterY][previousCharacterX].setTexture(textures[7]); // Assuming textures[7] represents an empty space

    // Set the character texture at its new position in the map
    mapSprites[mouse.getPosition().row][mouse.getPosition().col].setTexture(textures[6]); // Assuming textures[6] represents the character

    // Update the previous character position for the next move
    previousCharacterX = mouse.getPosition().col;
    previousCharacterY = mouse.getPosition().row;
}



