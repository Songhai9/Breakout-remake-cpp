#include "../includes/utils.hpp"
#include <algorithm>

void fillPolygon(SDL_Renderer *renderer, const std::vector<SDL_Point> &points)
{
    if (points.size() < 3)
        return; // A polygon must have at least 3 points

    // Find the top and bottom of the polygon
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
