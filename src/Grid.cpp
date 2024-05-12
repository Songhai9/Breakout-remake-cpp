#include "../includes/Grid.hpp"

Grid::Grid(SDL_Renderer* renderer, int centerX, int centerY)
    : renderer(renderer), centerX(centerX), centerY(centerY) {}

void Grid::setupGrid() {
    for (int i = 0; i < 20; i++) { 
        bricks.push_back(std::make_unique<Brick>(renderer, i * 50 + 100, 100, 40, 20, 2));
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
