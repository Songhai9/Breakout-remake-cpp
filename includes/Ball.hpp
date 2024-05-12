#ifndef BALL_HPP
#define BALL_HPP

#include <SDL2/SDL.h>

class Ball {
public:
    Ball(SDL_Renderer* renderer, int initX, int initY);
    void update();
    void render();
    void reverseY();
    void reverseX();
    const SDL_Rect& getRect() const;
    void setVelocityX(int vx);


private:
    SDL_Renderer* renderer;
    int x, y;
    int velocityX, velocityY;
    int radius;
};

#endif
