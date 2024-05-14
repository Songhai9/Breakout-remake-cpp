#include "../includes/brick.hpp"
#include "../includes/utils.hpp"
#include <vector>

/**
 * @brief Constructeur de la classe Brick.
 *
 * @param x Position x de la brique.
 * @param y Position y de la brique.
 * @param width Largeur de la brique.
 * @param height Hauteur de la brique.
 * @param hitPoints Points de vie de la brique.
 */
Brick::Brick(int x, int y, int width, int height, int hitPoints)
    : rect{x, y, width, height}, hitPoints(hitPoints), hitFlag(false), destroyedFlag(false)
{
}

/**
 * @brief Affiche la brique sur l'écran.
 *
 * @param renderer Le renderer SDL.
 */
void Brick::render(SDL_Renderer *renderer) const
{
    SDL_Color color = getColor();
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);
}

/**
 * @brief Affiche une brique hexagonale sur l'écran.
 *
 * @param renderer Le renderer SDL.
 */
void Brick::renderHexagonal(SDL_Renderer *renderer) const
{
    SDL_Color color = getColor();
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    const int hexWidth = rect.w;
    const int r = hexWidth / 2;
    const int h = static_cast<int>(r * sqrt(3) / 2);

    std::vector<SDL_Point> points = {
        {rect.x + r / 2, rect.y},
        {rect.x + 3 * r / 2, rect.y},
        {rect.x + 2 * r, rect.y + h},
        {rect.x + 3 * r / 2, rect.y + 2 * h},
        {rect.x + r / 2, rect.y + 2 * h},
        {rect.x, rect.y + h},
        {rect.x + r / 2, rect.y}};

    SDL_RenderDrawLines(renderer, points.data(), points.size());
    fillPolygon(renderer, points);
}

/**
 * @brief Affiche une brique triangulaire sur l'écran.
 *
 * @param renderer Le renderer SDL.
 */
void Brick::renderTriangular(SDL_Renderer *renderer) const
{
    SDL_Color color = getColor();
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    std::vector<SDL_Point> points = {
        {rect.x, rect.y + rect.h},
        {rect.x + rect.w / 2, rect.y},
        {rect.x + rect.w, rect.y + rect.h},
        {rect.x, rect.y + rect.h}};

    SDL_RenderDrawLines(renderer, points.data(), points.size());
    fillPolygon(renderer, points);
}

/**
 * @brief Inflige un coup à la brique, réduisant ses points de vie.
 */
void Brick::hit()
{
    if (hitPoints > 0)
    {
        hitPoints--;
        hitFlag = true;
        if (hitPoints == 0)
        {
            destroyedFlag = true;
        }
    }
}

/**
 * @brief Vérifie si la brique est détruite.
 *
 * @return True si la brique est détruite, false sinon.
 */
bool Brick::isDestroyed() const
{
    return hitPoints <= 0;
}

/**
 * @brief Vérifie si la brique a été touchée.
 *
 * @return True si la brique a été touchée, false sinon.
 */
bool Brick::isHit() const
{
    return hitFlag;
}

/**
 * @brief Vérifie si la brique vient juste d'être détruite.
 *
 * @return True si la brique vient juste d'être détruite, false sinon.
 */
bool Brick::wasJustDestroyed()
{
    if (destroyedFlag)
    {
        destroyedFlag = false;
        return true;
    }
    return false;
}

/**
 * @brief Réinitialise le drapeau de coup de la brique.
 */
void Brick::resetHitFlag()
{
    hitFlag = false;
}

/**
 * @brief Retourne le rectangle représentant la brique.
 *
 * @return Le rectangle SDL de la brique.
 */
SDL_Rect Brick::getRect() const
{
    return rect;
}

/**
 * @brief Retourne la couleur de la brique en fonction de ses points de vie.
 *
 * @return La couleur SDL de la brique.
 */
SDL_Color Brick::getColor() const
{
    switch (hitPoints)
    {
    case 3:
        return {0x33, 0x33, 0x33, 0xFF};
    case 2:
        return {0x66, 0x66, 0x66, 0xFF};
    case 1:
        return {0x99, 0x99, 0x99, 0xFF};
    default:
        return {0x00, 0xFF, 0x00, 0xFF};
    }
}
