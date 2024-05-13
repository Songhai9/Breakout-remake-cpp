#include "../includes/Grid.hpp"
#include "../includes/Brick.hpp"

Grid::Grid(SDL_Renderer* renderer, int centerX, int centerY)
    : renderer(renderer), centerX(centerX), centerY(centerY) {}

void Grid::setupGrid() {
    const int SPACING = 5; // Adjust spacing between bricks
    const int screenWidth = 800; // Assume screen width is 800 pixels
    const int numRows = 3; // Number of rows of bricks
    const int numCols = 15; // Number of columns of bricks
    const int brickHeight = 20; // Height of each brick
    int brickWidth = (screenWidth - (SPACING * (numCols + 1))) / numCols; // Calculate brick width dynamically

    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            int x = SPACING + col * (brickWidth + SPACING);
            int y = SPACING + row * (brickHeight + SPACING);
            bricks.push_back(std::make_unique<Brick>(renderer, x, y, brickWidth, brickHeight, 2)); // Assuming 2 hits required
        }
    }
}

void Grid::render() {
    for (auto& brick : bricks) {
        brick->render();
    }
}

bool Grid::checkCollision(const SDL_Rect& ballRect, SDL_Rect* collidedBrickRect) {
    for (auto& brick : bricks) {
        if (brick->checkCollision(ballRect)) {
            if (collidedBrickRect != nullptr) {
                *collidedBrickRect = brick->getRect();
            }
            return true;
        }
    }
    return false;
}
