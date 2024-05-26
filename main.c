#include "./events/handler.h"
#include "./rendering/palette.h"
#include "./rendering/render.h"
#include "./state/drawing_state.h"
#include "./state/sdl_context.h"
#include "./types/colors.h"
#include "./types/line.h"
#include "./types/point.h"
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
      handleSDLEvent(e, context, state);
    }
    renderRefresh(context, state);
  }
  destroyContext(context);
  return 0;
}
