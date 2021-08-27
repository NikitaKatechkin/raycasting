#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <cassert>
#include <math.h>

#define PI 3.14159

uint32_t pack_color(const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a = 255)
{
    return (a << 24) + (b << 16) + (g << 8) + r;
}

void unpack_color(const uint32_t &color, uint8_t &r, uint8_t &g, uint8_t &b, uint8_t &a)
{
    r = (color >> 0) & 255;
    g = (color >> 8) & 255;
    b = (color >> 16) & 255;
    a = (color >> 24) & 255;
}

void drop_ppm_image(const std::string filename, const std::vector<uint32_t> &image, const size_t width, const size_t height)
{
    assert(image.size() == width * height);
    std::ofstream ofs(filename);
    ofs << "P6\n" << width << " " << height << "\n255\n";
    for (size_t pxIndex = 0; pxIndex < height * width; pxIndex++)
    {
        uint8_t r, g, b, a;
        unpack_color(image[pxIndex], r, g, b, a);
        ofs << static_cast<char>(r) << static_cast<char>(g) << static_cast<char>(b);
    }
    ofs.close();
}

void draw_rectangle(std::vector<uint32_t> &image, const size_t image_width, const size_t image_height,
                    const size_t x, const size_t y, const size_t width, const size_t height, const uint32_t color)
{
    assert(image.size() == image_width * image_height);
    for (size_t rect_row = 0; rect_row < height; rect_row++)
    {
        for (size_t rect_col = 0; rect_col < width; rect_col++)
        {
            size_t current_row = y + rect_row;
            size_t current_col = x + rect_col;
            //assert(current_col < image_width && current_row < image_height);
            if (current_col >= image_width || current_row >=image_height)
            {
                continue;
            }
            image[current_col + current_row * image_width] = color;
        }
    }
}

int main()
{
    const size_t win_width = 1024;
    const size_t win_height = 512;

    std::vector<uint32_t> frameBuffer(win_width * win_height, pack_color(255, 255, 255));

    float player_x = 3.456;
    float player_y = 2.345;
    float player_a = 1.523;
    float player_field_of_view = PI / 3;
    const size_t player_width = 5;
    const size_t player_height = 5;

    const size_t map_width = 16;
    const size_t map_height = 16;
    const char game_map[] = "0000222222220000"\
                       "1              0"\
                       "1      11111   0"\
                       "1     0        0"\
                       "0     0  1110000"\
                       "0     3        0"\
                       "0   10000      0"\
                       "0   0   11100  0"\
                       "0   0   0      0"\
                       "0   0   1  00000"\
                       "0       1      0"\
                       "2       1      0"\
                       "0       0      0"\
                       "0 0000000      0"\
                       "0              0"\
                       "0002222222200000";
    assert(sizeof(game_map) == map_width*map_height+1);

    const size_t rect_width = win_width / (map_width * 2);
    const size_t rect_height = win_height / map_height;

    for (size_t row_rect_index = 0; row_rect_index < map_height; row_rect_index++)
    {
        for (size_t col_rect_index = 0; col_rect_index < map_width; col_rect_index++)
        {
            if (game_map[col_rect_index + row_rect_index * map_width] == ' ')
            {
                continue;
            }

            size_t rect_start_x = col_rect_index * rect_width;
            size_t rect_start_y = row_rect_index * rect_height;

            draw_rectangle(frameBuffer, win_width, win_height, rect_start_x, rect_start_y, rect_width, rect_height, pack_color(74, 255, 99));
        }
    }

    draw_rectangle(frameBuffer, win_width, win_height, player_x * rect_width, player_y * rect_height, player_width, player_height, pack_color(255, 255, 255));

    for (size_t i = 0; i < win_width / 2; i++)
    {
        float angle = (player_a - player_field_of_view / 2) + i * (player_field_of_view / float(win_width / 2));
        for(float distance = 0; distance < 20; distance += 0.05)
        {
            float current_x = player_x + distance * cos(angle);
            float current_y = player_y + distance * sin(angle);

            size_t px_x = current_x * rect_width;
            size_t px_y = current_y * rect_height;
            frameBuffer[px_x + px_y * win_width] = pack_color(160, 160, 160);

            if (game_map[int(current_x)+ int(current_y)*map_width] != ' ')
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
