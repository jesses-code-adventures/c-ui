#include "./point.h"

Point fromSDLMouseButtonEvent(SDL_MouseButtonEvent e) {
  Point p;
  p.x = e.x;
  p.y = e.y;
  return p;
}

