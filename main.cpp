#define SFML_STATIC

#include <SFML/Graphics.hpp>
#include "map.h"
#include <cassert>
#include "player.h"

int main()
{
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1024, 512), "DOOM replica");
    Game_map* game_map = new Game_map("./map.txt", window->getSize());
    Player* player = new Player(sf::Vector2f(3.456, 2.345), view(1.523, PI / 3), sf::Vector2f(5.f, 5.f));

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        window->clear();

        game_map->draw(window);
        player->getCamera()->draw(window, player, game_map);

        window->display();
    }

    return 0;
}
