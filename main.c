#include "./types/colors.h"
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
  // should be contained in a state struct
  int running = 1;
  int linesAdded = 0;
  Line lines[10];
  Point currentStart;
  Point currentEnd;
  int pressed = 0;
  SDL_Event e;
  while (running) {
    while (SDL_PollEvent(&e)) {
      switch (e.type) {
      case SDL_QUIT:
        running = 0;
        break;
      case SDL_MOUSEBUTTONDOWN:
        currentStart = fromSDLMouseButtonEvent(e.button);
        pressed = 1;
        break;
      case SDL_MOUSEBUTTONUP:
        currentEnd = fromSDLMouseButtonEvent(e.button);
        int indexToInsert = linesAdded;
        while (indexToInsert > 9) {
          indexToInsert -= 10;
        }
        Line newLine;
        newLine.start = currentStart;
        newLine.end = currentEnd;
        lines[indexToInsert] = newLine;
        linesAdded++;
        pressed = 0;
        break;
      default: {
        if (pressed > 0) {
          currentEnd = fromSDLMouseButtonEvent(e.button);
          int indexToInsert = linesAdded;
          while (indexToInsert > 9) {
            indexToInsert -= 10;
          }
          Line newLine;
          newLine.start = currentStart;
          newLine.end = currentEnd;
          lines[indexToInsert] = newLine;
        }
      }
      }
    }
    SDL_SetRenderDrawColor(context->renderer, COLORS[BLACK].r, COLORS[BLACK].g,
                           COLORS[BLACK].b, COLORS[BLACK].a);
    SDL_RenderClear(context->renderer);
    SDL_SetRenderDrawColor(context->renderer, COLORS[WHITE].r, COLORS[WHITE].g,
                           COLORS[WHITE].b, COLORS[WHITE].a);
    for (int i = 0; i < (linesAdded + pressed) && i < 10; ++i) {
      SDL_RenderDrawLine(context->renderer, lines[i].start.x, lines[i].start.y,
                         lines[i].end.x, lines[i].end.y);
    }
    SDL_RenderPresent(context->renderer);
    SDL_Delay(8);
  }
  destroyContext(context);
  return 0;
}
