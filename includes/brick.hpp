#ifndef BRICK_HPP
#define BRICK_HPP

#include <SDL2/SDL.h>

/**
 * @class Brick
 * @brief Représente une brique dans le jeu, gérant son rendu et son état.
 */
class Brick
{
public:
    /**
     * @brief Construit un nouvel objet Brick.
     *
     * @param x Position X de la brique.
     * @param y Position Y de la brique.
     * @param width Largeur de la brique.
     * @param height Hauteur de la brique.
     * @param hitPoints Nombre de coups que la brique peut encaisser avant d'être détruite.
     */
    Brick(int x, int y, int width, int height, int hitPoints);

    /**
     * @brief Affiche la brique à l'écran.
     *
     * @param renderer Renderer SDL pour dessiner la brique.
     */
    void render(SDL_Renderer *renderer) const;

    /**
     * @brief Affiche la brique avec une forme hexagonale.
     *
     * @param renderer Renderer SDL pour dessiner la brique.
     */
    void renderHexagonal(SDL_Renderer *renderer) const;

    /**
     * @brief Affiche la brique avec une forme triangulaire.
     *
     * @param renderer Renderer SDL pour dessiner la brique.
     */
    void renderTriangular(SDL_Renderer *renderer) const;

    /**
     * @brief Enregistre un coup sur la brique, réduisant ses points de vie et la marquant éventuellement comme détruite.
     */
    void hit();

    /**
     * @brief Vérifie si la brique est détruite.
     *
     * @return true Si la brique est détruite.
     * @return false Sinon.
     */
    bool isDestroyed() const;

    /**
     * @brief Vérifie si la brique a été touchée.
     *
     * @return true Si la brique a été touchée.
     * @return false Sinon.
     */
    bool isHit() const;

    /**
     * @brief Vérifie si la brique vient d'être détruite lors de la dernière mise à jour.
     *
     * @return true Si la brique vient d'être détruite.
     * @return false Sinon.
     */
    bool wasJustDestroyed();

    /**
     * @brief Réinitialise le drapeau de coup après avoir géré l'état de la brique touchée.
     */
    void resetHitFlag();

    /**
     * @brief Obtient le rectangle représentant la position et les dimensions de la brique.
     *
     * @return SDL_Rect Le rectangle de la brique.
     */
    SDL_Rect getRect() const;

private:
    SDL_Color getColor() const; ///< Fonction d'aide pour déterminer la couleur en fonction des points de vie.
    SDL_Rect rect;              ///< Rectangle SDL définissant la position et la taille de la brique.
    int hitPoints;              ///< Points de vie restants de la brique.
    bool hitFlag;               ///< Drapeau indiquant si la brique a été touchée lors de la frame actuelle.
    bool destroyedFlag;         ///< Drapeau indiquant si la brique est détruite.
};

#endif
