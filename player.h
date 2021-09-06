#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "tools.h"
#include <SFML/Graphics.hpp>
#include "camera.h"

#define PI 3.14159

class Player
{
public:
    void setCoords(sf::Vector2f l_coords);
    sf::Vector2f getCoords();

    void setView(View l_view);
    View getView();

    void setSize(sf::Vector2f l_size);
    sf::Vector2f getSize();

    Camera* m_camera;

    Camera* getCamera();

    Player(sf::Vector2f l_coords, View l_view, sf::Vector2f l_size, sf::Vector2f l_camera_pending = sf::Vector2f(0, 0));
    ~Player();
private:
    sf::Vector2f m_coords;
    View m_view;

    sf::Vector2f m_size;
};

#endif // PLAYER_H_INCLUDED
