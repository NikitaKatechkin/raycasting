#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "tools.h"

class Player
{
public:
    void setCoords(Coordinate l_coords);
    Coordinate getCoords();

    void setView(View l_view);
    View getView();

    void setSize(Phys_size l_size);
    Phys_size getSize();

    Player(Coordinate l_coords, View l_view, Phys_size l_size);
    ~Player();
private:
    Coordinate m_coords;
    View m_view;

    Phys_size m_size;
};

#endif // PLAYER_H_INCLUDED
