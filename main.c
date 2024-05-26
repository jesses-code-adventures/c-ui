#include "./types/colors.h"
#include "./state/drawing_state.h"
#include "./types/line.h"
#include "./types/point.h"
#include "./state/sdl_context.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  SDLContext *context = initializeApp();
  if (context == NULL) {
    return 1;
  }
  DrawingState *state = initializeDrawingState();
  SDL_Event e;
  while (context->running) {
    while (SDL_PollEvent(&e)) {
      switch (e.type) {
      case SDL_QUIT:
        context->running = 0;
        break;
      case SDL_MOUSEBUTTONDOWN:
        state->currentStart = fromSDLMouseButtonEvent(e.button);
        state->mousePressed = 1;
        break;
      case SDL_MOUSEBUTTONUP:
        state->currentEnd = fromSDLMouseButtonEvent(e.button);
        int indexToInsert = state->linesAdded;
        while (indexToInsert > 9) {
          indexToInsert -= 10;
        }
        Line newLine;
        newLine.start = state->currentStart;
        newLine.end = state->currentEnd;
        state->lines[indexToInsert] = newLine;
        state->linesAdded++;
        state->mousePressed = 0;
        break;
      default: {
        if (state->mousePressed > 0) {
          state->currentEnd = fromSDLMouseButtonEvent(e.button);
          int indexToInsert = state->linesAdded;
          while (indexToInsert > 9) {
            indexToInsert -= 10;
          }
          Line newLine;
          newLine.start = state->currentStart;
          newLine.end = state->currentEnd;
          state->lines[indexToInsert] = newLine;
        }
      }
      }
    }
    SDL_SetRenderDrawColor(context->renderer, COLORS[BLACK].r, COLORS[BLACK].g,
                           COLORS[BLACK].b, COLORS[BLACK].a);
    SDL_RenderClear(context->renderer);
    SDL_SetRenderDrawColor(context->renderer, COLORS[CYAN].r, COLORS[CYAN].g,
                           COLORS[CYAN].b, COLORS[CYAN].a);
    for (int i = 0; i < (state->linesAdded + state->mousePressed) && i < 10; ++i) {
      SDL_RenderDrawLine(context->renderer, state->lines[i].start.x, state->lines[i].start.y,
                         state->lines[i].end.x, state->lines[i].end.y);
    }
    SDL_RenderPresent(context->renderer);
    SDL_Delay(8);
  }
  destroyContext(context);
  return 0;
}
