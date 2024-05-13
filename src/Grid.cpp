#include "../includes/Grid.hpp"
#include "../includes/Brick.hpp"

Grid::Grid(SDL_Renderer *renderer, int centerX, int centerY)
    : renderer(renderer), centerX(centerX), centerY(centerY) {}

void Grid::setupGrid()
{
    const int SPACING = 5;
    const int screenWidth = 800;
    const int numRows = 6;
    const int numCols = 15;
    const int brickHeight = 20;
    int brickWidth = (screenWidth - (SPACING * (numCols + 1))) / numCols;

    for (int row = 0; row < numRows; row++)
    {
        int hitsRequired = 3 - (row % 3);
        for (int col = 0; col < numCols; col++)
        {
            int x = SPACING + col * (brickWidth + SPACING);
            int y = SPACING + row * (brickHeight + SPACING);
            bricks.push_back(std::make_unique<Brick>(renderer, x, y, brickWidth, brickHeight, hitsRequired));
        }
    }
}

void Grid::render()
{
    for (auto &brick : bricks)
    {
        if (!brick->isDestroyed())
        {
            brick->render();
        }
    }
}

bool Grid::checkCollision(const SDL_Rect &ballRect, SDL_Rect *collidedBrickRect)
{
    for (auto &brick : bricks)
    {
        if (brick->checkCollision(ballRect))
        {
            if (collidedBrickRect != nullptr)
            {
                *collidedBrickRect = brick->getRect();
            }
            return true;
        }
    }
    return false;
}
