#include "../includes/Grid.hpp"

Grid::Grid(SDL_Renderer* renderer, int centerX, int centerY)
    : renderer(renderer), centerX(centerX), centerY(centerY) {}

void Grid::setupGrid() {
    // Example setup for bricks
    for (int i = 0; i < 10; i++) {  // Just an example
        bricks.push_back(std::make_unique<Brick>(renderer, i * 50 + 100, 100, 40, 20, 2));
    }
}

void Grid::render() {
    for (auto& brick : bricks) {
        brick->render();
    }
}

bool Grid::checkCollision(const SDL_Rect& ballRect) {
    for (auto& brick : bricks) {
        if (brick->checkCollision(ballRect)) {
            return true;
        }
    }
    return false;
}
