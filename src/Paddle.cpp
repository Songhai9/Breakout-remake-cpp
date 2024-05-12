#include "../includes/Paddle.hpp"
#include <cmath>

Paddle::Paddle(SDL_Renderer* renderer, int centerX, int centerY, int radius)
    : renderer(renderer), centerX(centerX), centerY(centerY), radius(radius), angle(0.0) {
    rect.w = 100;  // Paddle width
    rect.h = 20;   // Paddle height
    calculatePosition();
}

void Paddle::setAngle(float angleDelta) {
    angle += angleDelta;
    calculatePosition();
}

void Paddle::calculatePosition() {
    rect.x = centerX + static_cast<int>(radius * cos(angle)) - rect.w / 2;
    rect.y = centerY + static_cast<int>(radius * sin(angle)) - rect.h / 2;
}

void Paddle::update() {
    // Update logic for paddle, if any
}

void Paddle::handleEvent(SDL_Event& event) {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_LEFT:
                setAngle(-0.1);  // Rotate left
                break;
            case SDLK_RIGHT:
                setAngle(0.1);   // Rotate right
                break;
        }
    }
}

void Paddle::render() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White paddle
    SDL_RenderFillRect(renderer, &rect);
}
