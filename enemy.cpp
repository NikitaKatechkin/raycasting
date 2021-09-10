#include "enemy.h"
#define PI 3.1415

void Enemy::setCoords(sf::Vector2f l_coords)
{
    m_coords = l_coords;
}

sf::Vector2f Enemy::getCoords()
{
    return m_coords;
}

void Enemy::setSize(sf::Vector2f l_size)
{
    m_size = l_size;
}

sf::Vector2f Enemy::getSize()
{
    return m_size;
}

Camera* Enemy::getCamera()
{
    return m_camera;
}

void Enemy::MoveForward(Game_map* game_map, float l_delta)
{
    this->Move(l_delta, game_map);
}

void Enemy::MoveBackward(Game_map* game_map, float l_delta)
{
    this->Move(l_delta, game_map);
}

void Enemy::Move(float l_delta, Game_map* game_map)
{
    float predict_x = this->getCoords().x + l_delta * cos(m_camera->getView().angle);
    float predict_y = this->getCoords().y + l_delta * sin(m_camera->getView().angle);

    if (game_map->game_scheme[int(predict_x)+ int(predict_y)*int(game_map->m_sizeInTile.x)] != ' ') { return; }

    this->setCoords(sf::Vector2f(predict_x, predict_y));
}

Enemy::Enemy(sf::Vector2f l_coords, sf::Vector2f l_size, sf::Vector2f l_camera_pending)
{
    m_coords = l_coords;
    m_size = l_size;
    m_camera = new Camera(l_camera_pending, view(1.5708f, PI / 3));
}

Enemy::~Enemy()
{
    delete m_camera;
}
