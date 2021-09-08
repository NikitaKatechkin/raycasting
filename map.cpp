#include "map.h"

void Game_map::setBlockSize(sf::Vector2f l_blockSize)
{
    m_blockSize = l_blockSize;
}

sf::Vector2f Game_map::getBlockSize()
{
    return m_blockSize;
}

void Game_map::draw(sf::RenderWindow *l_window)
{
    for (size_t row_rect_index = 0; row_rect_index < size_t(m_sizeInTile.x); row_rect_index++)
    {
        for (size_t col_rect_index = 0; col_rect_index < size_t(m_sizeInTile.y); col_rect_index++)
        {
            if (game_scheme[col_rect_index + row_rect_index * size_t(m_sizeInTile.x)] == ' ')
            {
                continue;
            }

            sf::RectangleShape tmp_draw_rect(m_blockSize);

            sf::Color wallColor;
            switch (game_scheme[col_rect_index + row_rect_index * size_t(m_sizeInTile.x)])
            {
            case '0':
                wallColor = sf::Color::Magenta;
                break;
            case '1':
                wallColor = sf::Color::Cyan;
                break;
            case '2':
                wallColor = sf::Color::Green;
                break;
            default:
                break;
            }
            tmp_draw_rect.setFillColor(wallColor);

            tmp_draw_rect.setPosition(sf::Vector2f((col_rect_index * m_blockSize.x),
                                                   (row_rect_index * m_blockSize.y)));

            l_window->draw(tmp_draw_rect);
        }
    }
}

Game_map::Game_map(std::string filePath, sf::Vector2u winSize)
{
    std::ifstream file(filePath);

    float map_width = 8.f;
    float map_height = 8.f;

    file >> map_width >> map_height;
    m_sizeInTile = sf::Vector2f(map_width, map_height);

    game_scheme = new char[int(m_sizeInTile.x * m_sizeInTile.y + 1)];

    std::string line;
    std::getline(file, line);
    for (size_t row_index = 0; row_index < size_t(m_sizeInTile.x); row_index++)
    {
        std::getline(file, line);
        for (size_t col_index = 0; col_index < size_t(m_sizeInTile.y); col_index++)
        {
            game_scheme[int(col_index + row_index * m_sizeInTile.x)] = line[col_index];
        }
    }

   m_blockSize = sf::Vector2f(winSize.x / (m_sizeInTile.x * 2), winSize.y / m_sizeInTile.y);
}

Game_map::~Game_map()
{
    delete[] game_scheme;
}
