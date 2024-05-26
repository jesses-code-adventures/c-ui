#ifndef DRAWING_STATE_H
#define DRAWING_STATE_H

#include "../types/line.h"
#include "../types/point.h"
#include <SDL2/SDL.h>

typedef struct {
  int running;
  int mousePressed;
  Line lines[10];
  int linesAdded;
  Point currentStart;
  Point currentEnd;
  SDL_Color *currentColor;
} DrawingState;

DrawingState *initializeDrawingState();
void destroyDrawingState(DrawingState *state);

#endif
