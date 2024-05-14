#include "../includes/bonus.hpp"

/**
 * @brief Constructeur de la classe Bonus.
 *
 * @param x Position x du bonus.
 * @param y Position y du bonus.
 * @param type Type du bonus.
 */
Bonus::Bonus(int x, int y, Type type)
    : rect{x, y, BONUS_SIZE, BONUS_SIZE}, type(type)
{
}

/**
 * @brief Déplace le bonus en fonction du temps écoulé.
 *
 * @param deltaTime Le temps écoulé depuis la dernière mise à jour.
 */
void Bonus::move(float deltaTime)
{
    rect.y += BONUS_VEL * deltaTime;
}

/**
 * @brief Affiche le bonus sur l'écran.
 *
 * @param renderer Le renderer SDL.
 */
void Bonus::render(SDL_Renderer *renderer) const
{
    switch (type)
    {
    case EXTRA_LIFE:
        SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
        break;
    case MULTI_BALL:
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
        break;
    case SMALL_PLATFORM:
        SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
        break;
    }
    SDL_RenderFillRect(renderer, &rect);
}

/**
 * @brief Vérifie si le bonus est hors de l'écran.
 *
 * @return True si le bonus est hors de l'écran, false sinon.
 */
bool Bonus::isOffScreen() const
{
    return rect.y > 600;
}

/**
 * @brief Retourne le rectangle représentant le bonus.
 *
 * @return Le rectangle SDL du bonus.
 */
SDL_Rect Bonus::getRect() const
{
    return rect;
}

/**
 * @brief Retourne le type du bonus.
 *
 * @return Le type du bonus.
 */
Bonus::Type Bonus::getType() const
{
    return type;
}

/**
 * @brief Retourne la taille du bonus.
 *
 * @return La taille du bonus.
 */
int Bonus::getSize()
{
    return BONUS_SIZE;
}
