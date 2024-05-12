#include "../includes/Platform.hpp"

/**
 * @brief Constructeur de la classe Platform.
 * 
 * @param x Position X initiale de la plateforme.
 * @param y Position Y initiale de la plateforme.
 * @param width Largeur de la plateforme.
 * @param height Hauteur de la plateforme.
 */
Platform::Platform(int x, int y, int width, int height) {
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;
}

/**
 * @brief Gère les entrées du clavier pour déplacer la plateforme.
 * 
 * @param e Événement SDL.
 */
void Platform::handleInput(SDL_Event& e) {
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
    if (currentKeyStates[SDL_SCANCODE_LEFT]) {
        rect.x -= 10; // Déplacement à gauche
    }
    if (currentKeyStates[SDL_SCANCODE_RIGHT]) {
        rect.x += 10; // Déplacement à droite
    }
}

/**
 * @brief Met à jour la logique de la plateforme.
 */
void Platform::update() {
    // Ajouter la logique de contrainte ou de collision ici si nécessaire
}

/**
 * @brief Affiche la plateforme à l'écran.
 * 
 * @param renderer Rendu SDL.
 */
void Platform::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);  // Blanc
    SDL_RenderFillRect(renderer, &rect);
}
