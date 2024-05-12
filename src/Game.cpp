#include "../includes/Game.hpp"
#include <iostream>

Game::Game() : isRunning(false), window(nullptr), renderer(nullptr) {}

Game::~Game() {
    clean();
}

void Game::init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cerr << "Failed at SDL_Init() with error: " << SDL_GetError() << std::endl;
        return;
    }
    window = SDL_CreateWindow("Circular Brick Breaker", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    if (!window) {
        std::cerr << "Failed at creating window with error: " << SDL_GetError() << std::endl;
        return;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Failed at creating renderer with error: " << SDL_GetError() << std::endl;
        return;
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black background
    paddle = std::make_unique<Paddle>(renderer, 800, 600);
    ball = std::make_unique<Ball>(renderer, 400, 290);
    grid = std::make_unique<Grid>(renderer, 400, 300);
    grid->setupGrid();
    isRunning = true;
}

void Game::run() {
    init();
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;

    while (isRunning) {
        frameStart = SDL_GetTicks();
        
        handleEvents();
        update();
        render();

        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }
}

void Game::update() {
    paddle->update();
    ball->update();

    // Check for collision with the grid (bricks)
    if (grid->checkCollision(ball->getRect())) {
        ball->reverseY();
    }

    // Collision detection between the ball and the paddle
    SDL_Rect ballRect = ball->getRect();
    SDL_Rect paddleRect = paddle->getRect();
    if (SDL_HasIntersection(&ballRect, &paddleRect)) {
        ball->reverseY();  // Reverse the vertical velocity of the ball

        // Advanced: Adjust angle based on where it hits the paddle
        int paddleCenter = paddleRect.x + paddleRect.w / 2;
        int ballCenter = ballRect.x + ballRect.w / 2;
        int distanceFromCenter = ballCenter - paddleCenter;

        // Change the horizontal velocity based on where the ball hits the paddle
        ball->setVelocityX(distanceFromCenter / 10); // Adjust this factor based on your game's design
    }
}


void Game::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }
        paddle->handleEvent(event);
    }
}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    grid->render();
    paddle->render();
    ball->render();
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
