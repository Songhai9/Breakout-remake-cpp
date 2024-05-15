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

    // Calcul des coordonnées des sommets de l'hexagone
    int x1 = rect.x + rect.w / 4;
    int y1 = rect.y;
    int x2 = rect.x + rect.w * 3 / 4;
    int y2 = rect.y;
    int x3 = rect.x + rect.w;
    int y3 = rect.y + rect.h / 2;
    int x4 = rect.x + rect.w * 3 / 4;
    int y4 = rect.y + rect.h;
    int x5 = rect.x + rect.w / 4;
    int y5 = rect.y + rect.h;
    int x6 = rect.x;
    int y6 = rect.y + rect.h / 2;

    // Dessin de l'hexagone
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
    SDL_RenderDrawLine(renderer, x2, y2, x3, y3);
    SDL_RenderDrawLine(renderer, x3, y3, x4, y4);
    SDL_RenderDrawLine(renderer, x4, y4, x5, y5);
    SDL_RenderDrawLine(renderer, x5, y5, x6, y6);
    SDL_RenderDrawLine(renderer, x6, y6, x1, y1);
}

void Brick::renderTriangular(SDL_Renderer *renderer) const
{
    SDL_Color color = getColor();
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    // Calcul des coordonnées des sommets du triangle
    int x1 = rect.x + rect.w / 2;
    int y1 = rect.y;
    int x2 = rect.x;
    int y2 = rect.y + rect.h;
    int x3 = rect.x + rect.w;
    int y3 = rect.y + rect.h;

    // Dessin du triangle
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
    SDL_RenderDrawLine(renderer, x2, y2, x3, y3);
    SDL_RenderDrawLine(renderer, x3, y3, x1, y1);
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
