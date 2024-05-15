#ifndef BONUS_HPP
#define BONUS_HPP

#include <SDL2/SDL.h>

/**
 * @class Bonus
 * @brief Représente un bonus qui peut être collecté pendant le jeu.
 */
class Bonus
{
public:
    /**
     * @enum Type
     * @brief Types de bonus qui peuvent affecter le gameplay.
     */
    enum Type
    {
        EXTRA_LIFE,    ///< Accorde une vie supplémentaire.
        MULTI_BALL,    ///< Ajoute des balles supplémentaires au jeu.
        SMALL_PLATFORM ///< Réduit temporairement la taille de la plateforme.
    };

    /**
     * @brief Construit un nouvel objet Bonus.
     *
     * @param x Position X du bonus.
     * @param y Position Y du bonus.
     * @param type Type du bonus.
     */
    Bonus(int x, int y, Type type);

    /**
     * @brief Déplace le bonus vers le bas.
     *
     * @param deltaTime Temps écoulé depuis la dernière frame.
     */
    void move(float deltaTime);

    /**
     * @brief Affiche le bonus à l'écran.
     *
     * @param renderer Renderer SDL pour dessiner le bonus.
     */
    void render(SDL_Renderer *renderer) const;

    /**
     * @brief Vérifie si le bonus est sorti de l'écran.
     *
     * @return true Si le bonus est sorti de l'écran.
     * @return false Sinon.
     */
    bool isOffScreen() const;

    /**
     * @brief Obtient le SDL_Rect représentant le bonus.
     *
     * @return SDL_Rect Rectangle du bonus.
     */
    SDL_Rect getRect() const;

    /**
     * @brief Obtient le type du bonus.
     *
     * @return Type Type du bonus.
     */
    Type getType() const;

    /**
     * @brief Obtient la taille du bonus.
     *
     * @return int Taille du bonus.
     */
    static int getSize();

private:
    SDL_Rect rect;
    Type type;
    static const int BONUS_SIZE = 20;
    static const int BONUS_VEL = 200;
};

#endif
