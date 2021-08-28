#include "map.h"

void Game_map::draw(Phys_size winSize, std::vector<uint32_t>* frameBuffer)
{

    const size_t rect_width = winSize.width / (m_sizeInTile.width * 2);
    const size_t rect_height = winSize.height / m_sizeInTile.height;

    for (size_t row_rect_index = 0; row_rect_index < m_sizeInTile.height; row_rect_index++)
    {
        for (size_t col_rect_index = 0; col_rect_index < m_sizeInTile.width; col_rect_index++)
        {
            if (game_scheme[col_rect_index + row_rect_index * m_sizeInTile.width] == ' ')
            {
                continue;
            }

            size_t rect_start_x = col_rect_index * rect_width;
            size_t rect_start_y = row_rect_index * rect_height;

            draw_rectangle(frameBuffer, winSize.width, winSize.height, rect_start_x, rect_start_y, rect_width, rect_height, pack_color(74, 255, 99));
        }
    }
}

Game_map::Game_map(std::string filePath)
{
    std::ifstream file(filePath);

    int map_width = 8;
    int map_height = 8;

    file >> map_width >> map_height;
    m_sizeInTile = phys_size(map_width, map_height);

    game_scheme = new char[m_sizeInTile.height * m_sizeInTile.width + 1];

    std::string line;
    std::getline(file, line);
    for (size_t row_index = 0; row_index < m_sizeInTile.height; row_index++)
    {
        std::getline(file, line);
        for (size_t col_index = 0; col_index < m_sizeInTile.width; col_index++)
        {
            game_scheme[col_index + row_index * m_sizeInTile.width] = line[col_index];
        }
    }
}

Game_map::~Game_map()
{
    delete[] game_scheme;
}
