#include "../includes/platform.hpp"

Platform::Platform(int screen_width, int screen_height)
    : screenWidth(screen_width), screenHeight(screen_height), posX(screen_width / 2 - PLATFORM_WIDTH / 2), posY(screen_height - 50), velX(0), smallPlatformMalus(false), malusTimer(0)
{
}

/**
 * @brief Gère les événements liés à la plateforme.
 * 
 * Cette fonction est appelée pour traiter les événements SDL liés à la plateforme.
 * Elle met à jour la vitesse de déplacement de la plateforme en fonction des touches
 * fléchées gauche et droite enfoncées ou relâchées.
 * 
 * @param e L'événement SDL à traiter.
 */
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
        fillRect.w /= 2;
    }
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderFillRect(renderer, &fillRect);
}

SDL_Rect Platform::getRect() const
{
    SDL_Rect rect = {posX, posY, PLATFORM_WIDTH, PLATFORM_HEIGHT};
    if (smallPlatformMalus)
    {
        rect.w /= 2;
    }
    return rect;
}

void Platform::applySmallPlatformMalus()
{
    smallPlatformMalus = true;
    malusTimer = 15.0f;
}

void Platform::update(float deltaTime)
{
    if (smallPlatformMalus)
    {
        malusTimer -= deltaTime;
        if (malusTimer <= 0)
        {
            smallPlatformMalus = false;
        }
    }
}
