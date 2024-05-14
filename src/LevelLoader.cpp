#include "../includes/LevelLoader.hpp"
#include <fstream>
#include <iostream>

std::vector<Brick> LevelLoader::loadLevel(const std::string &filePath, int screenWidth, int screenHeight, int brickWidth, int brickHeight, int spacing)
{
    std::vector<Brick> bricks;
    std::ifstream file(filePath);
    if (!file.is_open())
    {
        std::cerr << "Failed to open level file: " << filePath << std::endl;
        return bricks;
    }

    std::string line;
    int y = spacing; // Start with some spacing from the top
    while (std::getline(file, line))
    {
        int x = spacing; // Start with some spacing from the left
        for (char c : line)
        {
            if (c == 'X')
            {
                bricks.emplace_back(x, y, brickWidth, brickHeight, 1); // All bricks have 1 hit point for simplicity
            }
            x += brickWidth + spacing;
        }
        y += brickHeight + spacing;
    }

    file.close();
    return bricks;
}
