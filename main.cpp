#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <cassert>
#include <math.h>

#include "player.h"
#include "map.h"

#include"window.h"

#define PI 3.14159

void draw_first_view(Phys_size winSize, std::vector<uint32_t>* frameBuffer, Player& player, Game_map& game_map)
{
    const size_t rect_width = winSize.width / (game_map.m_sizeInTile.width * 2);
    const size_t rect_height = winSize.height / game_map.m_sizeInTile.height;

    for (size_t i = 0; i < winSize.width / 2; i++)
    {
        float angle = (player.getView().angle - player.getView().field_of_view / 2) + i * (player.getView().field_of_view / float(winSize.width / 2));
        for(float distance = 0; distance < 20; distance += 0.05)
        {
            float current_x = player.getCoords().x_coordinate + distance * cos(angle);
            float current_y = player.getCoords().y_coordinate + distance * sin(angle);

            size_t px_x = current_x * rect_width;
            size_t px_y = current_y * rect_height;
            (*frameBuffer)[px_x + px_y * winSize.width] = pack_color(160, 160, 160);

            if (game_map.game_scheme[int(current_x)+ int(current_y)*game_map.m_sizeInTile.width] != ' ')
            {
                size_t column_height = winSize.height / distance;
                draw_rectangle(frameBuffer, winSize.width, winSize.height, (winSize.width/2 + i), (winSize.height / 2 - column_height / 2),
                               1, column_height, pack_color(0, 255, 255));
                break;
            }
        }
    }
}

int main()
{
    Window window(1024, 512, pack_color(255, 255, 255));

    Player player(coordinate(3.456, 2.345), view(1.523f, float(PI / 3)), phys_size(5, 5));

    Game_map game_map("map.txt", phys_size(window.getWidth(), window.getHeight()));

    /*const size_t rect_width = window.getWidth() / (game_map.m_sizeInTile.width * 2);
    const size_t rect_height = window.getHeight() / game_map.m_sizeInTile.width;*/

    game_map.draw(phys_size(window.getWidth(), window.getHeight()), window.getFrameBuffer());

    draw_rectangle(window.getFrameBuffer(), window.getWidth(), window.getHeight(), player.getCoords().x_coordinate * game_map.getBlockSize().width,
                   player.getCoords().y_coordinate * game_map.getBlockSize().height, player.getSize().width, player.getSize().height, pack_color(255, 255, 255));

    draw_first_view(phys_size(window.getWidth(), window.getHeight()), window.getFrameBuffer(), player, game_map);

    drop_ppm_image("./out.ppm", window.getFrameBuffer(), window.getWidth(), window.getHeight());

    return 0;
}
