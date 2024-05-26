#ifndef COLORS_H
#define COLORS_H

#include "SDL2/SDL_pixels.h"

enum Color {
    BLACK,
    WHITE,
    RED,
    YELLOW,
    GREEN,
    BLUE,
    MAGENTA,
    CYAN,
    COLOR_COUNT
};

extern const SDL_Color COLORS[COLOR_COUNT];

#endif
