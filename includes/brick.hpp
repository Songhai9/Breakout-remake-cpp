#ifndef BRICK_HPP
#define BRICK_HPP

#include <SDL2/SDL.h>

/**
 * @class Brick
 * @brief Represents a brick in the game, handling its rendering and state.
 */
class Brick
{
public:
    /**
     * @brief Construct a new Brick object.
     *
     * @param x X position of the brick.
     * @param y Y position of the brick.
     * @param width Width of the brick.
     * @param height Height of the brick.
     * @param hitPoints Number of hits the brick can take before being destroyed.
     */
    Brick(int x, int y, int width, int height, int hitPoints);

    /**
     * @brief Renders the brick on the screen.
     *
     * @param renderer SDL Renderer to draw the brick.
     */
    void render(SDL_Renderer *renderer) const;

    /**
     * @brief Renders the brick with a hexagonal shape.
     *
     * @param renderer SDL Renderer to draw the brick.
     */
    void renderHexagonal(SDL_Renderer *renderer) const;

    /**
     * @brief Renders the brick with a triangular shape.
     *
     * @param renderer SDL Renderer to draw the brick.
     */
    void renderTriangular(SDL_Renderer *renderer) const;

    /**
     * @brief Records a hit to the brick, reducing its hit points and possibly marking it as destroyed.
     */
    void hit();

    /**
     * @brief Checks if the brick is destroyed.
     *
     * @return true If the brick is destroyed.
     * @return false Otherwise.
     */
    bool isDestroyed() const;

    /**
     * @brief Checks if the brick has been hit.
     *
     * @return true If the brick was hit.
     * @return false Otherwise.
     */
    bool isHit() const;

    /**
     * @brief Checks if the brick was just destroyed in the last update.
     *
     * @return true If the brick was just destroyed.
     * @return false Otherwise.
     */
    bool wasJustDestroyed();

    /**
     * @brief Resets the hit flag after handling the brick hit state.
     */
    void resetHitFlag();

    /**
     * @brief Get the rectangle representing the brick's position and dimensions.
     *
     * @return SDL_Rect The rectangle of the brick.
     */
    SDL_Rect getRect() const;

private:
    SDL_Color getColor() const; ///< Helper function to determine the color based on hit points.
    SDL_Rect rect;              ///< SDL rectangle defining the brick's position and size.
    int hitPoints;              ///< Remaining hit points of the brick.
    bool hitFlag;               ///< Flag indicating if the brick was hit in the current frame.
    bool destroyedFlag;         ///< Flag indicating if the brick is destroyed.
};

#endif
