#ifndef BONUS_HPP
#define BONUS_HPP

#include <SDL2/SDL.h>

/**
 * @class Bonus
 * @brief Represents a bonus item that can be collected during the game.
 */
class Bonus
{
public:
    /**
     * @enum Type
     * @brief Types of bonuses that can affect gameplay.
     */
    enum Type
    {
        EXTRA_LIFE,    ///< Grants an extra life.
        MULTI_BALL,    ///< Adds additional balls to the game.
        SMALL_PLATFORM ///< Reduces the platform size temporarily.
    };

    /**
     * @brief Construct a new Bonus object.
     *
     * @param x X position of the bonus.
     * @param y Y position of the bonus.
     * @param type Type of the bonus.
     */
    Bonus(int x, int y, Type type);

    /**
     * @brief Moves the bonus downwards.
     *
     * @param deltaTime Time elapsed since the last frame.
     */
    void move(float deltaTime);

    /**
     * @brief Renders the bonus on the screen.
     *
     * @param renderer SDL Renderer to draw the bonus.
     */
    void render(SDL_Renderer *renderer) const;

    /**
     * @brief Checks if the bonus has moved off the screen.
     *
     * @return true If the bonus is off the screen.
     * @return false Otherwise.
     */
    bool isOffScreen() const;

    /**
     * @brief Get the SDL_Rect representing the bonus.
     *
     * @return SDL_Rect Rectangle of the bonus.
     */
    SDL_Rect getRect() const;

    /**
     * @brief Get the Type of the bonus.
     *
     * @return Type Type of the bonus.
     */
    Type getType() const;

    /**
     * @brief Get the Size of the bonus.
     *
     * @return int Size of the bonus.
     */
    static int getSize();

private:
    SDL_Rect rect;
    Type type;
    static const int BONUS_SIZE = 20;
    static const int BONUS_VEL = 200;
};

#endif
