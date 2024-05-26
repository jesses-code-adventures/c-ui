#ifndef DRAWING_STATE_H
#define DRAWING_STATE_H

#include "../types/line.h"
#include "../types/point.h"

typedef struct {
  int running;
  int mousePressed;
  Line lines[10];
  int linesAdded;
  Point currentStart;
  Point currentEnd;
} DrawingState;

DrawingState *initializeDrawingState();
void destroyDrawingState(DrawingState *state);

#endif
