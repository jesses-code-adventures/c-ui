#include "SDL2/SDL.h"
#include "SDL2/SDL_pixels.h"
#include "SDL2/SDL_render.h"
#include <stdio.h>

// Constant for red
const SDL_Color RED = {255, 0, 0, 255};

// Constant for yellow
const SDL_Color YELLOW = {255, 255, 0, 255};

// Constant for green
const SDL_Color GREEN = {0, 255, 0, 255};

// Constant for blue
const SDL_Color BLUE = {0, 0, 255, 255};

const SDL_Color BLACK = {0, 0, 0, 255};

const SDL_Color WHITE = {255, 255, 255, 255};

typedef struct {
  int x;
  int y;
} Point;

typedef struct {
  Point start;
  Point end;
} Line;

int main(int argc, char *argv[]) {
  // Initialize SDL2
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    printf("SDL_Init Error: %s\n", SDL_GetError());
    return 1;
  }

  // Create a window
  SDL_Window *window =
      SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, 680, 480, SDL_WINDOW_SHOWN);

  if (window == NULL) {
    printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
    SDL_Quit();
    return 1;
  }

  // Create a renderer
  SDL_Renderer *renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (renderer == NULL) {
    SDL_DestroyWindow(window);
    printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
    SDL_Quit();
    return 1;
  }

  SDL_SetRenderDrawColor(renderer, BLACK.r, BLACK.g, BLACK.b, BLACK.a);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);

  // Main loop flag
  int running = 1;

  int linesAdded = 0;
  Line lines[10];
  Point currentStart;
  Point currentEnd;

  // Event loop
  SDL_Event e;
  while (running) {
    while (SDL_PollEvent(&e)) {
      switch (e.type) {
      case SDL_QUIT:
        running = 0;
        break;
      case SDL_MOUSEBUTTONDOWN:
        currentStart.x = e.button.x;
        currentStart.y = e.button.y;
        break;
      case SDL_MOUSEBUTTONUP:
        currentEnd.x = e.button.x;
        currentEnd.y = e.button.y;
        int indexToInsert = linesAdded;
        while (indexToInsert > 9) {
          indexToInsert -= 10;
        }
        Line newLine;
        newLine.start = currentStart;
        newLine.end = currentEnd;
        lines[indexToInsert] = newLine;
        linesAdded++;
        break;
      default: {
      }
      }
    }
    SDL_SetRenderDrawColor(renderer, BLACK.r, BLACK.g, BLACK.b, BLACK.a);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, WHITE.r, WHITE.g, WHITE.b, WHITE.a);
    for (int i = 0; i < linesAdded && i < 10; ++i) {
      SDL_RenderDrawLine(renderer, lines[i].start.x, lines[i].start.y,
                         lines[i].end.x, lines[i].end.y);
    }
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
