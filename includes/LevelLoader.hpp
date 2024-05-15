#ifndef LEVELLOADER_HPP
#define LEVELLOADER_HPP

#include <vector>
#include <string>
#include "brick.hpp"

/**
 * @class LevelLoader
 * @brief Responsable du chargement des niveaux de jeu à partir de fichiers.
 *
 * La classe LevelLoader gère la création des niveaux en lisant les configurations de disposition à partir de fichiers et en créant les briques en conséquence.
 */
class LevelLoader
{
public:
    enum GridShape
    {
        RECTANGULAR, ///< Briques de forme rectangulaire.
        HEXAGONAL,   ///< Briques de forme hexagonale.
        TRIANGULAR   ///< Briques de forme triangulaire.
    };

    /**
     * @brief Charge un niveau à partir d'un fichier.
     *
     * @param filePath Chemin vers le fichier de configuration du niveau.
     * @param shape Forme des briques dans le niveau.
     * @param screenWidth Largeur de l'écran de jeu pour mettre à l'échelle la position des briques.
     * @param screenHeight Hauteur de l'écran de jeu pour mettre à l'échelle la position des briques.
     * @param brickWidth Largeur de chaque brique.
     * @param brickHeight Hauteur de chaque brique.
     * @param spacing Espace entre les briques.
     * @return std::vector<Brick> Vecteur contenant toutes les briques du niveau.
     */
    static std::vector<Brick> loadLevel(const std::string &filePath, GridShape shape, int screenWidth, int screenHeight, int brickWidth, int brickHeight, int spacing);
};

#endif
