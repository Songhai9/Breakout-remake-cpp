#include "../includes/Brick.hpp"

Brick::Brick(SDL_Renderer *renderer, int x, int y, int w, int h, int hitsRequired)
    : renderer(renderer), rect{x, y, w, h}, hitsLeft(hitsRequired), destroyed(false)
{
    setColor(); // Initialize the color based on hits required
}

void Brick::setColor()
{
    switch (hitsLeft)
    {
    case 3:
        color = {255, 0, 0, 255}; // Red
        break;
    case 2:
        color = {255, 165, 0, 255}; // Orange
        break;
    case 1:
        color = {255, 255, 0, 255}; // Yellow
        break;
    default:
        color = {255, 255, 255, 255}; // Default to white (or could be invisible/transparent)
    }
}

void Brick::render()
{
    if (!destroyed)
    {
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
        SDL_RenderFillRect(renderer, &rect);
    }
}

bool Brick::checkCollision(const SDL_Rect &ballRect)
{
    if (!destroyed && SDL_HasIntersection(&ballRect, &rect))
    {
        hitsLeft--;
        if (hitsLeft <= 0)
        {
            destroyed = true; // Brick is destroyed when hitsLeft is 0 or less
        }
        else
        {
            setColor(); // Update the color based on the new hitsLeft value
        }
        return true; // Return true if collision occurs, regardless of destruction
    }
    return false; // Return false if no collision occurs
}

const SDL_Rect &Brick::getRect() const
{
    return rect;
}

bool Brick::isDestroyed() const
{
    return destroyed;
}
