#ifndef BRICK_HPP
#define BRICK_HPP

#include <SDL2/SDL.h>

class Brick
{
public:
    Brick(int x, int y, int width, int height, int hitPoints);
    void render(SDL_Renderer *renderer) const;
    void hit();
    bool isDestroyed() const;
    bool isHit() const;
    bool wasJustDestroyed();
    void resetHitFlag();
    SDL_Rect getRect() const;

private:
    SDL_Color getColor() const;
    SDL_Rect rect;
    int hitPoints;
    bool hitFlag;
    bool destroyedFlag;
};

#endif
