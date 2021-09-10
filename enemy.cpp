#include "enemy.h"

sf::RectangleShape* Enemy::getMapRect()
{
    return m_mapRect;
}

void Enemy::draw(sf::RenderWindow* l_window, Game_map* game_map)
{
    m_mapRect->setSize(m_size);
    m_mapRect->setPosition(sf::Vector2f(m_coords.x * game_map->getBlockSize().x - m_size.x / 2,
                                    m_coords.y * game_map->getBlockSize().y - m_size.y / 2));
    l_window->draw(*m_mapRect);
}

Enemy::Enemy(sf::Vector2f l_coords, sf::Vector2f l_size, sf::Color l_mapRectColor):
    Game_character(l_coords, l_size)
{
    m_mapRect = new sf::RectangleShape(l_size);
    m_mapRect->setFillColor(l_mapRectColor);
}

Enemy::~Enemy()
{
    delete m_mapRect;
}
