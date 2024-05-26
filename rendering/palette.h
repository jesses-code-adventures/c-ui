#ifndef PALETTE_H
#define PALETTE_H

#include "../types/point.h"
#include "SDL2/SDL.h"
#define BOX_SIZE 30

typedef struct {
  Point topLeft;
} Palette;

void renderPalette(SDL_Renderer *renderer);

#endif
