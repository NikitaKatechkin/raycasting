#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>

struct Coordinate
{
    float x_coordinate;
    float y_coordinate;
};

struct View
{
    float angle;
    float field_of_view;
};

struct Phys_size
{
    size_t width;
    size_t height;
};

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
