#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include "map.h"
#include <SFML/Graphics.hpp>
#include "camera.h"

class Enemy
{
public:
    void setCoords(sf::Vector2f l_coords);
    sf::Vector2f getCoords();

    void setSize(sf::Vector2f l_size);
    sf::Vector2f getSize();

    void MoveForward(Game_map* game_map, float l_delta = 0.1f);
    void MoveBackward(Game_map* game_map, float l_delta = -0.1f);

    Camera* getCamera();

    Enemy(sf::Vector2f l_coords = sf::Vector2f(0, 0), sf::Vector2f l_size = sf::Vector2f(5, 5), sf::Vector2f l_camera_pending = sf::Vector2f(0, 0));
    ~Enemy();
private:
    void Move(float l_delta, Game_map* game_map);

    sf::Vector2f m_coords;
    sf::Vector2f m_size;

    Camera* m_camera;
};

#endif // ENEMY_H_INCLUDED
