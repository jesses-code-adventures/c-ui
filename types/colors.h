#ifndef COLORS_H
#define COLORS_H

#include "SDL2/SDL_pixels.h"

extern const SDL_Color RED_COLOR;
extern const SDL_Color YELLOW_COLOR;
extern const SDL_Color GREEN_COLOR;
extern const SDL_Color BLUE_COLOR;
extern const SDL_Color BLACK_COLOR;
extern const SDL_Color WHITE_COLOR;

enum Color {
    RED,
    YELLOW,
    GREEN,
    BLUE,
    BLACK,
    WHITE,
    COLOR_COUNT
};

extern const SDL_Color COLORS[COLOR_COUNT];

#endif
