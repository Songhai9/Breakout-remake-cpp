#ifndef BRICK_HPP
#define BRICK_HPP

#include <SDL2/SDL.h>

/**
 * @brief Classe représentant une brique dans le jeu Casse Brique.
 */
class Brick
{
public:
    /**
     * @brief Constructeur de la classe Brick.
     *
     * @param x Position x de la brique.
     * @param y Position y de la brique.
     * @param width Largeur de la brique.
     * @param height Hauteur de la brique.
     * @param hitPoints Points de vie de la brique.
     */
    Brick(int x, int y, int width, int height, int hitPoints);

    /**
     * @brief Affiche la brique sur l'écran.
     *
     * @param renderer Le renderer SDL.
     */
    void render(SDL_Renderer *renderer) const;

    /**
     * @brief Affiche une brique hexagonale sur l'écran.
     *
     * @param renderer Le renderer SDL.
     */
    void renderHexagonal(SDL_Renderer *renderer) const;

    /**
     * @brief Affiche une brique triangulaire sur l'écran.
     *
     * @param renderer Le renderer SDL.
     */
    void renderTriangular(SDL_Renderer *renderer) const;

    /**
     * @brief Inflige un coup à la brique, réduisant ses points de vie.
     */
    void hit();

    /**
     * @brief Vérifie si la brique est détruite.
     *
     * @return True si la brique est détruite, false sinon.
     */
    bool isDestroyed() const;

    /**
     * @brief Vérifie si la brique a été touchée.
     *
     * @return True si la brique a été touchée, false sinon.
     */
    bool isHit() const;

    /**
     * @brief Vérifie si la brique vient juste d'être détruite.
     *
     * @return True si la brique vient juste d'être détruite, false sinon.
     */
    bool wasJustDestroyed();

    /**
     * @brief Réinitialise le drapeau de coup de la brique.
     */
    void resetHitFlag();

    /**
     * @brief Retourne le rectangle représentant la brique.
     *
     * @return Le rectangle SDL de la brique.
     */
    SDL_Rect getRect() const;

    /**
     * @brief Retourne la couleur de la brique en fonction de ses points de vie.
     *
     * @return La couleur SDL de la brique.
     */
    SDL_Color getColor() const;

private:
    /// Le rectangle représentant la position et la taille de la brique.
    SDL_Rect rect;

    /// Les points de vie de la brique.
    int hitPoints;

    /// Drapeau indiquant si la brique a été touchée.
    bool hitFlag;

    /// Drapeau indiquant si la brique a été détruite.
    bool destroyedFlag;
};

#endif
