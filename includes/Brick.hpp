#ifndef BRICK_HPP
#define BRICK_HPP

#include <SDL2/SDL.h>

class Brick
{
public:
    Brick(SDL_Renderer *renderer, int x, int y, int w, int h, int hitsRequired);
    void render();
    bool checkCollision(const SDL_Rect &ballRect);
    const SDL_Rect &getRect() const;
    bool isDestroyed() const;
    void setColor();

private:
    SDL_Renderer *renderer;
    SDL_Rect rect;
    SDL_Color color;
    int hitsLeft;
    bool destroyed;
};

#endif