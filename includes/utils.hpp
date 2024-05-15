#ifndef UTILS_HPP
#define UTILS_HPP

#include <SDL2/SDL.h>
#include <vector>

void DrawCircle(SDL_Renderer *renderer, int centerX, int centerY, int radius);
bool checkCollision(const SDL_Rect &a, const SDL_Rect &b);
/**
 * @brief Remplit un polygone avec le rendu SDL.
 *
 * Cette fonction remplit un polygone défini par une liste de points avec le rendu SDL spécifié.
 *
 * @param renderer Le rendu SDL sur lequel le polygone sera dessiné.
 * @param points   La liste des points définissant le polygone.
 */
void fillPolygon(SDL_Renderer *renderer, const std::vector<SDL_Point> &points);

#endif
