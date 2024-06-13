#pragma once

#include "board.h"

class Game
{
private:
	Board m_Board;
	sf::RenderWindow m_Window;

public:
	Game();
	void Play();
	void HandleEvents();
};