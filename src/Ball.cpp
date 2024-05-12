#include "../includes/Ball.hpp"

/**
 * @brief Constructeur de la classe Ball.
 * 
 * @param x Position X initiale de la balle.
 * @param y Position Y initiale de la balle.
 * @param size Taille de la balle.
 * @param velX Vitesse initiale horizontale.
 * @param velY Vitesse initiale verticale.
 */
Ball::Ball(int x, int y, int size, float velX, float velY) {
    rect.x = x;
    rect.y = y;
    rect.w = size;
    rect.h = size;
    velocityX = velX;
    velocityY = velY;
}

/**
 * @brief Met à jour la position de la balle en fonction de sa vitesse.
 * Gère les collisions avec les limites de la fenêtre.
 */
void Ball::update() {
    rect.x += static_cast<int>(velocityX);
    rect.y += static_cast<int>(velocityY);

    // Collision avec les limites de la fenêtre
    if (rect.x <= 0 || rect.x + rect.w >= 620) { // Supposer largeur de 620 pour la fenêtre
        velocityX = -velocityX; // Inverser la vitesse horizontale
    }
    if (rect.y <= 0 || rect.y + rect.h >= 480) { // Supposer hauteur de 480 pour la fenêtre
        velocityY = -velocityY; // Inverser la vitesse verticale
    }
}

/**
 * @brief Affiche la balle à l'écran.
 * 
 * @param renderer Rendu SDL pour dessiner la balle.
 */
void Ball::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Couleur rouge
    SDL_RenderFillRect(renderer, &rect);
}
