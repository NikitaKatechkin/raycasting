#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "map.h"
#include <cassert>
#include "player.h"
#include "enemy.h"

class Game
{
public:
    void handleEvent();
    void render();
    void update();

    bool isOver();

    Game(sf::VideoMode l_videoMode, std::string l_windowName,
         sf::Vector2f l_coords, sf::Vector2f l_size,
         std::string filePath, std::string textureWallPath,
         sf::Vector2f l_camera_pending = sf::Vector2f(0, 0), bool l_isOver = false);
    ~Game();
private:
    bool m_isOver;

    Player* m_player;
    Game_map* m_gameMap;

    Enemy* m_enemys;

    sf::RenderWindow* m_window;
};

#endif // GAME_H_INCLUDED
