#ifndef BALL_HPP
#define BALL_HPP

#include <SDL2/SDL.h>

/**
 * @brief Classe représentant la balle dans le jeu.
 */
class Ball {
public:
    Ball(int x, int y, int size, float velX, float velY);
    void update();
    void render(SDL_Renderer* renderer);

private:
    SDL_Rect rect;   ///< Rectangle définissant la position et la taille de la balle.
    float velocityX; ///< Vitesse horizontale de la balle.
    float velocityY; ///< Vitesse verticale de la balle.
};

#endif // BALL_H
