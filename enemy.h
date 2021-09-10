#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include "game_character.h"

class Enemy : public Game_character
{
public:
    Enemy(sf::Vector2f l_coords = sf::Vector2f(0, 0), sf::Vector2f l_size = sf::Vector2f(5, 5));
    ~Enemy();
private:
};

#endif // ENEMY_H_INCLUDED
