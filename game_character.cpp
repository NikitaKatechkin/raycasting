#include "game_character.h"

void Game_character::setCoords(sf::Vector2f l_coords)
{
    m_coords = l_coords;
}

sf::Vector2f Game_character::getCoords()
{
    return m_coords;
}

void Game_character::setSize(sf::Vector2f l_size)
{
    m_size = l_size;
}

sf::Vector2f Game_character::getSize()
{
    return m_size;
}

void Game_character::draw(sf::RenderWindow* l_window, Game_map* game_map)
{
    sf::RectangleShape square(m_size);
    square.setFillColor(sf::Color::Red);
    square.setPosition(sf::Vector2f(m_coords.x * game_map->getBlockSize().x - m_size.x / 2,
                                    m_coords.y * game_map->getBlockSize().y - m_size.y / 2));
    l_window->draw(square);
}

Game_character::Game_character(sf::Vector2f l_coords, sf::Vector2f l_size)
{
    m_coords = l_coords;
    m_size = l_size;
}

Game_character::~Game_character()
{

}
