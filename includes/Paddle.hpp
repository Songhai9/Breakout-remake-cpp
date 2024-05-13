#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <SDL2/SDL.h>

class Paddle
{
public:
    Paddle(SDL_Renderer *renderer, int windowWidth, int windowHeight);
    void update();
    void render();
    void handleEvent(SDL_Event &event);
    const SDL_Rect &getRect() const;

private:
    SDL_Renderer *renderer;
    SDL_Rect rect;
    int windowWidth;
    int speed;
};

#endif
