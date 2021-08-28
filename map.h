#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include "tools.h"
#include <sstream>
#include <string>
#include <fstream>

class Game_map
{
public:
    char* game_scheme;
    Phys_size m_sizeInTile;

    void draw(Phys_size winSize, std::vector<uint32_t>* frameBuffer);

    Game_map(std::string filePath);
    ~Game_map();
};

#endif // MAP_H_INCLUDED
