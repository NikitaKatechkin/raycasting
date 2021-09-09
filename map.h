#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

//#include "tools.h"

#include <SFML/Graphics.hpp>
#include <sstream>
#include <string>
#include <fstream>

class Game_map
{
public:
    char* game_scheme;
    sf::Vector2f m_sizeInTile;
    sf::Vector2f m_blockSize;

    sf::Texture* texture;
    sf::Sprite* sprite;

    sf::Texture* getTexture();
    sf::Sprite* getSprite();

    void draw(sf::RenderWindow *l_window/*, std::vector<uint32_t>* frameBuffer*/);

    void setBlockSize(sf::Vector2f l_size);
    sf::Vector2f getBlockSize();

    Game_map(std::string filePath, sf::Vector2u winSize, std::string texturePath);
    ~Game_map();
};

#endif // MAP_H_INCLUDED
