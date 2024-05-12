#ifndef BRICK_HPP
#define BRICK_HPP

#include <SDL2/SDL.h>

/**
 * @brief Classe représentant une brique dans le jeu.
 */
class Brick {
public:
    Brick(int x, int y, int width, int height, bool isActive);
    void render(SDL_Renderer* renderer);
    bool isActive() const;

private:
    SDL_Rect rect;   ///< Rectangle définissant la position et la taille de la brique.
    bool active;     ///< Indique si la brique est active (non détruite).
};

#endif // BRICK_H
