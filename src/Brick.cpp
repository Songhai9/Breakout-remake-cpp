#include "../includes/Brick.hpp"

Brick::Brick(SDL_Renderer *renderer, int x, int y, int w, int h, int hitsRequired)
    : renderer(renderer), rect{x, y, w, h}, hitsLeft(hitsRequired), destroyed(false)
{
    setColor(); // Initialize the color based on hits required
}

void Brick::setColor()
{
    switch (hitsLeft)
    {
    case 3:
        color = {255, 0, 0, 255}; // Red
        break;
    case 2:
#include <cstdlib> // For rand() and srand()
#include <ctime> // For time()

// In the Brick constructor
srand(time(NULL)); // Initialize random seed

// Modify checkCollision method
bool Brick::checkCollision(const SDL_Rect &ballRect) {
    if (!destroyed && SDL_HasIntersection(&ballRect, &rect)) {
        hitsLeft--;
        if (hitsLeft <= 0) {
            destroyed = true;
            // 10% chance to spawn a bonus
            if (rand() % 10 == 0) {
                spawnBonus(rect.x, rect.y); // Function to spawn a bonus
            }
        } else {
            setColor();
        }
        return true;
    }
    return false;
}

    return false; // Return false if no collision occurs
}

const SDL_Rect &Brick::getRect() const
{
    return rect;
}

bool Brick::isDestroyed() const
{
    return destroyed;
}
