#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <SDL2/SDL.h>

class Paddle {
public:
    Paddle(SDL_Renderer* renderer, int centerX, int centerY, int radius);
    void update();
    void render();
    void handleEvent(SDL_Event& event);
    void setAngle(float angleDelta);

private:
    SDL_Renderer* renderer;
    SDL_Rect rect;
    int centerX, centerY, radius;
    float angle; 

    void calculatePosition();
};

#endif
