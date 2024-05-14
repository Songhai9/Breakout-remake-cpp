#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "../includes/LevelLoader.hpp"
#include "../includes/ball.hpp"
#include "../includes/platform.hpp"
#include "../includes/brick.hpp"
#include "../includes/bonus.hpp"
#include "../includes/utils.hpp"

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 800;
const int FPS = 60;
const int FRAME_DELAY = 1000 / FPS;

const int SPACING = 10;
const int BRICK_WIDTH = (SCREEN_WIDTH - (10 + 1) * SPACING) / 10;
const int BRICK_HEIGHT = 20;

enum GameState
{
    RUNNING,
    WON,
    LOST
};

enum BrickShape
{
    RECTANGULAR,
    TRIANGULAR,
    HEXAGONAL
};

bool initSDL(SDL_Window *&window, SDL_Renderer *&renderer, TTF_Font *&font)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }
    if (TTF_Init() == -1)
    {
        std::cerr << "TTF_Init: " << TTF_GetError() << std::endl;
        return false;
    }
    window = SDL_CreateWindow("Casse Brique", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr)
    {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr)
    {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }
    font = TTF_OpenFont("assets/font.ttf", 16);
    if (font == nullptr)
    {
        std::cerr << "Failed to load font! TTF_Error: " << TTF_GetError() << std::endl;
        return false;
    }
    return true;
}

void closeSDL(SDL_Window *window, SDL_Renderer *renderer, TTF_Font *font)
{
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
}

void renderText(SDL_Renderer *renderer, TTF_Font *font, const std::string &text, int x, int y)
{
    SDL_Color textColor = {0, 0, 0, 255};
    SDL_Surface *textSurface = TTF_RenderText_Solid(font, text.c_str(), textColor);
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    int textWidth = textSurface->w;
    int textHeight = textSurface->h;
    SDL_FreeSurface(textSurface);

    SDL_Rect renderQuad = {x, y, textWidth, textHeight};
    SDL_RenderCopy(renderer, textTexture, nullptr, &renderQuad);
    SDL_DestroyTexture(textTexture);
}

std::pair<std::string, BrickShape> chooseLevel(SDL_Renderer *renderer, TTF_Font *font)
{
    bool quit = false;
    SDL_Event e;
    std::vector<std::string> levels = {"levels/level1.txt", "levels/level2.txt", "levels/level3.txt", "levels/level5.txt"};
    BrickShape brickShape = RECTANGULAR;
    int lineSpacing = 50;

    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
                return {"", RECTANGULAR};
            }
            else if (e.type == SDL_KEYDOWN)
            {
                switch (e.key.keysym.sym)
                {
                case SDLK_1:
                    brickShape = RECTANGULAR;
                    return {levels[0], brickShape};
                case SDLK_2:
                    brickShape = RECTANGULAR;
                    return {levels[1], brickShape};
                case SDLK_3:
                    brickShape = RECTANGULAR;
                    return {levels[2], brickShape};
                case SDLK_4:
                    brickShape = TRIANGULAR;
                    return {levels[0], brickShape};
                case SDLK_5:
                    brickShape = HEXAGONAL;
                    return {levels[3], brickShape};
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);

        renderText(renderer, font, "Select Level and Brick Shape:", 200, 150);
        renderText(renderer, font, "1. Level 1  Rectangular Bricks", 200, 200);
        renderText(renderer, font, "2. Level 2  Rectangular Bricks", 200, 200 + lineSpacing);
        renderText(renderer, font, "3. Level 3  Rectangular Bricks", 200, 200 + 2 * lineSpacing);
        renderText(renderer, font, "4. Level 4  Triangular Bricks", 200, 200 + 3 * lineSpacing);
        renderText(renderer, font, "5. Level 5  Hexagonal Bricks", 200, 200 + 4 * lineSpacing);

        SDL_RenderPresent(renderer);
    }

    return {"", RECTANGULAR};
}

void createAdditionalBalls(std::vector<Ball> &balls, int screen_width, int screen_height)
{
    while (balls.size() < 3)
    {
        balls.emplace_back(screen_width, screen_height);
    }
}

GameState runGame(SDL_Renderer *renderer, TTF_Font *font, std::vector<Brick> &bricks, BrickShape brickShape)
{
    Platform platform(SCREEN_WIDTH, SCREEN_HEIGHT);
    std::vector<Ball> balls = {Ball(SCREEN_WIDTH, SCREEN_HEIGHT)};

    int lives = 3;
    int score = 0;

    std::vector<Bonus> bonuses;

    bool quit = false;
    SDL_Event e;
    Uint32 startTime, frameTime;
    float deltaTime;

    while (!quit)
    {
        startTime = SDL_GetTicks();

        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
                return LOST;
            }
            platform.handleEvent(e);
        }

        deltaTime = FRAME_DELAY / 1000.0f;

        platform.move(deltaTime);
        platform.update(deltaTime);

        for (auto &ball : balls)
        {
            ball.move(deltaTime);
        }

        for (auto it = balls.begin(); it != balls.end();)
        {
            if (it->getY() + Ball::BALL_SIZE >= SCREEN_HEIGHT)
            {
                it = balls.erase(it);
            }
            else
            {
                ++it;
            }
        }

        if (balls.empty())
        {
            lives--;
            score -= 50;
            balls.emplace_back(SCREEN_WIDTH, SCREEN_HEIGHT);
        }

        if (lives <= 0)
        {
            return LOST;
        }

        // Check for collisions
        for (auto &ball : balls)
        {
            ball.checkCollisionWithPlatform(platform.getRect());
            ball.checkCollisionWithBricks(bricks);
        }

        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);

        platform.render(renderer);
        for (const auto &ball : balls)
        {
            ball.render(renderer);
        }

        bool allBricksDestroyed = true;
        for (auto &brick : bricks)
        {
            if (!brick.isDestroyed())
            {
                allBricksDestroyed = false;
                if (brick.isHit())
                {
                    score += 10;
                    brick.resetHitFlag();
                }
                switch (brickShape)
                {
                case RECTANGULAR:
                    brick.render(renderer);
                    break;
                case TRIANGULAR:
                    brick.renderTriangular(renderer);
                    break;
                case HEXAGONAL:
                    brick.renderHexagonal(renderer);
                    break;
                }
            }
            else if (brick.wasJustDestroyed())
            {
                score += 150;
                int randNum = std::rand() % 100;
                if (randNum < 5)
                {
                    int bonusX = brick.getRect().x + brick.getRect().w / 2 - Bonus::getSize() / 2;
                    int bonusY = brick.getRect().y + brick.getRect().h;
                    bonuses.emplace_back(bonusX, bonusY, Bonus::EXTRA_LIFE);
                }
                else if (randNum < 10)
                {
                    int bonusX = brick.getRect().x + brick.getRect().w / 2 - Bonus::getSize() / 2;
                    int bonusY = brick.getRect().y + brick.getRect().h;
                    bonuses.emplace_back(bonusX, bonusY, Bonus::MULTI_BALL);
                }
                else if (randNum < 15)
                {
                    int bonusX = brick.getRect().x + brick.getRect().w / 2 - Bonus::getSize() / 2;
                    int bonusY = brick.getRect().y + brick.getRect().h;
                    bonuses.emplace_back(bonusX, bonusY, Bonus::SMALL_PLATFORM);
                }
            }
        }

        if (allBricksDestroyed)
        {
            return WON;
        }

        for (auto it = bonuses.begin(); it != bonuses.end();)
        {
            it->move(deltaTime);
            if (it->isOffScreen())
            {
                it = bonuses.erase(it);
            }
            else
            {
                SDL_Rect bonusRect = it->getRect();
                SDL_Rect platformRect = platform.getRect();
                if (SDL_HasIntersection(&bonusRect, &platformRect))
                {
                    if (it->getType() == Bonus::EXTRA_LIFE)
                    {
                        lives++;
                    }
                    else if (it->getType() == Bonus::MULTI_BALL)
                    {
                        createAdditionalBalls(balls, SCREEN_WIDTH, SCREEN_HEIGHT);
                    }
                    else if (it->getType() == Bonus::SMALL_PLATFORM)
                    {
                        platform.applySmallPlatformMalus();
                    }
                    it = bonuses.erase(it);
                }
                else
                {
                    it->render(renderer);
                    ++it;
                }
            }
        }

        std::string livesText = "Lives: " + std::to_string(lives);
        int livesTextWidth = 0, livesTextHeight = 0;
        TTF_SizeText(font, livesText.c_str(), &livesTextWidth, &livesTextHeight);
        renderText(renderer, font, livesText, SCREEN_WIDTH - livesTextWidth - 10, SCREEN_HEIGHT - livesTextHeight - 10);

        std::string scoreText = "Score: " + std::to_string(score);
        int scoreTextWidth = 0, scoreTextHeight = 0;
        TTF_SizeText(font, scoreText.c_str(), &scoreTextWidth, &scoreTextHeight);
        renderText(renderer, font, scoreText, 10, SCREEN_HEIGHT - scoreTextHeight - 10);

        SDL_RenderPresent(renderer);

        frameTime = SDL_GetTicks() - startTime;
        if (frameTime < FRAME_DELAY)
        {
            SDL_Delay(FRAME_DELAY - frameTime);
        }
    }

    return LOST;
}

void renderEndGame(SDL_Renderer *renderer, TTF_Font *font, GameState gameState, int score)
{
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);

    std::string endText = (gameState == WON) ? "You Won!" : "Game Over!";
    renderText(renderer, font, endText, 350, 200);
    renderText(renderer, font, "Score: " + std::to_string(score), 350, 250);
    renderText(renderer, font, "Press Enter to play again", 300, 300);

    SDL_RenderPresent(renderer);
}

int main(int argc, char *args[])
{
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    TTF_Font *font = nullptr;

    if (!initSDL(window, renderer, font))
    {
        std::cerr << "Failed to initialize SDL!" << std::endl;
        return -1;
    }

    bool quit = false;
    while (!quit)
    {
        auto [chosenLevel, brickShape] = chooseLevel(renderer, font);
        if (chosenLevel.empty())
        {
            quit = true;
            continue;
        }

        std::vector<Brick> bricks = LevelLoader::loadLevel(chosenLevel, LevelLoader::RECTANGULAR, SCREEN_WIDTH, SCREEN_HEIGHT, BRICK_WIDTH, BRICK_HEIGHT, SPACING);
        GameState gameState = runGame(renderer, font, bricks, brickShape);
        renderEndGame(renderer, font, gameState, 0);

        SDL_Event e;
        bool waitForEnter = true;
        while (waitForEnter)
        {
            while (SDL_PollEvent(&e) != 0)
            {
                if (e.type == SDL_QUIT)
                {
                    quit = true;
                    waitForEnter = false;
                }
                else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN)
                {
                    waitForEnter = false;
                }
            }
        }
    }

    closeSDL(window, renderer, font);
    return 0;
}
