#include "../includes/bonus.hpp"

Bonus::Bonus(int x, int y, Type type)
    : rect{x, y, BONUS_SIZE, BONUS_SIZE}, type(type)
{
}

void Bonus::move(float deltaTime)
{
    rect.y += BONUS_VEL * deltaTime;
}

void Bonus::render(SDL_Renderer *renderer) const
{
    switch (type)
    {
    case EXTRA_LIFE:
        SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF); // Green color for extra life bonus
        break;
    case MULTI_BALL:
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF); // Blue color for multi-ball bonus
        break;
    case SMALL_PLATFORM:
        SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF); // Red color for small platform malus
        break;
    }
    SDL_RenderFillRect(renderer, &rect);
}

bool Bonus::isOffScreen() const
{
    return rect.y > 600; // Assuming 600 is the screen height
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
