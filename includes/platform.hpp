#ifndef PLATFORM_HPP
#define PLATFORM_HPP

#include <SDL2/SDL.h>

/**
 * @brief Classe représentant la plateforme dans le jeu Casse Brique.
 */
class Platform
{
public:
    /**
     * @brief Constructeur de la classe Platform.
     *
     * @param screen_width La largeur de l'écran.
     * @param screen_height La hauteur de l'écran.
     */
    Platform(int screen_width, int screen_height);

    /**
     * @brief Gère les événements de clavier pour déplacer la plateforme.
     *
     * @param e L'événement SDL.
     */
    void handleEvent(const SDL_Event &e);

    /**
     * @brief Déplace la plateforme en fonction du temps écoulé.
     *
     * @param deltaTime Le temps écoulé depuis la dernière mise à jour.
     */
    void move(float deltaTime);

    /**
     * @brief Affiche la plateforme sur l'écran.
     *
     * @param renderer Le renderer SDL.
     */
    void render(SDL_Renderer *renderer) const;

    /**
     * @brief Retourne le rectangle représentant la plateforme.
     *
     * @return Le rectangle SDL de la plateforme.
     */
    SDL_Rect getRect() const;

    /**
     * @brief Applique le malus de petite plateforme.
     */
    void applySmallPlatformMalus();

    /**
     * @brief Met à jour l'état de la plateforme.
     *
     * @param deltaTime Le temps écoulé depuis la dernière mise à jour.
     */
    void update(float deltaTime);

private:
    /// La largeur de l'écran.
    int screenWidth;

    /// La hauteur de l'écran.
    int screenHeight;

    /// La position x de la plateforme.
    float posX;

    /// La position y de la plateforme.
    float posY;

    /// La vitesse x de la plateforme.
    float velX;

    /// Indicateur de malus de petite plateforme.
    bool smallPlatformMalus;

    /// Timer pour le malus de petite plateforme.
    float malusTimer;

    /// La largeur de la plateforme.
    static const int PLATFORM_WIDTH = 100;

    /// La hauteur de la plateforme.
    static const int PLATFORM_HEIGHT = 20;

    /// La vitesse de la plateforme.
    static const int PLATFORM_VEL = 400;
};

#endif
