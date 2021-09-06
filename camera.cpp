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

/*void Player::setSize(sf::Vector2f l_size)
{
    m_size = l_size;
}

sf::Vector2f Player::getSize()
{
    return m_size;
}*/

void Camera::draw(sf::RenderWindow* l_window, Player* player, Game_map* game_map)
{
    /*const size_t rect_width = winSize.width / (game_map.m_sizeInTile.width * 2);
    const size_t rect_height = winSize.height / game_map.m_sizeInTile.height;*/

    for (size_t i = 0; i < l_window->getSize().x / 2; i++)
    {
        float angle = (m_view.angle - m_view.field_of_view / 2) + i * (m_view.field_of_view / float(l_window->getSize().x / 2));
        for(float distance = 0; distance < 20; distance += 0.05)
        {
            float current_x = player->getCoords().x + m_pending.x + distance * cos(angle);
            float current_y = player->getCoords().y + m_pending.y + distance * sin(angle);

            //DRAW HERE
            size_t px_x = size_t(current_x * game_map->getBlockSize().x); //game_map.getBlockSize().x
            size_t px_y = size_t(current_y * game_map->getBlockSize().y); //game_map.getBlockSize().y
            //(*frameBuffer)[px_x + px_y * winSize.width] = pack_color(160, 160, 160);

            sf::RectangleShape tmp_pixel = sf::RectangleShape(sf::Vector2f(1, 1));
            tmp_pixel.setFillColor(sf::Color::Yellow);
            tmp_pixel.setPosition(sf::Vector2f(float(px_x), float(px_y)));

            l_window->draw(tmp_pixel);

            if (game_map->game_scheme[int(current_x)+ int(current_y)*int(game_map->m_sizeInTile.x)] != ' ')
            {
                size_t column_height = l_window->getSize().y / distance;
                /*draw_rectangle(frameBuffer, winSize.width, winSize.height, (winSize.width/2 + i), (winSize.height / 2 - column_height / 2),
                               1, column_height, pack_color(0, 255, 255));*/

                tmp_pixel.setFillColor(sf::Color::Red);
                tmp_pixel.setSize(sf::Vector2f(1.f, float(column_height)));
                tmp_pixel.setPosition(sf::Vector2f(float((l_window->getSize().x /2 + i)), float(l_window->getSize().y / 2 - column_height / 2)));

                l_window->draw(tmp_pixel);

                break;
            }
        }
    }
}

Camera::Camera(sf::Vector2f l_pending, View l_view/*, sf::Vector2f l_size*/)
{
    m_pending = l_pending;
    m_view = l_view;
    /*m_size = l_size;*/
}

Camera::~Camera()
{

}
