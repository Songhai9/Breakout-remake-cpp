#include "../includes/Brick.hpp"

Brick::Brick(SDL_Renderer* renderer, int x, int y, int w, int h, int hitsRequired)
    : renderer(renderer), rect{x, y, w, h}, hitsLeft(hitsRequired) {}

void Brick::render() {
    int r = 255;  // Red value for orange
    int g = 50 + 70 * (hitsLeft - 1);  // Increasing green makes it lighter
    int b = 0;  // Blue value stays at 0 for orange color
    SDL_SetRenderDrawColor(renderer, r, g, b, 255); // Shades of orange depending on hitsLeft
    SDL_RenderFillRect(renderer, &rect);
}

bool Brick::checkCollision(const SDL_Rect& ballRect) {
    if (SDL_HasIntersection(&ballRect, &rect)) {
        hitsLeft--;
        return hitsLeft <= 0;
    }
    return false;
}

const SDL_Rect& Brick::getRect() const {
    return rect;
}