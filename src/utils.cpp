#include "../includes/utils.hpp"
#include <cmath>
#include <iostream>
#include <algorithm>

/**
 * @brief Dessine un cercle à l'écran.
 *
 * @param renderer Le renderer SDL.
 * @param centerX La position x du centre du cercle.
 * @param centerY La position y du centre du cercle.
 * @param radius Le rayon du cercle.
 */
void DrawCircle(SDL_Renderer *renderer, int centerX, int centerY, int radius)
{
    for (int w = 0; w < radius * 2; w++)
    {
        for (int h = 0; h < radius * 2; h++)
        {
            int dx = radius - w;
            int dy = radius - h;
            if ((dx * dx + dy * dy) <= (radius * radius))
            {
                SDL_RenderDrawPoint(renderer, centerX + dx, centerY + dy);
            }
        }
    }
}

/**
 * @brief Vérifie la collision entre deux rectangles.
 *
 * @param a Le premier rectangle SDL.
 * @param b Le deuxième rectangle SDL.
 * @return True si les rectangles se chevauchent, false sinon.
 */
bool checkCollision(const SDL_Rect &a, const SDL_Rect &b)
{
    if (a.x + a.w <= b.x || b.x + b.w <= a.x || a.y + a.h <= b.y || b.y + b.h <= a.y)
    {
        return false;
    }
    return true;
}

/**
 * @brief Remplit un polygone à l'écran.
 *
 * @param renderer Le renderer SDL.
 * @param points Un vecteur de points SDL représentant le polygone.
 */
void fillPolygon(SDL_Renderer *renderer, const std::vector<SDL_Point> &points)
{
    if (points.size() < 3)
        return;

    auto [minY, maxY] = std::minmax_element(points.begin(), points.end(), [](const SDL_Point &a, const SDL_Point &b)
                                            { return a.y < b.y; });

    for (int y = minY->y; y <= maxY->y; ++y)
    {
        std::vector<int> nodeX;
        size_t j = points.size() - 1;
        for (size_t i = 0; i < points.size(); ++i)
        {
            if ((points[i].y < y && points[j].y >= y) || (points[j].y < y && points[i].y >= y))
            {
                nodeX.push_back(points[i].x + (y - points[i].y) * (points[j].x - points[i].x) / (points[j].y - points[i].y));
            }
            j = i;
        }
        std::sort(nodeX.begin(), nodeX.end());
        for (size_t i = 0; i < nodeX.size(); i += 2)
        {
            if (i + 1 < nodeX.size())
            {
                SDL_RenderDrawLine(renderer, nodeX[i], y, nodeX[i + 1], y);
            }
        }
    }
}
