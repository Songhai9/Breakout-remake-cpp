#ifndef BALL_HPP
#define BALL_HPP

#include <SDL2/SDL.h>
#include <vector>
#include "brick.hpp"

class Ball
{
public:
    Ball(int screen_width, int screen_height);
    void move(float deltaTime);
    void render(SDL_Renderer *renderer) const;
    void reset();
    void checkCollisionWithPlatform(const SDL_Rect &platformRect);
    void checkCollisionWithBricks(std::vector<Brick> &bricks);
    float getY() const;
    static const int BALL_SIZE = 15; // Make this public

private:
    int screenWidth;
    int screenHeight;
    static const int BALL_VEL = 300; // Pixels per second

    float posX, posY;
    float velX, velY;

    void reflectOnPlatformCollision(const SDL_Rect &platformRect);
};

#endif
