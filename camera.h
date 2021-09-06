#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include "tools.h"
#include <SFML/Graphics.hpp>

class Player;
class Game_map;

class Camera
{
public:
    void setPending(sf::Vector2f l_pending);
    sf::Vector2f getPending();

    void setView(View l_view);
    View getView();

    void draw(sf::RenderWindow* l_window, Player* player, Game_map* game_map);

    /*void setSize(sf::Vector2f l_size);
    sf::Vector2f getSize();*/

    Camera(sf::Vector2f l_pending, View l_view/*, sf::Vector2f l_size*/);
    ~Camera();
private:
    sf::Vector2f m_pending;
    View m_view;

    /*sf::Vector2f m_size;*/
};

#endif // CAMERA_H_INCLUDED
