#include "../includes/utils.hpp"
#include <SDL2/SDL.h>
#include <algorithm>
#include <vector>

// Définition simplifiée de DrawCircle
void DrawCircle(SDL_Renderer *renderer, int x, int y, int radius)
{
    for (int w = 0; w < radius * 2; w++)
    {
        for (int h = 0; h < radius * 2; h++)
        {
            int dx = radius - w; // horizontal offset
            int dy = radius - h; // vertical offset
            if ((dx * dx + dy * dy) <= (radius * radius))
            {
                SDL_RenderDrawPoint(renderer, x + dx, y + dy);
            }
        }
    }
}

// Définition simplifiée de checkCollision
bool checkCollision(const SDL_Rect &a, const SDL_Rect &b)
{
    // Vérifie si les rectangles se chevauchent
    if (a.x + a.w < b.x || a.x > b.x + b.w)
        return false;
    if (a.y + a.h < b.y || a.y > b.y + b.h)
        return false;
    return true;
}


void fillPolygon(SDL_Renderer* renderer, const std::vector<SDL_Point>& points) {
    if (points.size() < 3) return; // A polygon must have at least 3 points

    // Find the top and bottom of the polygon
    auto [minY, maxY] = std::minmax_element(points.begin(), points.end(), [](const SDL_Point& a, const SDL_Point& b) {
        return a.y < b.y;
    });

    for (int y = minY->y; y <= maxY->y; ++y) {
        std::vector<int> nodeX;
        size_t j = points.size() - 1;
        for (size_t i = 0; i < points.size(); ++i) {
            if ((points[i].y < y && points[j].y >= y) || (points[j].y < y && points[i].y >= y)) {
                nodeX.push_back(points[i].x + (y - points[i].y) * (points[j].x - points[i].x) / (points[j].y - points[i].y));
            }
            j = i;
        }
        std::sort(nodeX.begin(), nodeX.end());
        for (size_t i = 0; i < nodeX.size(); i += 2) {
            if (i + 1 < nodeX.size()) {
                SDL_RenderDrawLine(renderer, nodeX[i], y, nodeX[i + 1], y);
            }
        }
    }
}