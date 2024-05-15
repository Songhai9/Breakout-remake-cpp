#ifndef PLATFORM_HPP
#define PLATFORM_HPP

#include <SDL2/SDL.h>

/**
 * @class Platform
 * @brief Représente la plateforme contrôlée par le joueur dans le jeu.
 */
class Platform
{
public:
    /**
     * @brief Construit un nouvel objet Platform.
     *
     * @param screen_width Largeur de l'écran de jeu pour déterminer les limites de la plateforme.
     * @param screen_height Hauteur de l'écran de jeu pour positionner la plateforme.
     */
    Platform(int screen_width, int screen_height);

    /**
     * @brief Gère les événements clavier pour le mouvement de la plateforme.
     *
     * @param e SDL_Event à gérer.
     */
    void handleEvent(const SDL_Event &e);

    /**
     * @brief Déplace la plateforme en fonction de sa vitesse actuelle et du temps écoulé.
     *
     * @param deltaTime Temps écoulé depuis la dernière mise à jour.
     */
    void move(float deltaTime);

    /**
     * @brief Affiche la plateforme à l'écran.
     *
     * @param renderer SDL Renderer pour dessiner la plateforme.
     */
    void render(SDL_Renderer *renderer) const;

    /**
     * @brief Obtient le SDL_Rect représentant la position et les dimensions de la plateforme.
     *
     * @return SDL_Rect Rectangle de la plateforme.
     */
    SDL_Rect getRect() const;

    /**
     * @brief Applique un malus temporaire qui réduit la largeur de la plateforme.
     */
    void applySmallPlatformMalus();

    /**
     * @brief Met à jour l'état de la plateforme, y compris la vérification et la gestion de la minuterie du malus.
     *
     * @param deltaTime Temps écoulé depuis la dernière image.
     */
    void update(float deltaTime);

private:
    static const int PLATFORM_VEL = 400;   ///< Vitesse de déplacement de la plateforme.
    static const int PLATFORM_WIDTH = 100; ///< Largeur de la plateforme.
    static const int PLATFORM_HEIGHT = 20; ///< Hauteur de la plateforme.

    int screenWidth;  ///< Largeur de l'écran pour limiter le mouvement de la plateforme.
    int screenHeight; ///< Hauteur de l'écran pour le positionnement.
    int posX, posY;   ///< Position de la plateforme sur l'écran.
    int velX;         ///< Vitesse horizontale actuelle de la plateforme.

    bool smallPlatformMalus; ///< Indicateur indiquant si la plateforme est soumise à un malus de réduction de taille.
    float malusTimer;        ///< Minuterie pour suivre la durée du malus de petite plateforme.
};

#endif
