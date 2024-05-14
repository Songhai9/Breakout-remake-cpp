#ifndef UTILS_HPP
#define UTILS_HPP

#include <SDL2/SDL.h>
#include <vector>

void DrawCircle(SDL_Renderer *renderer, int centerX, int centerY, int radius);

bool checkCollision(const SDL_Rect &a, const SDL_Rect &b);

void fillPolygon(SDL_Renderer* renderer, const std::vector<SDL_Point>& points);

#endif
