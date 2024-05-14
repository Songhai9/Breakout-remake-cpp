#include "../includes/platform.hpp"

Platform::Platform(int screen_width, int screen_height)
    : screenWidth(screen_width), screenHeight(screen_height), posX(screen_width / 2 - PLATFORM_WIDTH / 2), posY(screen_height - 50), velX(0), smallPlatformMalus(false), malusTimer(0)
{
}

void Platform::handleEvent(const SDL_Event &e)
{
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
    {
        switch (e.key.keysym.sym)
        {
        case SDLK_LEFT:
            velX -= PLATFORM_VEL;
            break;
        case SDLK_RIGHT:
            velX += PLATFORM_VEL;
            break;
        }
    }
    else if (e.type == SDL_KEYUP && e.key.repeat == 0)
    {
        switch (e.key.keysym.sym)
        {
        case SDLK_LEFT:
            velX += PLATFORM_VEL;
            break;
        case SDLK_RIGHT:
            velX -= PLATFORM_VEL;
            break;
        }
    }
}

void Platform::move(float deltaTime)
{
    posX += velX * deltaTime;

    if (posX < 0)
    {
        posX = 0;
    }
    else if (posX > screenWidth - PLATFORM_WIDTH)
    {
        posX = screenWidth - PLATFORM_WIDTH;
    }
}

void Platform::render(SDL_Renderer *renderer) const
{
    SDL_Rect fillRect = {posX, posY, PLATFORM_WIDTH, PLATFORM_HEIGHT};
    if (smallPlatformMalus)
    {
        fillRect.w /= 2; // Reduce width by half if malus is active
    }
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF); // Black color
    SDL_RenderFillRect(renderer, &fillRect);
}

SDL_Rect Platform::getRect() const
{
    SDL_Rect rect = {posX, posY, PLATFORM_WIDTH, PLATFORM_HEIGHT};
    if (smallPlatformMalus)
    {
        rect.w /= 2; // Adjust width if malus is active
    }
    return rect;
}

void Platform::applySmallPlatformMalus()
{
    smallPlatformMalus = true;
    malusTimer = 15.0f; // Set the malus duration to 15 seconds
}

void Platform::update(float deltaTime)
{
    if (smallPlatformMalus)
    {
        malusTimer -= deltaTime;
        if (malusTimer <= 0)
        {
            smallPlatformMalus = false; // Restore the platform size after the malus duration
        }
    }
}
