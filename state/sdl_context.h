#ifndef SDL_CONTEXT_H
#define SDL_CONTEXT_H

#include "SDL2/SDL.h"

typedef struct {
  SDL_Window *window;
  SDL_Renderer *renderer;
  int running;
} SDLContext;

SDLContext *initializeApp();
void destroyContext(SDLContext *context);

#endif
