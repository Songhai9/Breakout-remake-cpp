#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

/**
 * @brief Classe gérant le moteur de jeu principal.
 * 
 * Cette classe initialise SDL, gère la boucle de jeu, traite les événements
 * et gère le nettoyage à la fin.
 */
class GameEngine {
public:
    GameEngine();
    ~GameEngine();

    /**
     * @brief Initialise le moteur de jeu, crée une fenêtre et un rendu.
     * 
     * @param title Titre de la fenêtre.
     * @param width Largeur de la fenêtre.
     * @param height Hauteur de la fenêtre.
     * @return true Si l'initialisation réussit.
     * @return false Si l'initialisation échoue.
     */
    bool init(const std::string& title, int width, int height);

    /**
     * @brief Démarre la boucle principale du jeu.
     */
    void run();

private:
    SDL_Window* window;       ///< Pointeur vers la fenêtre SDL.
    SDL_Renderer* renderer;   ///< Pointeur vers le rendu SDL.
    bool isRunning;           ///< État d'exécution du moteur de jeu.

    /**
     * @brief Gère les événements d'entrée.
     */
    void handleEvents();

    /**
     * @brief Met à jour la logique du jeu.
     */
    void update();

    /**
     * @brief Affiche le contenu à l'écran.
     */
    void render();

    /**
     * @brief Nettoie et libère les ressources.
     */
    void cleanUp();
};

#endif // GAME_ENGINE_HPP
