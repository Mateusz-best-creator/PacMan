#include "board.h"

Board::Board()
{

}

void Board::DrawBoard(sf::RenderWindow& window)
{
    window.clear();
    sf::Sprite sprite;

    sf::Texture texture;
    std::string filePath = "Assets\\Map" + std::to_string(CELL_SIZE) + ".png";
    texture.loadFromFile(filePath);

    // Get map sketch and interpret it
    ConvertSketch();

    sprite.setTexture(texture);

    // Calculate new cell size to fit the screen dimensions
    float scaleX = static_cast<float>(WINDOW_WIDTH) / (MAP_WIDTH * CELL_SIZE);
    float scaleY = static_cast<float>(WINDOW_HEIGHT) / (MAP_HEIGHT * CELL_SIZE);
    float scale = std::min(scaleX, scaleY);

    for (int width_index = 0; width_index < MAP_WIDTH; width_index++)
    {
        for (int height_index = 0; height_index < MAP_HEIGHT; height_index++)
        {
            sprite.setPosition(static_cast<float>(CELL_SIZE * width_index * scale), static_cast<float>(CELL_SIZE * height_index * scale));
            sprite.setScale(scale, scale); // Scale the sprite

            switch (m_Map[width_index][height_index])
            {
            case Cell::DOOR:
                sprite.setTextureRect(sf::IntRect(2 * CELL_SIZE, CELL_SIZE, CELL_SIZE, CELL_SIZE));
                window.draw(sprite);
                break;
            case Cell::FRUIT:
                sprite.setTextureRect(sf::IntRect(CELL_SIZE, CELL_SIZE, CELL_SIZE, CELL_SIZE));
                window.draw(sprite);
                break;
            case Cell::PELLET:
                sprite.setTextureRect(sf::IntRect(0, CELL_SIZE, CELL_SIZE, CELL_SIZE));
                window.draw(sprite);
                break;
            case Cell::WALL:
                short down = 0;
                short left = 0;
                short right = 0;
                short up = 0;

                if (height_index < MAP_HEIGHT - 1)
                {
                    if (Cell::WALL == m_Map[width_index][1 + height_index])
                        down = 1;
                }
                if (0 < width_index)
                {
                    if (Cell::WALL == m_Map[width_index - 1][height_index])
                        left = 1;
                }
                else
                    left = 1;

                if (width_index < MAP_WIDTH - 1)
                {
                    if (Cell::WALL == m_Map[1 + width_index][height_index])
                        right = 1;
                }
                else
                    right = 1;

                if (0 < height_index)
                {
                    if (Cell::WALL == m_Map[width_index][height_index - 1])
                        up = 1;
                }
                sprite.setTextureRect(sf::IntRect(CELL_SIZE * (down + 2 * (left + 2 * (right + 2 * up))), 0, CELL_SIZE, CELL_SIZE));
                window.draw(sprite);
            }
        }
    }
}


void Board::ConvertSketch()
{
	for (int height_index = 0; height_index < MAP_HEIGHT; height_index++)
	{
		for (int width_index = 0; width_index < MAP_WIDTH; width_index++)
		{
			switch (m_MapSketch[height_index][width_index])
			{
			case '#':
				m_Map[width_index][height_index] = Cell::WALL;
				break;
			case '=':
				m_Map[width_index][height_index] = Cell::DOOR;
				break;
			case '.':
				m_Map[width_index][height_index] = Cell::PELLET;
				break;
			case 'o':
				m_Map[width_index][height_index] = Cell::FRUIT;
				break;
            //By default, every cell is empty.
            default:
                 m_Map[width_index][height_index] = Cell::EMPTY;
                 break;
			}
		}
	}
}