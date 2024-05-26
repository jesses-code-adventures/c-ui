#include "colors.h"
#include "SDL2/SDL_pixels.h"

const SDL_Color COLORS[COLOR_COUNT] = {
    [BLACK] = {0, 0, 0, 255},   [WHITE] = {255, 255, 255, 255},
    [RED] = {255, 0, 0, 255},   [YELLOW] = {255, 255, 0, 255},
    [GREEN] = {0, 255, 0, 255}, [BLUE] = {0, 0, 255, 255},
    [MAGENTA] = {255, 0, 255, 255}, [CYAN] = {0, 255, 255, 255},
};
