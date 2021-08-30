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
    Phys_size m_blockSize;

    void draw(Phys_size winSize, std::vector<uint32_t>* frameBuffer);

    void setBlockSize(Phys_size l_size);
    Phys_size getBlockSize();

    Game_map(std::string filePath, Phys_size l_winSize);
    ~Game_map();
};

#endif // MAP_H_INCLUDED
