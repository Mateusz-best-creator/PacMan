#include "game.h"
#include <iostream>

Game::Game()
{
    m_Window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "PacMan");
}

void Game::Play()
{
    while (m_Window.isOpen())
    {
        m_Board.DrawBoard(m_Window);
        HandleEvents();
        m_Window.display();
    }
}

void Game::HandleEvents()
{
    sf::Event event;
    while (m_Window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            m_Window.close();
        else if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Right)
                std::cout << "Moving right!\n";
        }
    }
}