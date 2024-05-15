#ifndef LEVELLOADER_HPP
#define LEVELLOADER_HPP

#include <vector>
#include <string>
#include "brick.hpp"

/**
 * @class LevelLoader
 * @brief Responsible for loading game levels from files.
 *
 * The LevelLoader class handles the creation of levels by reading layout configurations from files and creating bricks accordingly.
 */
class LevelLoader
{
public:
    enum GridShape
    {
        RECTANGULAR, ///< Rectangular shaped bricks.
        HEXAGONAL,   ///< Hexagonal shaped bricks.
        TRIANGULAR   ///< Triangular shaped bricks.
    };

    /**
     * @brief Loads a level from a file.
     *
     * @param filePath Path to the level configuration file.
     * @param shape Shape of the bricks in the level.
     * @param screenWidth Width of the game screen to scale brick positioning.
     * @param screenHeight Height of the game screen to scale brick positioning.
     * @param brickWidth Width of each brick.
     * @param brickHeight Height of each brick.
     * @param spacing Space between bricks.
     * @return std::vector<Brick> Vector containing all bricks for the level.
     */
    static std::vector<Brick> loadLevel(const std::string &filePath, GridShape shape, int screenWidth, int screenHeight, int brickWidth, int brickHeight, int spacing);
};

#endif
