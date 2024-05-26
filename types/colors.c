#include "colors.h"
#include "SDL2/SDL_pixels.h"

// const SDL_Color RED_COLOR = {255, 0, 0, 255};
// const SDL_Color YELLOW_COLOR = {255, 255, 0, 255};
// const SDL_Color GREEN_COLOR = {0, 255, 0, 255};
// const SDL_Color BLUE_COLOR = {0, 0, 255, 255};
// const SDL_Color BLACK_COLOR = {0, 0, 0, 255};
// const SDL_Color WHITE_COLOR = {255, 255, 255, 255};

const SDL_Color COLORS[COLOR_COUNT] = {
    [RED] = {255, 0, 0, 255},   [YELLOW] = {255, 255, 0, 255},
    [GREEN] = {0, 255, 0, 255}, [BLUE] = {0, 0, 255, 255},
    [BLACK] = {0, 0, 0, 255},   [WHITE] = {255, 255, 255, 255},
};
