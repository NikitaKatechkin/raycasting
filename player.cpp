#include "player.h"

void Player::setCoords(sf::Vector2f l_coords)
{
    m_coords = l_coords;
}

sf::Vector2f Player::getCoords()
{
    return m_coords;
}

void Player::setView(View l_view)
{
    m_view = l_view;
}

View Player::getView()
{
    return m_view;
}

void Player::setSize(sf::Vector2f l_size)
{
    m_size = l_size;
}

sf::Vector2f Player::getSize()
{
    return m_size;
}

Camera* Player::getCamera()
{
    return m_camera;
}

Player::Player(sf::Vector2f l_coords, View l_view, sf::Vector2f l_size, sf::Vector2f l_camera_pending)
{
    m_coords = l_coords;
    m_view = l_view;
    m_size = l_size;
    m_camera = new Camera(l_camera_pending, view(1.523, PI / 3));
}

Player::~Player()
{

}
