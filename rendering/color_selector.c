#ifndef COLOR_SELECTOR_H
#define COLOR_SELECTOR_H

#include <SDL2/SDL.h>
#include "./color_selector.h"
#include "../types/colors.h"

void renderColorSelectorGrid(SDL_Renderer *renderer) {
  SDL_Rect rect;
  rect.w = BOX_SIZE;
  rect.h = BOX_SIZE;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      rect.x = i * BOX_SIZE;
      rect.y = j * BOX_SIZE;
      SDL_SetRenderDrawColor(renderer, COLORS[i * 4 + j].r, COLORS[i * 4 + j].g,
                              COLORS[i * 4 + j].b, COLORS[i * 4 + j].a);
      SDL_RenderFillRect(renderer, &rect);
    }
  }
}

#endif
