#include "../state/drawing_state.h"
#include "../state/sdl_context.h"
#include "SDL2/SDL_events.h"

void handleSDLEvent(SDL_Event e, SDLContext *context, DrawingState *state) {
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
