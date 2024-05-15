#include "../includes/brick.hpp"
#include "../includes/utils.hpp"
#include <vector>

Brick::Brick(int x, int y, int width, int height, int hitPoints)
    : rect{x, y, width, height}, hitPoints(hitPoints), hitFlag(false), destroyedFlag(false)
{
}

void Brick::render(SDL_Renderer *renderer) const
{
    SDL_Color color = getColor();
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);
}

void Brick::renderHexagonal(SDL_Renderer *renderer) const
{
    SDL_Color color = getColor();
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    // Drawing hexagonal brick is not implemented here, add implementation.
}

void Brick::renderTriangular(SDL_Renderer *renderer) const
{
    SDL_Color color = getColor();
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    // Drawing triangular brick is not implemented here, add implementation.
}

void Brick::hit()
{
    if (hitPoints > 0)
    {
        hitPoints--;
        hitFlag = true;
        if (hitPoints == 0)
        {
            destroyedFlag = true;
        }
    }
}

bool Brick::isDestroyed() const
{
    return hitPoints <= 0;
}

bool Brick::isHit() const
{
    return hitFlag;
}

bool Brick::wasJustDestroyed()
{
    if (destroyedFlag)
    {
        destroyedFlag = false;
        return true;
    }
    return false;
}

void Brick::resetHitFlag()
{
    hitFlag = false;
}

SDL_Rect Brick::getRect() const
{
    return rect;
}

SDL_Color Brick::getColor() const
{
    switch (hitPoints)
    {
    case 3:
        return {0x33, 0x33, 0x33, 0xFF};
    case 2:
        return {0x66, 0x66, 0x66, 0xFF};
    case 1:
        return {0x99, 0x99, 0x99, 0xFF};
    default:
        return {0x00, 0xFF, 0x00, 0xFF};
    }
}
