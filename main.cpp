#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <cassert>
#include <math.h>

#include "player.h"
#include "map.h"

#define PI 3.14159

int main()
{
    const size_t win_width = 1024;
    const size_t win_height = 512;

    std::vector<uint32_t> frameBuffer(win_width * win_height, pack_color(255, 255, 255));

    Player player(coordinate(3.456, 2.345), view(1.523f, float(PI / 3)), phys_size(5, 5));

    Game_map game_map("map.txt");

    const size_t rect_width = win_width / (game_map.m_sizeInTile.width * 2);
    const size_t rect_height = win_height / game_map.m_sizeInTile.width;

    game_map.draw(phys_size(win_width, win_height), frameBuffer);

    draw_rectangle(frameBuffer, win_width, win_height, player.getCoords().x_coordinate * rect_width,
                   player.getCoords().y_coordinate * rect_height, player.getSize().width, player.getSize().height, pack_color(255, 255, 255));

    for (size_t i = 0; i < win_width / 2; i++)
    {
        float angle = (player.getView().angle - player.getView().field_of_view / 2) + i * (player.getView().field_of_view / float(win_width / 2));
        for(float distance = 0; distance < 20; distance += 0.05)
        {
            float current_x = player.getCoords().x_coordinate + distance * cos(angle);
            float current_y = player.getCoords().y_coordinate + distance * sin(angle);

            size_t px_x = current_x * rect_width;
            size_t px_y = current_y * rect_height;
            frameBuffer[px_x + px_y * win_width] = pack_color(160, 160, 160);

            if (game_map.game_scheme[int(current_x)+ int(current_y)*game_map.m_sizeInTile.width] != ' ')
            {
                size_t column_height = win_height / distance;
                draw_rectangle(frameBuffer, win_width, win_height, (win_width/2 + i), (win_height / 2 - column_height / 2), 1, column_height, pack_color(0, 255, 255));
                break;
            }
        }
    }


    drop_ppm_image("./out.ppm", frameBuffer, win_width, win_height);

    return 0;
}
