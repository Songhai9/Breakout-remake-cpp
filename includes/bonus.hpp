#ifndef BONUS_HPP
#define BONUS_HPP

#include <SDL2/SDL.h>

class Bonus
{
public:
    enum Type
    {
        EXTRA_LIFE,
        MULTI_BALL,
        SMALL_PLATFORM
    };

    Bonus(int x, int y, Type type);
    void move(float deltaTime);
    void render(SDL_Renderer *renderer) const;
    bool isOffScreen() const;
    SDL_Rect getRect() const;
    Type getType() const;
    static int getSize(); // Getter for BONUS_SIZE

private:
    SDL_Rect rect;
    Type type;
    static const int BONUS_SIZE = 20;
    static const int BONUS_VEL = 200; // Pixels per second
};

#endif
