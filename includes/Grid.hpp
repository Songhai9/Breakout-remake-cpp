#ifndef GRID_HPP
#define GRID_HPP

#include <vector>
#include <memory>
#include <SDL2/SDL.h>
#include "Brick.hpp"

class Grid
{
public:
    Grid(SDL_Renderer *renderer, int centerX, int centerY);
    void setupGrid();
    void render();
    bool checkCollision(const SDL_Rect &ballRect, SDL_Rect *collidedBrickRect);

private:
    SDL_Renderer *renderer;
    std::vector<std::unique_ptr<Brick>> bricks;
    int centerX, centerY;
};

#endif
