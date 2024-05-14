#ifndef PLATFORM_HPP
#define PLATFORM_HPP

#include <SDL2/SDL.h>

class Platform
{
public:
    Platform(int screen_width, int screen_height);
    void handleEvent(const SDL_Event &e);
    void move(float deltaTime);
    void render(SDL_Renderer *renderer) const;
    SDL_Rect getRect() const;
    void applySmallPlatformMalus(); // Apply small platform malus
    void update(float deltaTime);   // Update method to handle malus duration

private:
    static const int PLATFORM_VEL = 400; // Pixels per second
    static const int PLATFORM_WIDTH = 100;
    static const int PLATFORM_HEIGHT = 20;

    int screenWidth;
    int screenHeight;
    int posX, posY;
    int velX;

    bool smallPlatformMalus;
    float malusTimer;
};

#endif
