#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include "game_character.h"

class Camera;
class Player;

class Enemy : public Game_character
{
public:
    sf::RectangleShape* getMapRect();

    void draw(sf::RenderWindow* l_window, Game_map* game_map, Player* player, Camera* l_camera);

    Enemy(sf::Vector2f l_coords = sf::Vector2f(0, 0), sf::Vector2f l_size = sf::Vector2f(5, 5), sf::Color l_mapRectColor = sf::Color::Red);
    ~Enemy();
private:
    sf::RectangleShape* m_mapRect;
};

#endif // ENEMY_H_INCLUDED
