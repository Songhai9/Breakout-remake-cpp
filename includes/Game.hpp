#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>
#include <memory>
#include "Paddle.hpp"
#include "Ball.hpp"
#include "Grid.hpp"

class Game {
public:
    Game();
    ~Game();
    void run();

private:
    bool isRunning;
    SDL_Window* window;
    SDL_Renderer* renderer;
    std::unique_ptr<Paddle> paddle;
    std::unique_ptr<Ball> ball;
    std::unique_ptr<Grid> grid;

    void init();
    void update();
    void handleEvents();
    void render();
    void clean();
};

#endif
