#ifndef BALL_HPP
#define BALL_HPP

#include <SDL2/SDL.h>
#include <vector>
#include "brick.hpp"

/**
 * @class Ball
 * @brief Représente la balle utilisée dans le jeu, gérant son mouvement et ses interactions.
 */
class Ball
{
public:
    /**
     * @brief Construit un nouvel objet Ball.
     *
     * @param screenWidth Largeur de l'écran pour limiter le mouvement de la balle.
     * @param screenHeight Hauteur de l'écran pour limiter le mouvement de la balle.
     */
    Ball(int screenWidth, int screenHeight);

    /**
     * @brief Déplace la balle en fonction du temps écoulé.
     *
     * @param deltaTime Temps écoulé depuis la dernière frame.
     */
    void move(float deltaTime);

    /**
     * @brief Affiche la balle à l'écran.
     *
     * @param renderer Renderer SDL pour dessiner la balle.
     */
    void render(SDL_Renderer *renderer) const;

    /**
     * @brief Vérifie et gère la collision avec la plateforme.
     *
     * @param platformRect SDL_Rect représentant la plateforme.
     */
    void checkCollisionWithPlatform(const SDL_Rect &platformRect);

    /**
     * @brief Vérifie et gère la collision avec les briques.
     *
     * @param bricks Vecteur de briques pour vérifier les collisions.
     */
    void checkCollisionWithBricks(std::vector<Brick> &bricks);

    /**
     * @brief Obtient la position Y de la balle.
     *
     * @return float Coordonnée Y de la balle.
     */
    float getY() const;

    /**
     * @brief Obtient le rayon de la balle.
     *
     * @return int Rayon de la balle.
     */
    int getRadius() const;

private:
    int screenWidth;
    int screenHeight;
    float x, y;
    float dx, dy;
    int radius;
    SDL_Rect rect;
};

#endif
