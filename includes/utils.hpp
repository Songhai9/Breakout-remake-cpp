#ifndef UTILS_HPP
#define UTILS_HPP

#include <SDL2/SDL.h>
#include <vector>

/**
 * @file utils.hpp
 * @brief Utility functions to assist in rendering complex shapes and checking collisions.
 */

/**
 * @brief Draws a circle on the renderer at the specified location.
 *
 * @param renderer The SDL_Renderer to draw on.
 * @param centerX The x-coordinate of the circle's center.
 * @param centerY The y-coordinate of the circle's center.
 * @param radius The radius of the circle.
 */
void DrawCircle(SDL_Renderer *renderer, int centerX, int centerY, int radius);

/**
 * @brief Checks if two rectangles overlap (collision detection).
 *
 * @param a The first rectangle.
 * @param b The second rectangle.
 * @return true If the rectangles overlap.
 * @return false Otherwise.
 */
bool checkCollision(const SDL_Rect &a, const SDL_Rect &b);

/**
 * @brief Fills a polygon defined by a vector of SDL_Points.
 *
 * @param renderer The SDL_Renderer to draw on.
 * @param points The vector of points defining the polygon.
 */
void fillPolygon(SDL_Renderer *renderer, const std::vector<SDL_Point> &points);

#endif
