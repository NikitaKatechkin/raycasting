#include "game.h"

void Game::handleEvent()
{
    sf::Event event;
    while (m_window->pollEvent(event))
    {
        if(event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
            case sf::Keyboard::A:
                m_player->getCamera()->leftRotate();
                break;
            case sf::Keyboard::D:
                m_player->getCamera()->rightRotate();
                break;
            case sf::Keyboard::W:
                m_player->MoveForward(m_gameMap);
                break;
            case sf::Keyboard::S:
                m_player->MoveBackward(m_gameMap);
                break;
            case sf::Keyboard::Escape:
                m_isOver = true;
                break;
            default:
                break;
            }
        }
        if (event.type == sf::Event::Closed)
            m_isOver = true;
    }
}

void Game::render()
{
    m_window->clear();

    m_gameMap->draw(m_window);

    m_player->getCamera()->draw(m_window, m_player, m_gameMap);
    m_player->getCamera()->drawObjects(m_window, m_player, m_gameMap, m_enemys);
    m_player->draw(m_window, m_gameMap);

    for (int i = 0; i < 4; i++)
    {
        m_enemys[i].draw(m_window, m_gameMap, m_player, m_player->getCamera());
    }

    m_window->display();
}

void Game::update()
{
    if (m_isOver)
    {
        m_window->close();
        return;
    }
}

bool Game::isOver()
{
    return m_isOver;
}

Enemy* Game::getEnemys()
{
    return m_enemys;
}

Game::Game(sf::VideoMode l_videoMode, std::string l_windowName,
           sf::Vector2f l_coords, sf::Vector2f l_size,
           std::string l_filePath, std::string filePath, sf::Vector2f l_camera_pending, bool l_isOver):
               m_isOver(l_isOver)
{
    m_window = new sf::RenderWindow(l_videoMode, l_windowName);
    m_gameMap = new Game_map(l_filePath, m_window->getSize(), filePath);
    m_player = new Player(l_coords, l_size, l_camera_pending);

    m_enemys = new Enemy[4];
    for (int i = 0; i < 4; i++)
    {
        m_enemys[i].setCoords(sf::Vector2f(3.456 + 0.5f * i, 3.456 + 0.5f * i));
    }
}

Game::~Game()
{
    delete m_player;
    delete m_gameMap;
    delete m_window;
    delete[] m_enemys;
}
