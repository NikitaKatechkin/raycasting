#ifndef GAME_CHARACTER_H_INCLUDED
#define GAME_CHARACTER_H_INCLUDED

#include "map.h"
#include <SFML/Graphics.hpp>

class Game_character
{
public:
    void setCoords(sf::Vector2f l_coords);
    sf::Vector2f getCoords();

    void setSize(sf::Vector2f l_size);
    sf::Vector2f getSize();

    void draw(sf::RenderWindow* l_window, Game_map* game_map);

    Game_character(sf::Vector2f l_coords, sf::Vector2f l_size);
    ~Game_character();
protected:
    sf::Vector2f m_coords;
    sf::Vector2f m_size;
};

#endif // GAME_CHARACTER_H_INCLUDED
