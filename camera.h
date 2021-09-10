#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include "tools.h"
#include <SFML/Graphics.hpp>

class Player;
class Game_map;
class Enemy;

class Camera
{
public:
    void setPending(sf::Vector2f l_pending);
    sf::Vector2f getPending();

    void setView(View l_view);
    View getView();

    void leftRotate(float delta = -0.1f);
    void rightRotate(float delta = 0.1f);

    void draw(sf::RenderWindow* l_window, Player* player, Game_map* game_map);
    void drawObjects(sf::RenderWindow* l_window, Player* player, Game_map* game_map, Enemy* enemys);

    Camera(sf::Vector2f l_pending, View l_view);
    ~Camera();
private:
    void Rotate(float l_delta);

    sf::Vector2f m_pending;
    View m_view;
};

#endif // CAMERA_H_INCLUDED
