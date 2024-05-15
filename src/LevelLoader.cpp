#include "../includes/LevelLoader.hpp"
#include <fstream>
#include <iostream>
#include <cmath>

/**
 * @brief Charge un niveau à partir d'un fichier et retourne un vecteur de briques.
 * 
 * @param filePath Le chemin du fichier contenant le niveau.
 * @param shape La forme de la grille.
 * @param screenWidth La largeur de l'écran.
 * @param screenHeight La hauteur de l'écran.
 * @param brickWidth La largeur d'une brique.
 * @param brickHeight La hauteur d'une brique.
 * @param spacing L'espacement entre les briques.
 * @return Un vecteur de briques représentant le niveau chargé.
 */
std::vector<Brick> LevelLoader::loadLevel(const std::string &filePath, GridShape shape, int screenWidth, int screenHeight, int brickWidth, int brickHeight, int spacing)
{
    std::vector<Brick> bricks;
    std::ifstream file(filePath);
    if (!file.is_open())
    {
        std::cerr << "Failed to open level file: " << filePath << std::endl;
        return bricks;
    }

    std::string line;
    int y = spacing; 
    int row = 0;
    while (std::getline(file, line))
    {
        int x = spacing; 
        for (char c : line)
        {
            int hitPoints = 0;
            if (c == 'X')
            {
                hitPoints = 1;
            }
            else if (c == 'Y')
            {
                hitPoints = 2;
            }
            else if (c == 'Z')
            {
                hitPoints = 3;
            }
            if (hitPoints > 0)
            {
                if (shape == RECTANGULAR)
                {
                    bricks.emplace_back(x, y, brickWidth, brickHeight, hitPoints);
                }
                else if (shape == HEXAGONAL)
                {
                    int offsetX = (row % 2 == 0) ? 0 : (brickWidth / 2 + spacing / 2);
                    bricks.emplace_back(x + offsetX, y, brickWidth, brickHeight, hitPoints);
                }
                else if (shape == TRIANGULAR)
                {
                    bricks.emplace_back(x + (row * (brickWidth + spacing) / 2), y, brickWidth, brickHeight, hitPoints);
                }
            }
            x += brickWidth + spacing;
        }
        y += brickHeight + spacing;
        row++;
    }

    file.close();
    return bricks;
}
