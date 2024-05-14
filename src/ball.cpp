#include "../includes/ball.hpp"
#include "../includes/utils.hpp"
#include <cstdlib>
#include <cmath>

/**
 * @brief Constructeur de la classe Ball.
 *
 * Initialise la balle à la position centrale de l'écran et avec une vitesse aléatoire.
 *
 * @param screen_width La largeur de l'écran.
 * @param screen_height La hauteur de l'écran.
 */
Ball::Ball(int screen_width, int screen_height)
    : screenWidth(screen_width), screenHeight(screen_height)
{
    reset();
}

/**
 * @brief Déplace la balle en fonction du temps écoulé.
 *
 * @param deltaTime Le temps écoulé depuis la dernière mise à jour.
 */
void Ball::move(float deltaTime)
{
    posX += velX * deltaTime;
    posY += velY * deltaTime;

    if (posX <= 0 || posX + BALL_SIZE >= screenWidth)
    {
        velX = -velX;
    }

    if (posY <= 0)
    {
        velY = -velY;
    }
}

/**
 * @brief Affiche la balle sur l'écran.
 *
 * @param renderer Le renderer SDL.
 */
void Ball::render(SDL_Renderer *renderer) const
{
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
    DrawCircle(renderer, static_cast<int>(posX + BALL_SIZE / 2), static_cast<int>(posY + BALL_SIZE / 2), BALL_SIZE / 2);
}

/**
 * @brief Réinitialise la position et la vitesse de la balle.
 */
void Ball::reset()
{
    posX = screenWidth / 2.0f - BALL_SIZE / 2.0f;
    posY = screenHeight / 2.0f - BALL_SIZE / 2.0f;
    velX = BALL_VEL * ((rand() % 2 == 0) ? 1 : -1);
    velY = -BALL_VEL;
}

/**
 * @brief Vérifie la collision avec la plateforme et ajuste la direction de la balle.
 *
 * @param platformRect Le rectangle représentant la plateforme.
 */
void Ball::checkCollisionWithPlatform(const SDL_Rect &platformRect)
{
    SDL_Rect ballRect = {static_cast<int>(posX), static_cast<int>(posY), BALL_SIZE, BALL_SIZE};
    if (checkCollision(ballRect, platformRect))
    {
        reflectOnPlatformCollision(platformRect);
    }
}

/**
 * @brief Réfléchit la balle en cas de collision avec la plateforme.
 *
 * @param platformRect Le rectangle représentant la plateforme.
 */
void Ball::reflectOnPlatformCollision(const SDL_Rect &platformRect)
{
    float relativeIntersectX = (posX + (BALL_SIZE / 2)) - (platformRect.x + (platformRect.w / 2));
    float normalizedRelativeIntersectionX = (relativeIntersectX / (platformRect.w / 2));
    float bounceAngle = normalizedRelativeIntersectionX * (M_PI / 4);

    velX = BALL_VEL * sin(bounceAngle);
    velY = -BALL_VEL * cos(bounceAngle);
}

/**
 * @brief Vérifie la collision avec les briques et ajuste la direction de la balle.
 *
 * @param bricks Un vecteur de briques.
 */
void Ball::checkCollisionWithBricks(std::vector<Brick> &bricks)
{
    SDL_Rect ballRect = {static_cast<int>(posX), static_cast<int>(posY), BALL_SIZE, BALL_SIZE};
    for (auto &brick : bricks)
    {
        if (!brick.isDestroyed() && checkCollision(ballRect, brick.getRect()))
        {
            if ((posX + BALL_SIZE - 1 < brick.getRect().x) || (posX + 1 > brick.getRect().x + brick.getRect().w))
            {
                velX = -velX;
            }
            else
            {
                velY = -velY;
            }
            brick.hit();
            break;
        }
    }
}

/**
 * @brief Retourne la position verticale de la balle.
 *
 * @return La position y de la balle.
 */
float Ball::getY() const
{
    return posY;
}
