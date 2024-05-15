#ifndef BALL_HPP
#define BALL_HPP

#include <SDL2/SDL.h>
#include <vector>
#include "brick.hpp"

/**
 * @class Ball
 * @brief Represents the ball used in the game, handling its movement and interactions.
 */
class Ball
{
public:
    /**
     * @brief Construct a new Ball object.
     *
     * @param screenWidth Width of the screen to bound ball movement.
     * @param screenHeight Height of the screen to bound ball movement.
     */
    Ball(int screenWidth, int screenHeight);

    /**
     * @brief Moves the ball based on time elapsed.
     *
     * @param deltaTime Time elapsed since the last frame.
     */
    void move(float deltaTime);

    /**
     * @brief Renders the ball on the screen.
     *
     * @param renderer SDL Renderer to draw the ball.
     */
    void render(SDL_Renderer *renderer) const;

    /**
     * @brief Checks and handles collision with the platform.
     *
     * @param platformRect SDL_Rect representing the platform.
     */
    void checkCollisionWithPlatform(const SDL_Rect &platformRect);

    /**
     * @brief Checks and handles collision with bricks.
     *
     * @param bricks Vector of bricks to check collisions against.
     */
    void checkCollisionWithBricks(std::vector<Brick> &bricks);

    /**
     * @brief Get the Y position of the ball.
     *
     * @return float Y coordinate of the ball.
     */
    float getY() const;

    /**
     * @brief Get the radius of the ball.
     *
     * @return int Radius of the ball.
     */
    int getRadius() const;

private:
    int screenWidth;
    int screenHeight;
    float x, y;
    float dx, dy;
    int radius;
    SDL_Rect rect;
};

#endif
