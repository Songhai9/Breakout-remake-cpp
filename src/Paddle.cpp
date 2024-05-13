#include "../includes/Paddle.hpp"

Paddle::Paddle(SDL_Renderer *renderer, int windowWidth, int windowHeight)
    : renderer(renderer), windowWidth(windowWidth), speed(10)
{
    rect.w = 100;                       
    rect.h = 20;                         
    rect.x = (windowWidth - rect.w) / 2;
    rect.y = windowHeight - rect.h - 30; 
}

void Paddle::update()
{
}

void Paddle::handleEvent(SDL_Event &event)
{
    if (event.type == SDL_KEYDOWN)
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_LEFT:
            rect.x -= speed;
            if (rect.x < 0)
            {
                rect.x = 0; 
            }
            break;
        case SDLK_RIGHT:
            rect.x += speed;
            if (rect.x > windowWidth - rect.w)
            {
                rect.x = windowWidth - rect.w; 
            }
            break;
        }
    }
}

void Paddle::render()
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); 
    SDL_RenderFillRect(renderer, &rect);
}

const SDL_Rect &Paddle::getRect() const
{
    return rect;
}
