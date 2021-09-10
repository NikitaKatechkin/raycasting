#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "camera.h"
#include "game_character.h"

#define PI 3.14159

class Player : public Game_character
{
public:
    void MoveForward(Game_map* game_map, float l_delta = 0.1f);
    void MoveBackward(Game_map* game_map, float l_delta = -0.1f);

    Camera* getCamera();

    Player(sf::Vector2f l_coords, sf::Vector2f l_size, sf::Vector2f l_camera_pending = sf::Vector2f(0, 0));
    ~Player();
protected:
    void Move(float l_delta, Game_map* game_map);

    Camera* m_camera;
};

#endif // PLAYER_H_INCLUDED
