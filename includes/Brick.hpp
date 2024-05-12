#ifndef BRICK_HPP
#define BRICK_HPP

#include <SDL2/SDL.h>

class Brick {
public:
    Brick(SDL_Renderer* renderer, int x, int y, int w, int h, int hitsRequired);
    void render();
    bool checkCollision(const SDL_Rect& ballRect);
    const SDL_Rect& getRect() const;

private:
    SDL_Renderer* renderer;
    SDL_Rect rect;
    int hitsLeft;
};

#endif
