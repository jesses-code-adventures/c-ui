#include "drawing_state.h"
#include "../types/line.h"
#include "../types/point.h"

DrawingState *initializeDrawingState() {
  DrawingState *state = malloc(sizeof(DrawingState));
  state->mousePressed = 0;
  state->running = 1;
  state->linesAdded = 0;
  return state;
}

void freeDrawingState(DrawingState *state) { free(state); }
