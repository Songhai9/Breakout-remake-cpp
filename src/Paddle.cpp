#include "../includes/Paddle.hpp"

Paddle::Paddle(SDL_Renderer* renderer, int windowWidth, int windowHeight)
    : renderer(renderer), windowWidth(windowWidth), speed(10) {
    rect.w = 100;  // Paddle width
    rect.h = 20;   // Paddle height
    rect.x = (windowWidth - rect.w) / 2;  // Center paddle initially
    rect.y = windowHeight - rect.h - 30;  // Position paddle at the bottom
}

void Paddle::update() {
    // Movement logic is handled in handleEvent
}

void Paddle::handleEvent(SDL_Event& event) {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_LEFT:
                rect.x -= speed;
                if (rect.x < 0) {
                    rect.x = 0;  // Prevent moving out of the window on the left
                }
                break;
            case SDLK_RIGHT:
                rect.x += speed;
                if (rect.x > windowWidth - rect.w) {
                    rect.x = windowWidth - rect.w;  // Prevent moving out of the window on the right
                }
                break;
        }
    }
}

void Paddle::render() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White color for the paddle
    SDL_RenderFillRect(renderer, &rect);
}

const SDL_Rect& Paddle::getRect() const {
    return rect;
}
