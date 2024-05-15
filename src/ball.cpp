#include "../includes/ball.hpp"
#include "../includes/brick.hpp"
#include <SDL2/SDL.h>
#include <cmath>

Ball::Ball(int screenWidth, int screenHeight)
    : screenWidth(screenWidth), screenHeight(screenHeight), x(screenWidth / 2), y(screenHeight / 2),
      dx(200), dy(200), radius(7)
{
    rect = {static_cast<int>(x - radius), static_cast<int>(y - radius), 2 * radius, 2 * radius};
}

void Ball::move(float deltaTime)
{
    x += dx * deltaTime;
    y += dy * deltaTime;


    if (x - radius < 0 || x + radius > screenWidth)
    {
        dx = -dx;
    }

    if (y - radius < 0)
    {
        dy = -dy;
    }

    rect.x = static_cast<int>(x - radius);
    rect.y = static_cast<int>(y - radius);
}

void Ball::render(SDL_Renderer *renderer) const
{
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderFillRect(renderer, &rect);
}

void Ball::checkCollisionWithPlatform(const SDL_Rect &platformRect)
{
    if (SDL_HasIntersection(&rect, &platformRect))
    {
        dy = -dy;
        y = platformRect.y - rect.h;
    }
}

/**
 * Vérifie les collisions de la balle avec les briques.
 * 
 * @param bricks Le vecteur contenant les briques.
 */
void Ball::checkCollisionWithBricks(std::vector<Brick> &bricks)
{
    for (auto &brick : bricks)
    {
        if (!brick.isDestroyed())
        {
            SDL_Rect brickRect = brick.getRect();
            if (SDL_HasIntersection(&rect, &brickRect))
            {
                brick.hit();
                if (x < brickRect.x || x > brickRect.x + brickRect.w)
                {
                    dx = -dx;
                }
                else
                {
                    dy = -dy;
                }
            }
        }
    }
}

float Ball::getY() const
{
    return y;
}

int Ball::getRadius() const
{
    return radius;
}
