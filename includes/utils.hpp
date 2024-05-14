#ifndef UTILS_HPP
#define UTILS_HPP

#include <SDL2/SDL.h>
#include <vector>

/**
 * @brief Dessine un cercle à l'écran.
 *
 * @param renderer Le renderer SDL.
 * @param centerX La position x du centre du cercle.
 * @param centerY La position y du centre du cercle.
 * @param radius Le rayon du cercle.
 */
void DrawCircle(SDL_Renderer *renderer, int centerX, int centerY, int radius);

/**
 * @brief Vérifie la collision entre deux rectangles.
 *
 * @param a Le premier rectangle SDL.
 * @param b Le deuxième rectangle SDL.
 * @return True si les rectangles se chevauchent, false sinon.
 */
bool checkCollision(const SDL_Rect &a, const SDL_Rect &b);

/**
 * @brief Remplit un polygone à l'écran.
 *
 * @param renderer Le renderer SDL.
 * @param points Un vecteur de points SDL représentant le polygone.
 */
void fillPolygon(SDL_Renderer *renderer, const std::vector<SDL_Point> &points);

#endif
