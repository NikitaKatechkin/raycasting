#include "player.h"

Camera* Player::getCamera()
{
    return m_camera;
}

void Player::MoveForward(Game_map* game_map, float l_delta)
{
    this->Move(l_delta, game_map);
}

void Player::MoveBackward(Game_map* game_map, float l_delta)
{
    this->Move(l_delta, game_map);
}

void Player::Move(float l_delta, Game_map* game_map)
{
    float predict_x = this->getCoords().x + l_delta * cos(m_camera->getView().angle);
    float predict_y = this->getCoords().y + l_delta * sin(m_camera->getView().angle);

    if (game_map->game_scheme[int(predict_x)+ int(predict_y)*int(game_map->m_sizeInTile.x)] != ' ') { return; }

    this->setCoords(sf::Vector2f(predict_x, predict_y));
}

Player::Player(sf::Vector2f l_coords, sf::Vector2f l_size, sf::Vector2f l_camera_pending):
    Game_character(l_coords, l_size)
{
    m_camera = new Camera(l_camera_pending, view(1.5708f, PI / 3));
}

Player::~Player()
{
    delete m_camera;
}
