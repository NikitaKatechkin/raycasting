#include "enemy.h"
#include "camera.h"
#include "player.h"

sf::RectangleShape* Enemy::getMapRect()
{
    return m_mapRect;
}

void Enemy::draw(sf::RenderWindow* l_window, Game_map* game_map, Player* player, Camera* l_camera)
{
    m_mapRect->setSize(m_size);
    m_mapRect->setPosition(sf::Vector2f(m_coords.x * game_map->getBlockSize().x - m_size.x / 2,
                                    m_coords.y * game_map->getBlockSize().y - m_size.y / 2));

    bool isObstclOnWay;

    float current_x;
    float current_y;

    float angle;
    float leftViewBorder;
    float rightViewBorder;
    float distancePtoE;

    sf::RectangleShape tmp_square;
    tmp_square.setFillColor(sf::Color::Green);

    size_t column_height;
    float render_x_coords;

    angle = std::atan2(m_coords.y - player->getCoords().y, m_coords.x - player->getCoords().x);
    angle = std::fmod(angle, 6.28319f);
    if (angle < 0) { angle = 6.28319f + angle; }

    leftViewBorder = player->getCamera()->getView().angle - player->getCamera()->getView().field_of_view / 2;
    leftViewBorder = std::fmod(leftViewBorder, 6.28319f);
    if (leftViewBorder < 0) { leftViewBorder = 6.28319f + leftViewBorder; }

    rightViewBorder = player->getCamera()->getView().angle + player->getCamera()->getView().field_of_view / 2;
    rightViewBorder = std::fmod(rightViewBorder, 6.28319f);
    if (rightViewBorder < 0) { rightViewBorder = 6.28319f + rightViewBorder; }

    distancePtoE = std::hypot(m_coords.x - player->getCoords().x, m_coords.y - player->getCoords().y);

    if ((angle >= leftViewBorder) && (angle <= rightViewBorder) && (distancePtoE <= 5.f))
    {
        //Produce check for obstacles on the way
        isObstclOnWay = false;

        for(float distance = 0; distance < distancePtoE; distance += 0.90)
        {
            current_x = player->getCoords().x + l_camera->getPending().x + distance * cos(angle);
            current_y = player->getCoords().y + l_camera->getPending().y + distance * sin(angle);

            if (game_map->game_scheme[int(current_x)+ int(current_y)*int(game_map->m_sizeInTile.x)] != ' ')
            {
                isObstclOnWay = true;
                break;
            }
        }

        if (!isObstclOnWay)
        {
            m_mapRect->setFillColor(sf::Color::Green);

            /*column_height = l_window->getSize().y / (distancePtoE * cos(angle - player->getCamera()->getView().angle));
            if(column_height >= l_window->getSize().y) { column_height = l_window->getSize().y; }

            //float x_coords = l_window->getSize().x / 2 + (l_window->getSize().x / 2) * ((angle - leftViewBorder) / (rightViewBorder - leftViewBorder));
            render_x_coords = (l_window->getSize().x / 2.f) * (1.f + (angle - leftViewBorder) / (rightViewBorder - leftViewBorder));
            render_x_coords -= column_height / 2;

            if (render_x_coords < 513)
            {
                render_x_coords = 512.f;
                tmp_square.setSize(sf::Vector2f(render_x_coords + column_height - 512, column_height));
            }
            else
            {
                tmp_square.setSize(sf::Vector2f(column_height, column_height));
            }

            tmp_square.setPosition(sf::Vector2f(render_x_coords, float(l_window->getSize().y / 2 - column_height / 2)));
            l_window->draw(tmp_square);
            //std::cout << render_x_coords << std::endl;*/
        }
    }
    else
    {
        m_mapRect->setFillColor(sf::Color::Red);
    }

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
