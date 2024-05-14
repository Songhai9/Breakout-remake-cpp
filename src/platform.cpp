#include "../includes/platform.hpp"

/**
 * @brief Constructeur de la classe Platform.
 *
 * @param screen_width La largeur de l'écran.
 * @param screen_height La hauteur de l'écran.
 */
Platform::Platform(int screen_width, int screen_height)
    : screenWidth(screen_width), screenHeight(screen_height), posX(screen_width / 2 - PLATFORM_WIDTH / 2), posY(screen_height - 50), velX(0), smallPlatformMalus(false), malusTimer(0)
{
}

/**
 * @brief Gère les événements de clavier pour déplacer la plateforme.
 *
 * @param e L'événement SDL.
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

/**
 * @brief Déplace la plateforme en fonction du temps écoulé.
 *
 * @param deltaTime Le temps écoulé depuis la dernière mise à jour.
 */
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

/**
 * @brief Affiche la plateforme sur l'écran.
 *
 * @param renderer Le renderer SDL.
 */
void Platform::render(SDL_Renderer *renderer) const
{
    SDL_Rect fillRect = {static_cast<int>(posX), static_cast<int>(posY), PLATFORM_WIDTH, PLATFORM_HEIGHT};
    if (smallPlatformMalus)
    {
        fillRect.w /= 2;
    }
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderFillRect(renderer, &fillRect);
}

/**
 * @brief Retourne le rectangle représentant la plateforme.
 *
 * @return Le rectangle SDL de la plateforme.
 */
SDL_Rect Platform::getRect() const
{
    SDL_Rect rect = {static_cast<int>(posX), static_cast<int>(posY), PLATFORM_WIDTH, PLATFORM_HEIGHT};
    if (smallPlatformMalus)
    {
        rect.w /= 2;
    }
    return rect;
}

/**
 * @brief Applique le malus de petite plateforme.
 */
void Platform::applySmallPlatformMalus()
{
    smallPlatformMalus = true;
    malusTimer = 15.0f;
}

/**
 * @brief Met à jour l'état de la plateforme.
 *
 * @param deltaTime Le temps écoulé depuis la dernière mise à jour.
 */
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
