#include "../includes/ball.hpp"
#include "../includes/utils.hpp"
#include <cstdlib>
#include <cmath>

Ball::Ball(int screen_width, int screen_height)
    : screenWidth(screen_width), screenHeight(screen_height)
{
    reset();
}

void Ball::move(float deltaTime)
{
    posX += velX * deltaTime;
    posY += velY * deltaTime;

    // Bounce off the left and right walls
    if (posX <= 0 || posX + BALL_SIZE >= screenWidth)
    {
        velX = -velX;
    }

    // Bounce off the top wall
    if (posY <= 0)
    {
        velY = -velY;
    }
}

void Ball::render(SDL_Renderer *renderer) const
{
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF); // Red color
    DrawCircle(renderer, static_cast<int>(posX + BALL_SIZE / 2), static_cast<int>(posY + BALL_SIZE / 2), BALL_SIZE / 2);
}

void Ball::reset()
{
    posX = screenWidth / 2.0f - BALL_SIZE / 2.0f;
    posY = screenHeight / 2.0f - BALL_SIZE / 2.0f;
    velX = BALL_VEL * ((rand() % 2 == 0) ? 1 : -1); // Random initial direction
    velY = -BALL_VEL;
}

void Ball::checkCollisionWithPlatform(const SDL_Rect &platformRect)
{
    SDL_Rect ballRect = {static_cast<int>(posX), static_cast<int>(posY), BALL_SIZE, BALL_SIZE};
    if (checkCollision(ballRect, platformRect))
    {
        reflectOnPlatformCollision(platformRect);
    }
}

void Ball::reflectOnPlatformCollision(const SDL_Rect &platformRect)
{
    float relativeIntersectX = (posX + (BALL_SIZE / 2)) - (platformRect.x + (platformRect.w / 2));
    float normalizedRelativeIntersectionX = (relativeIntersectX / (platformRect.w / 2));
    float bounceAngle = normalizedRelativeIntersectionX * (M_PI / 4); // Max bounce angle of 45 degrees

    velX = BALL_VEL * sin(bounceAngle);
    velY = -BALL_VEL * cos(bounceAngle);
}

void Ball::checkCollisionWithBricks(std::vector<Brick> &bricks)
{
    SDL_Rect ballRect = {static_cast<int>(posX), static_cast<int>(posY), BALL_SIZE, BALL_SIZE};
    for (auto &brick : bricks)
    {
        if (!brick.isDestroyed() && checkCollision(ballRect, brick.getRect()))
        {
            // Calculate the collision angle
            if ((posX + BALL_SIZE - 1 < brick.getRect().x) || (posX + 1 > brick.getRect().x + brick.getRect().w))
            {
                velX = -velX;
            }
            else
            {
                velY = -velY;
            }
            brick.hit();
            break; // Only handle one collision per frame for simplicity
        }
    }
}

float Ball::getY() const
{
    return posY;
}
