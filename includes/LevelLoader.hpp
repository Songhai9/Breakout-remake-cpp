#ifndef LEVELLOADER_HPP
#define LEVELLOADER_HPP

#include <vector>
#include <string>
#include "brick.hpp"

class LevelLoader {
public:
    static std::vector<Brick> loadLevel(const std::string& filePath, int screenWidth, int screenHeight, int brickWidth, int brickHeight, int spacing);
};

#endif
