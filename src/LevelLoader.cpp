#include "../includes/LevelLoader.hpp"
#include <fstream>
#include <iostream>
#include <cmath>

/**
 * @brief Loads a level from a file, creating a vector of bricks with specified attributes.
 *
 * @param filePath Path to the level configuration file.
 * @param shape Shape of the bricks in the level (Rectangular, Hexagonal, Triangular).
 * @param screenWidth Width of the game screen to scale brick positioning.
 * @param screenHeight Height of the game screen to scale brick positioning.
 * @param brickWidth Width of each brick.
 * @param brickHeight Height of each brick.
 * @param spacing Space between bricks.
 * @return std::vector<Brick> Vector containing all bricks for the level.
 */
std::vector<Brick> LevelLoader::loadLevel(const std::string &filePath, GridShape shape, int screenWidth, int screenHeight, int brickWidth, int brickHeight, int spacing)
{
    std::vector<Brick> bricks;
    std::ifstream file(filePath);
    if (!file.is_open())
    {
        std::cerr << "Failed to open level file: " << filePath << std::endl;
        return bricks;
    }

    std::string line;
    int y = spacing;
    int row = 0;
    while (std::getline(file, line))
    {
        int x = spacing;
        for (char c : line)
        {
            int hitPoints = 0;
            if (c == 'X')
            {
                hitPoints = 1;
            }
            else if (c == 'Y')
            {
                hitPoints = 2;
            }
            else if (c == 'Z')
            {
                hitPoints = 3;
            }

            if (hitPoints > 0)
            {
                if (shape == RECTANGULAR)
                {
                    bricks.emplace_back(x, y, brickWidth, brickHeight, hitPoints);
                }
                else if (shape == HEXAGONAL)
                {
                    int offsetX = (row % 2 == 0) ? 0 : (brickWidth / 2 + spacing / 2);
                    bricks.emplace_back(x + offsetX, y, brickWidth, brickHeight, hitPoints);
                }
                else if (shape == TRIANGULAR)
                {
                    bricks.emplace_back(x + (row * (brickWidth + spacing) / 2), y, brickWidth, brickHeight, hitPoints);
                }
            }
            x += brickWidth + spacing;
        }
        y += brickHeight + spacing;
        row++;
    }

    file.close();
    return bricks;
}
