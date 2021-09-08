#define SFML_STATIC

/*#include <SFML/Graphics.hpp>
#include "map.h"
#include <cassert>
#include "player.h"*/
#include "game.h"

int main()
{
    /*sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1024, 512), "DOOM replica");
    Game_map* game_map = new Game_map("./map.txt", window->getSize());
    Player* player = new Player(sf::Vector2f(3.456, 2.345), sf::Vector2f(5.f, 5.f));

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if(event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                case sf::Keyboard::A:
                    player->getCamera()->leftRotate();
                    break;
                case sf::Keyboard::D:
                    player->getCamera()->rightRotate();
                    break;
                case sf::Keyboard::W:
                    player->MoveForward(game_map);
                    break;
                case sf::Keyboard::S:
                    player->MoveBackward(game_map);
                    break;
                default:
                    break;
                }
            }
            if (event.type == sf::Event::Closed)
                window->close();
        }

        window->clear();

        game_map->draw(window);
        player->getCamera()->draw(window, player, game_map);

        window->display();
    }*/

    Game* game = new Game(sf::VideoMode(1024, 512), "DOOM replica",
              sf::Vector2f(3.456, 2.345), sf::Vector2f(5.f, 5.f),
              "./map.txt");

    while(!game->isOver())
    {
        game->handleEvent();
        game->update();
        game->render();
    }

    return 0;
}
