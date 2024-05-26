#ifndef POINT_H
#define POINT_H

#include <SDL2/SDL.h>

typedef struct {
  int x;
  int y;
  SDL_Color *color;
} Point;

Point fromSDLMouseButtonEvent(SDL_MouseButtonEvent e);

#endif
