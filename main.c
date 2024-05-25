#include "SDL2/SDL.h"
#include <stdio.h>

int main(int argc, char* argv[]) {
    // Initialize SDL2
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create a window
    SDL_Window* window = SDL_CreateWindow("SDL2 Window",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        680, 480, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Create a renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        SDL_DestroyWindow(window);
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Set the draw color to red
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    // Main loop flag
    int running = 1;

    // Event loop
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }

        // Clear screen with red color
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);

        // Delay to control frame rate
        SDL_Delay(16); // Roughly 60 frames per second
    }

    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
