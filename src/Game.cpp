#include "../includes/Game.hpp"
#include <iostream>

// Constructor initializing the game state and creating necessary objects
Game::Game() : isRunning(false), window(nullptr), renderer(nullptr), lives(3), ballLost(false) {}

// Destructor to clean up resources
Game::~Game()
{
    clean();
}

// Initialize SDL, create the game window, renderer, and set up game objects
void Game::init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cerr << "Failed at SDL_Init() with error: " << SDL_GetError() << std::endl;
        return;
    }
    window = SDL_CreateWindow("Circular Brick Breaker", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    if (!window)
    {
        std::cerr << "Failed at creating window with error: " << SDL_GetError() << std::endl;
        return;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        std::cerr << "Failed at creating renderer with error: " << SDL_GetError() << std::endl;
        return;
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    paddle = std::make_unique<Paddle>(renderer, 800, 600);
    ball = std::make_unique<Ball>(renderer, 400, 290);
    grid = std::make_unique<Grid>(renderer, 400, 300);
    grid->setupGrid();
    isRunning = true;
    TTF_Init(); // Initialize the TTF engine for text rendering
}

// The main game loop handling events, updating game logic, and rendering
void Game::run()
{
    init();
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;

    while (isRunning)
    {
        frameStart = SDL_GetTicks();

        handleEvents();
        update();
        render();

        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
}

// Update game objects; check for collisions and game state changes
void Game::update()
{
    paddle->update();
    ball->update();

    SDL_Rect ballRect = ball->getRect();
    SDL_Rect brickRect;
    if (grid->checkCollision(ballRect, &brickRect))
    {
        ball->adjustOnCollisionWithBrick(brickRect);
        score += 10; // Increase score for hitting and destroying a brick
    }

    SDL_Rect paddleRect = paddle->getRect();
    if (SDL_HasIntersection(&ballRect, &paddleRect))
    {
        ball->adjustOnCollisionWithPaddle(paddleRect);
// Include Bonus.hpp at the top
#include "../includes/Bonus.hpp"

// Define a vector to hold active bonuses
std::vector<Bonus> bonuses;

// Modify the update method to check for bonus collection
void Game::update() {
    paddle->update();
    ball->update();

    // Existing collision handling...

    // Handle bonuses
    for (auto& bonus : bonuses) {
        bonus.update();
        if (SDL_HasIntersection(&paddle->getRect(), &bonus.rect)) {
            bonus.activate();
        }
    }
    bonuses.erase(std::remove_if(bonuses.begin(), bonuses.end(), [](const Bonus& b) { return !b.active; }), bonuses.end());
}

// Sample effect function for multi-ball bonus
void spawnExtraBall() {
    balls.push_back(std::make_unique<Ball>(renderer, ball->getRect().x, ball->getRect().y)); // Assuming a Ball constructor exists
}
    }

    if (ballRect.y + ballRect.h >= 600)
    {
        if (!ballLost)
        {
            lives--;
            score -= 5; // Decrease score for losing a ball
            ballLost = true;
        }
    }
    else
    {
        ballLost = false;
    }
}

// Handle user input and system events
void Game::handleEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            isRunning = false;
        }
        paddle->handleEvent(event);
    }
}

// Render all game components on the screen
void Game::render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    grid->render();
    paddle->render();
    ball->render();

    // Render lives and score text
    renderText("Lives: " + std::to_string(lives), 650, 580, {255, 255, 255, 255});
    renderText("Score: " + std::to_string(score), 50, 580, {255, 255, 255, 255});

    SDL_RenderPresent(renderer);
}

// Render text to the screen
void Game::renderText(const std::string &text, int x, int y, SDL_Color color)
{
    TTF_Font *font = TTF_OpenFont("assets/font.ttf", 12); // Specify your font path and size
    if (!font)
    {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
        return;
    }
    SDL_Surface *surface = TTF_RenderText_Solid(font, text.c_str(), color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect textRect = {x, y, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &textRect);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
}

void Game::clean()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
