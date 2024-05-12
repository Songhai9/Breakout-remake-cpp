#include "../includes/GameEngine.hpp"
#include <iostream>

/**
 * @brief Constructeur de la classe GameEngine.
 */
GameEngine::GameEngine() : window(nullptr), renderer(nullptr), isRunning(false) {}

/**
 * @brief Destructeur de la classe GameEngine.
 */
GameEngine::~GameEngine() {
    cleanUp();
}

/**
 * @brief Initialise SDL, la fenêtre et le rendu.
 * 
 * @param title Le titre de la fenêtre.
 * @param width La largeur de la fenêtre.
 * @param height La hauteur de la fenêtre.
 * @return true Si tout est initialisé correctement.
 * @return false En cas d'échec de l'initialisation.
 */
bool GameEngine::init(const std::string& title, int width, int height) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "Échec de SDL_Init(): " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    if (!window) {
        std::cout << "Échec de SDL_CreateWindow(): " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        SDL_DestroyWindow(window);
        std::cout << "Échec de SDL_CreateRenderer(): " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    if (TTF_Init() == -1) {
        std::cout << "Échec de TTF_Init(): " << TTF_GetError() << std::endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }

    isRunning = true;
    return true;
}

/**
 * @brief Exécute la boucle principale du jeu.
 */
void GameEngine::run() {
    while (isRunning) {
        handleEvents();
        update();
        render();
    }
}

/**
 * @brief Traite les événements comme les entrées clavier et la fermeture de la fenêtre.
 */
void GameEngine::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }
    }
}

/**
 * @brief Met à jour la logique du jeu.
 */
void GameEngine::update() {
    // Mettez à jour la logique du jeu ici
}

/**
 * @brief Effectue le rendu des objets du jeu à l'écran.
 */
void GameEngine::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Définir la couleur de fond à noir
    SDL_RenderClear(renderer);
    // Code de rendu va ici
    SDL_RenderPresent(renderer);
}

/**
 * @brief Nettoie et libère les ressources SDL.
 */
void GameEngine::cleanUp() {
    if (renderer) {
        SDL_DestroyRenderer(renderer);
    }
    if (window) {
        SDL_DestroyWindow(window);
    }
    TTF_Quit();
    SDL_Quit();
}
