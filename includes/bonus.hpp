#ifndef BONUS_HPP
#define BONUS_HPP

#include <SDL2/SDL.h>

/**
 * @brief Classe représentant un bonus dans le jeu Casse Brique.
 */
class Bonus
{
public:
    /**
     * @brief Types de bonus disponibles.
     */
    enum Type
    {
        EXTRA_LIFE,
        MULTI_BALL,
        SMALL_PLATFORM
    };

    /**
     * @brief Constructeur de la classe Bonus.
     *
     * @param x Position x du bonus.
     * @param y Position y du bonus.
     * @param type Type du bonus.
     */
    Bonus(int x, int y, Type type);

    /**
     * @brief Déplace le bonus en fonction du temps écoulé.
     *
     * @param deltaTime Le temps écoulé depuis la dernière mise à jour.
     */
    void move(float deltaTime);

    /**
     * @brief Affiche le bonus sur l'écran.
     *
     * @param renderer Le renderer SDL.
     */
    void render(SDL_Renderer *renderer) const;

    /**
     * @brief Vérifie si le bonus est hors de l'écran.
     *
     * @return True si le bonus est hors de l'écran, false sinon.
     */
    bool isOffScreen() const;

    /**
     * @brief Retourne le rectangle représentant le bonus.
     *
     * @return Le rectangle SDL du bonus.
     */
    SDL_Rect getRect() const;

    /**
     * @brief Retourne le type du bonus.
     *
     * @return Le type du bonus.
     */
    Type getType() const;

    /**
     * @brief Retourne la taille du bonus.
     *
     * @return La taille du bonus.
     */
    static int getSize();

    /// La taille du bonus.
    static const int BONUS_SIZE = 20;

    /// La vitesse du bonus.
    static const int BONUS_VEL = 100;

private:
    /// Le rectangle représentant la position et la taille du bonus.
    SDL_Rect rect;

    /// Le type du bonus.
    Type type;
};

#endif
