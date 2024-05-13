#include "../includes/Ball.hpp"
#include <algorithm>

Ball::Ball(SDL_Renderer *renderer, int initX, int initY)
    : renderer(renderer), x(initX), y(initY), velocityX(5), velocityY(-5), radius(10) {}

void Ball::update()
{
    x += velocityX;
    y += velocityY;
    if (x < 0 || x > 800 - radius)
        velocityX = -velocityX;
    if (y < 0 || y > 600 - radius)
        velocityY = -velocityY;
}

void Ball::render()
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_Rect ballRect = {x - radius, y - radius, 2 * radius, 2 * radius};
    SDL_RenderFillRect(renderer, &ballRect);
}

void Ball::reverseY()
{
    velocityY = -velocityY;
}

void Ball::reverseX()
{
    velocityX = -velocityX;
}

const SDL_Rect &Ball::getRect() const
{
    static SDL_Rect r;
    r.x = x - radius;
    r.y = y - radius;
    r.w = 2 * radius;
    r.h = 2 * radius;
    return r;
}

void Ball::adjustOnCollisionWithPaddle(const SDL_Rect &paddleRect)
{
    reverseY();
    y = paddleRect.y - radius * 2; 
}

void Ball::adjustOnCollisionWithBrick(const SDL_Rect &brickRect)
{
    reverseY();
    if (velocityY > 0)
    {                                           
        y = brickRect.y + brickRect.h + radius; 
    }
    else
    {                                 
        y = brickRect.y - radius * 2; 
    }
}
