#ifndef PLATFORM_HPP
#define PLATFORM_HPP

#include <SDL2/SDL.h>

/**
 * @class Platform
 * @brief Represents the player-controlled platform in the game.
 */
class Platform
{
public:
    /**
     * @brief Construct a new Platform object.
     *
     * @param screen_width Width of the game screen to determine platform boundaries.
     * @param screen_height Height of the game screen to determine platform position.
     */
    Platform(int screen_width, int screen_height);

    /**
     * @brief Handles keyboard events for platform movement.
     *
     * @param e SDL_Event to handle.
     */
    void handleEvent(const SDL_Event &e);

    /**
     * @brief Moves the platform based on its current velocity and time elapsed.
     *
     * @param deltaTime Time elapsed since the last update.
     */
    void move(float deltaTime);

    /**
     * @brief Renders the platform on the screen.
     *
     * @param renderer SDL Renderer to draw the platform.
     */
    void render(SDL_Renderer *renderer) const;

    /**
     * @brief Get the SDL_Rect representing the platform's position and dimensions.
     *
     * @return SDL_Rect Rectangle of the platform.
     */
    SDL_Rect getRect() const;

    /**
     * @brief Applies a temporary malus that reduces the platform's width.
     */
    void applySmallPlatformMalus();

    /**
     * @brief Updates the platform's state, including checking and handling the malus timer.
     *
     * @param deltaTime Time elapsed since the last frame.
     */
    void update(float deltaTime);

private:
    static const int PLATFORM_VEL = 400;   ///< Velocity of the platform movement.
    static const int PLATFORM_WIDTH = 100; ///< Width of the platform.
    static const int PLATFORM_HEIGHT = 20; ///< Height of the platform.

    int screenWidth;  ///< Width of the screen to limit platform's movement.
    int screenHeight; ///< Height of the screen for positioning.
    int posX, posY;   ///< Position of the platform on the screen.
    int velX;         ///< Current horizontal velocity of the platform.

    bool smallPlatformMalus; ///< Flag to indicate if the platform is under a size-reducing malus.
    float malusTimer;        ///< Timer to track the duration of the small platform malus.
};

#endif
