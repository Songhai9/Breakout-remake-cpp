#ifndef LEVELLOADER_HPP
#define LEVELLOADER_HPP

#include <vector>
#include <string>
#include "brick.hpp"

class LevelLoader
{
public:
    enum GridShape
    {
        RECTANGULAR,
        HEXAGONAL,
        TRIANGULAR
    };

    static std::vector<Brick> loadLevel(const std::string &filePath, GridShape shape, int screenWidth, int screenHeight, int brickWidth, int brickHeight, int spacing);
};

#endif
