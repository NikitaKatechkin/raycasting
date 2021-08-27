#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include "tools.h"

class Game_map
{
public:
    char* game_scheme;
    Phys_size m_sizeInTile;

    void draw();

    Game_map();
    ~Game_map();
};

#endif // MAP_H_INCLUDED
