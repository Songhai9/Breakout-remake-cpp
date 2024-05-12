#ifndef PLATFORM_HPP
#define PLATFORM_HPP

#include <SDL2/SDL.h>

/**
 * @brief Classe représentant la plateforme (paddle) contrôlée par le joueur.
 */
class Platform {
public:
    Platform(int x, int y, int width, int height);
    void handleInput(SDL_Event& e);
    void update();
    void render(SDL_Renderer* renderer);

private:
    SDL_Rect rect;
};

#endif // PLATFORM_H
