#include "./palette.h"
#include "../types/colors.h"
#include <SDL2/SDL.h>

void renderPalette(SDL_Renderer *renderer) {
  SDL_Rect rect;
  rect.w = BOX_SIZE;
  rect.h = BOX_SIZE;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 4; ++j) {
      rect.x = j * BOX_SIZE;
      rect.y = i * BOX_SIZE;
      SDL_SetRenderDrawColor(renderer, COLORS[i * 4 + j].r, COLORS[i * 4 + j].g,
                             COLORS[i * 4 + j].b, COLORS[i * 4 + j].a);
      SDL_RenderFillRect(renderer, &rect);
    }
  }
}
