#include "render.h"
#include "../types/colors.h"
#include "./color_selector.h"

void renderRefresh(SDLContext *context, DrawingState *state) {
  SDL_SetRenderDrawColor(context->renderer, COLORS[BLACK].r, COLORS[BLACK].g,
                         COLORS[BLACK].b, COLORS[BLACK].a);
  SDL_RenderClear(context->renderer);
  SDL_SetRenderDrawColor(context->renderer, COLORS[CYAN].r, COLORS[CYAN].g,
                         COLORS[CYAN].b, COLORS[CYAN].a);
  for (int i = 0; i < (state->linesAdded + state->mousePressed) && i < 10;
       ++i) {
    SDL_RenderDrawLine(context->renderer, state->lines[i].start.x,
                       state->lines[i].start.y, state->lines[i].end.x,
                       state->lines[i].end.y);
  }
  renderColorSelectorGrid(context->renderer);
  SDL_RenderPresent(context->renderer);
  SDL_Delay(16); // match roughly 60fps
}
