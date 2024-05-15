#include "../includes/bonus.hpp"

Bonus::Bonus(int x, int y, Type type)
    : rect{x, y, BONUS_SIZE, BONUS_SIZE}, type(type)
{
}

void Bonus::move(float deltaTime)
{
    rect.y += BONUS_VEL * deltaTime;
}

/**
 * @brief Rendu du bonus sur le rendu SDL.
 * 
 * Cette fonction est utilisée pour afficher le bonus sur le rendu SDL en utilisant le rendu spécifié.
 * La couleur du bonus est déterminée par son type.
 * 
 * @param renderer Le pointeur vers le rendu SDL.
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

bool Bonus::isOffScreen() const
{
    return rect.y > 600;
}

SDL_Rect Bonus::getRect() const
{
    return rect;
}

Bonus::Type Bonus::getType() const
{
    return type;
}

int Bonus::getSize()
{
    return BONUS_SIZE;
}
