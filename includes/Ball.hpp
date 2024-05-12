#ifndef BALL_HPP
#define BALL_HPP

#include <SDL2/SDL.h>

class Ball {
public:
    Ball(SDL_Renderer* renderer, int initX, int initY);
    void update();
    void render();
    void reverseY();
    const SDL_Rect& getRect() const;

private:
    SDL_Renderer* renderer;
    int x, y;
    int velocityX, velocityY;
    int radius;
};

#endif
