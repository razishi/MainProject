/*
Notebook changes : 
- 4 pics for the mouse. Done
- logical stuff ( end cheese = end game () ) , ( must have key to eat door ())
*/

#include<Game.h>

Game::Game() : window(sf::VideoMode(1360, 900), "Tom&Jerry") {
    loadTextures();
    loadMap("Level1.txt");
}


void Game::loadTextures() 
{
    // Load textures for wall, mouse, gift, cheese, key, door
    // Add each texture to the 'textures' vector in the same order as your symbols
    sf::Texture texture;
    texture.loadFromFile("wall.png");
    textures.push_back(texture);

    texture.loadFromFile("cat.png");
    textures.push_back(texture);

    texture.loadFromFile("cheese.png");
    textures.push_back(texture);

    texture.loadFromFile("gift.png");
    textures.push_back(texture); 

    texture.loadFromFile("key.png");
    textures.push_back(texture);

    texture.loadFromFile("door.png");
    textures.push_back(texture);

    texture.loadFromFile("mouse1.png");
    textures.push_back(texture);

    texture.loadFromFile("mouse2.png");
    textures.push_back(texture);

    texture.loadFromFile("mouse3.png");
    textures.push_back(texture);

    texture.loadFromFile("mouse4.png");
    textures.push_back(texture);

    texture.loadFromFile("empty.png");
    textures.push_back(texture);

    texture.loadFromFile("firstBG.png");
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
                    mouse.setLocation(x, y);// Assuming row and col indices
                    // Assuming row and col indices

                    previousCharacterX = mouse.getPosition().row;
                    previousCharacterY = mouse.getPosition().col;
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
        
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::KeyPressed:
            switch (event.key.code) {
            case sf::Keyboard::Up:
                moveCharacter(direction::UP); // Up

                break;
            case sf::Keyboard::Down:
                moveCharacter(direction::DOWN);
                break;
            case sf::Keyboard::Left:
                moveCharacter(direction::LEFT);
                break;
            case sf::Keyboard::Right:
                moveCharacter(direction::RIGHT);
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
    int startX = (window.getSize().x - 32 * mapWidth) / 2;
    int startY = (window.getSize().y - 32 * mapHeight) / 2;

    // Define the width and height of the displayed portion of the map (half of the window)
    int displayWidth = window.getSize().x / 2;
    int displayHeight = window.getSize().y / 2;

    // Render the portion of the map that fits within half of the window
    for (int y = 0; y < mapHeight && y * 32 < displayHeight; ++y) {
        for (int x = 0; x < mapWidth && x * 32 < displayWidth; ++x) {
            // Check if the indices are within bounds
            if (y < mapSprites.size() && x < mapSprites[y].size()) {
                mapSprites[y][x].setPosition(startX + x * 32, startY + y * 32);
                mapSprites[y][x].setScale(scale, scale);
                window.draw(mapSprites[y][x]);
            }
        }
    }
    window.display();
}
void Game::moveCharacter(direction C) {
    Location newPos = mouse.calculateNewPosition(mouse.getPosition(), C );
    if (isValidMove(newPos.row, newPos.col)) {
        // Update the character's position
        mouse.setLocation(newPos.row, newPos.col);
        // Update the map after character movement
        updateMap(C);
    }
}



bool Game::isValidMove(int x, int y) {
    // Check if the new position is within bounds of the map and not a wall
    return x >= 0 && x < mapSprites[y].size() && y >= 0 && y < mapSprites.size() &&
        mapSprites[y][x].getTexture() != &textures[0] ; // Assuming the first texture represents a wall
}

void Game::updateMap(direction C) {
    // Reset the previous character position in the map
    mapSprites[previousCharacterY][previousCharacterX].setTexture(textures[10]); // Assuming textures[7] represents an empty space

    switch (C) {
    case UP:    mapSprites[mouse.getPosition().col][mouse.getPosition().row].setTexture(textures[9]);; break;
    case DOWN:  mapSprites[mouse.getPosition().col][mouse.getPosition().row].setTexture(textures[6]);; break;
    case LEFT:  mapSprites[mouse.getPosition().col][mouse.getPosition().row].setTexture(textures[7]);; break;
    case RIGHT: mapSprites[mouse.getPosition().col][mouse.getPosition().row].setTexture(textures[8]);; break;
    }
    // Set the character texture at its new position in the map
    //mapSprites[mouse.getPosition().col][mouse.getPosition().row].setTexture(textures[6]); // Assuming textures[6] represents the character

    // Update the previous character position for the next move
    previousCharacterX = mouse.getPosition().row;
    previousCharacterY = mouse.getPosition().col;
}



