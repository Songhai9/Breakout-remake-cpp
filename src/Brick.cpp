#include "../includes/Brick.hpp"

/**
 * @brief Constructeur de la classe Brick.
 * 
 * @param x Position X de la brique.
 * @param y Position Y de la brique.
 * @param width Largeur de la brique.
 * @param height Hauteur de la brique.
 * @param isActive État initial de la brique (active ou non).
 */
Brick::Brick(int x, int y, int width, int height, bool isActive) {
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;
    active = isActive;
}

/**
 * @brief Affiche la brique à l'écran si elle est active.
 * 
 * @param renderer Rendu SDL pour dessiner la brique.
 */
void Brick::render(SDL_Renderer* renderer) {
    if (!active) return;

    SDL_SetRenderDrawColor(renderer, 255, 165, 0, 255); // Couleur orange pour la brique
    SDL_RenderFillRect(renderer, &rect);
}

/**
 * @brief Retourne l'état de la brique.
 * 
 * @return true Si la brique est active.
 * @return false Si la brique est détruite.
 */
bool Brick::isActive() const {
    return active;
}
