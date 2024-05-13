#ifndef BONUS_HPP
#define BONUS_HPP

#include "SDL.h"

class Bonus {
public:
    SDL_Rect rect;
    bool active;
    void (*effect)(void);

    Bonus(int x, int y, void (*effectFunc)(void)) : rect{x, y, 32, 32}, active(true), effect(effectFunc) {}

    void update() {
        rect.y += 2; // Fall speed
        if (rect.y > 600) active = false; // Disappear if it hits the bottom
    }

    void activate() {
        effect();
        active = false;
    }
};

#endif // BONUS_HPP
