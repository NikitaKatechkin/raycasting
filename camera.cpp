#include "camera.h"
#include "player.h"
#include "map.h"

void Camera::setPending(sf::Vector2f l_pending)
{
    m_pending = l_pending;
}

sf::Vector2f Camera::getPending()
{
    return m_pending;
}

void Camera::setView(View l_view)
{
    m_view = l_view;
}

View Camera::getView()
{
    return m_view;
}

void Camera::leftRotate(float delta)
{
    this->Rotate(delta);
}

void Camera::rightRotate(float delta)
{
    this->Rotate(delta);
}

void Camera::draw(sf::RenderWindow* l_window, Player* player, Game_map* game_map)
{
    /*
    INITIALIZING TEXTURE
    */

    for (size_t i = 0; i < l_window->getSize().x / 2; i++)
    {
        float angle = (m_view.angle - m_view.field_of_view / 2) + i * (m_view.field_of_view / float(l_window->getSize().x / 2));
        for(float distance = 0; distance < 5; distance += 0.05)
        {
            float current_x = player->getCoords().x + m_pending.x + distance * cos(angle);
            float current_y = player->getCoords().y + m_pending.y + distance * sin(angle);

            size_t px_x = size_t(current_x * game_map->getBlockSize().x);
            size_t px_y = size_t(current_y * game_map->getBlockSize().y);

            sf::RectangleShape tmp_pixel = sf::RectangleShape(sf::Vector2f(1, 1));
            tmp_pixel.setFillColor(sf::Color::Yellow);
            tmp_pixel.setPosition(sf::Vector2f(float(px_x), float(px_y)));

            l_window->draw(tmp_pixel);

            if (game_map->game_scheme[int(current_x)+ int(current_y)*int(game_map->m_sizeInTile.x)] != ' ')
            {
                size_t column_height = l_window->getSize().y / (distance * cos(angle - player->getCamera()->getView().angle));
                if(column_height >= l_window->getSize().y) { column_height = l_window->getSize().y; }

                char wallType = game_map->game_scheme[int(current_x)+ int(current_y)*int(game_map->m_sizeInTile.x)];
                /*
                DETECTION OF COLLISION WITH HOR / VER SIDE OF WALL
                */
                float padding = 0.f;
                if ((int(current_y) * game_map->getBlockSize().y <= int (current_y * float(game_map->getBlockSize().y))) &&
                    ((current_x - int(current_x)) *  (current_x - int(current_x)) <= 0.025) &&
                    (game_map->game_scheme[int(current_x - 1) + int(current_y)*int(game_map->m_sizeInTile.x)] == ' '))
                {
                    //VERTICAL NORMAL SIDE
                    padding = current_y - int(current_y);

                }
                else if ((int(current_x) * game_map->getBlockSize().x < int (current_x * float(game_map->getBlockSize().x))) &&
                    ((current_y - int(current_y)) *  (current_y - int(current_y)) <= 0.025) &&
                    (game_map->game_scheme[int(current_x) + int(current_y - 1)*int(game_map->m_sizeInTile.x)] == ' '))
                {
                    //HORIZONTAL NORMAL SIDE
                    padding = current_x - int(current_x);
                }
                else
                {
                    if ((int(current_x) * game_map->getBlockSize().x < int (current_x * float(game_map->getBlockSize().x))) &&
                    (current_x - int(current_x) >= current_y - int(current_y)))
                    {
                        //std::cout << "VERTICAL" << std::endl;
                        padding = current_y - int(current_y);
                    }
                    else
                    {
                        //std::cout << "HORIZONTAL" << std::endl;
                        padding = current_x - int(current_x);
                    }
                }
                /*
                CLOTHING THE WALL
                */
                game_map->getSprite()->setTextureRect(sf::IntRect((int(wallType) - 48) * 64 + int(padding * 64), 0, 1, 64));
                game_map->getSprite()->setScale(sf::Vector2f(1.f, (float(column_height) / 64.f)));
                game_map->getSprite()->setPosition(sf::Vector2f(float((l_window->getSize().x /2 + i)), float(l_window->getSize().y / 2 - column_height / 2)));

                l_window->draw(*(game_map->getSprite()));

                //wallStack = true;
                break;
            }
        }
    }
}

void Camera::Rotate(float l_delta)
{
    m_view.angle += l_delta;
}

Camera::Camera(sf::Vector2f l_pending, View l_view)
{
    m_pending = l_pending;
    m_view = l_view;
}

Camera::~Camera()
{

}
