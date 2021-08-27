#include "player.h"

void Player::setCoords(Coordinate l_coords)
{
    m_coords = l_coords;
}

Coordinate Player::getCoords()
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

void Player::setSize(Phys_size l_size)
{
    m_size = l_size;
}

Phys_size Player::getSize()
{
    return m_size;
}

Player::Player(Coordinate l_coords, View l_view, Phys_size l_size)
{
    m_coords = l_coords;
    m_view = l_view;
    m_size = l_size;
}

Player::~Player()
{

}
