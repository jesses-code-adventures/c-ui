#include "./sdl_context.h"
#include "../types/colors.h"
#include <stdio.h>
#include <stdlib.h>

SDLContext *initializeApp() {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    printf("SDL_Init Error: %s\n", SDL_GetError());
    return NULL;
  }
  SDL_Window *window =
      SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, 680, 480, SDL_WINDOW_SHOWN);
  if (window == NULL) {
    printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
    SDL_Quit();
    return NULL;
  }
  SDL_Renderer *renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (renderer == NULL) {
    SDL_DestroyWindow(window);
    printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
    SDL_Quit();
    return NULL;
  }
  SDL_SetRenderDrawColor(renderer, COLORS[BLACK].r, COLORS[BLACK].g,
                         COLORS[BLACK].b, COLORS[BLACK].a);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);

  SDLContext *context = (SDLContext *)malloc(sizeof(SDLContext));
  context->window = window;
  context->renderer = renderer;
  context->running = 1;
  return context;
}

void destroyContext(SDLContext *context) {
  if (context == NULL) {
    return;
  }
  if (context->renderer) {
    SDL_DestroyRenderer(context->renderer);
  }
  if (context->window) {
    SDL_DestroyWindow(context->window);
  }
  context->running = 0;
  free(context);
  SDL_Quit();
}
