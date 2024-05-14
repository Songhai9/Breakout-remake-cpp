#ifndef LEVEL_LOADER_HPP
#define LEVEL_LOADER_HPP

#include <vector>
#include <string>
#include "brick.hpp"

/**
 * @brief Classe pour charger les niveaux du jeu depuis des fichiers.
 */
class LevelLoader
{
public:
    /**
     * @brief Formes de grille disponibles pour les niveaux.
     */
    enum GridShape
    {
        RECTANGULAR,
        HEXAGONAL,
        TRIANGULAR
    };

    /**
     * @brief Charge un niveau depuis un fichier et crée les briques correspondantes.
     *
     * @param filePath Le chemin vers le fichier de niveau.
     * @param shape La forme de la grille de briques.
     * @param screenWidth La largeur de l'écran.
     * @param screenHeight La hauteur de l'écran.
     * @param brickWidth La largeur des briques.
     * @param brickHeight La hauteur des briques.
     * @param spacing L'espacement entre les briques.
     * @return Un vecteur de briques.
     */
    static std::vector<Brick> loadLevel(const std::string &filePath, GridShape shape, int screenWidth, int screenHeight, int brickWidth, int brickHeight, int spacing);
};

#endif
