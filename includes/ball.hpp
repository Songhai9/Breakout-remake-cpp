#ifndef BALL_HPP
#define BALL_HPP

#include <SDL2/SDL.h>
#include <vector>
#include "brick.hpp"

class Ball
{
public:
    Ball(int screenWidth, int screenHeight);
    void move(float deltaTime);
    void render(SDL_Renderer *renderer) const;
    void checkCollisionWithPlatform(const SDL_Rect &platformRect);
    void checkCollisionWithBricks(std::vector<Brick> &bricks);
    float getY() const;
    int getRadius() const; // Assurez-vous que c'est public

private:
    int screenWidth;
    int screenHeight;
    float x, y;
    float dx, dy;
    int radius;
    SDL_Rect rect;
};

#endif
