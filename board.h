#pragma once

#include <array>
#include <string>
#include <SFML/Graphics.hpp>

constexpr int WINDOW_HEIGHT = 800, WINDOW_WIDTH = 800;
constexpr unsigned int MAP_HEIGHT = 21, MAP_WIDTH = 21, CELL_SIZE = 16;

class Board
{
protected:
	enum Cell
	{
		DOOR,
		EMPTY,
		FRUIT,
		PELLET,
		WALL
	};

private:
	std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> m_Map{};
	std::array<std::string, MAP_HEIGHT> m_MapSketch = 
	{
		" ################### ",
		" #........#........# ",
		" #o##.###.#.###.##o# ",
		" #.................# ",
		" #.##.#.#####.#.##.# ",
		" #....#...#...#....# ",
		" ####.### # ###.#### ",
		"    #.#   0   #.#    ",
		"#####.# ##=## #.#####",
		"     .  #   #  .     ",
		"#####.# ##### #.#####",
		"    #.#       #.#    ",
		" ####.# ##### #.#### ",
		" #........#........# ",
		" #.##.###.#.###.##.# ",
		" #o.#.....P.....#.o# ",
		" ##.#.#.#####.#.#.## ",
		" #....#...#...#....# ",
		" #.######.#.######.# ",
		" #.................# ",
		" ################### "
	};

public:
	Board();
	void DrawBoard(sf::RenderWindow&);
	void ConvertSketch();
};