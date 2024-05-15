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

/**
 * \brief Rendre un hexagone pour la brique.
 *
 * Cette fonction rend un hexagone pour la brique en utilisant le rendu SDL.
 *
 * \param renderer Le pointeur vers le rendu SDL.
 */
void Brick::renderHexagonal(SDL_Renderer *renderer) const
{
    SDL_Color color = getColor();
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    const int hexWidth = rect.w;
    const int r = hexWidth / 2;
    const int h = static_cast<int>(r * sqrt(3) / 2); 

    std::vector<SDL_Point> points = {
        {rect.x + r / 2, rect.y},
        {rect.x + 3 * r / 2, rect.y},
        {rect.x + 2 * r, rect.y + h},
        {rect.x + 3 * r / 2, rect.y + 2 * h},
        {rect.x + r / 2, rect.y + 2 * h},
        {rect.x, rect.y + h},
        {rect.x + r / 2, rect.y}};

    SDL_RenderDrawLines(renderer, points.data(), points.size());
    fillPolygon(renderer, points);
}

void Brick::renderTriangular(SDL_Renderer *renderer) const
{
    SDL_Color color = getColor();
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    std::vector<SDL_Point> points = {
        {rect.x, rect.y + rect.h},
        {rect.x + rect.w / 2, rect.y},
        {rect.x + rect.w, rect.y + rect.h},
        {rect.x, rect.y + rect.h}};

    SDL_RenderDrawLines(renderer, points.data(), points.size());
    fillPolygon(renderer, points);
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
        return {0x33, 0x33, 0x33, 0xFF}; // Darker shade for 3-hit bricks
    case 2:
        return {0x66, 0x66, 0x66, 0xFF}; // Medium shade for 2-hit bricks
    case 1:
        return {0x99, 0x99, 0x99, 0xFF}; // Lighter shade for 1-hit bricks
    default:
        return {0x99, 0x99, 0x99, 0xFF}; // Lighter shade for 1-hit bricks
    }
}
